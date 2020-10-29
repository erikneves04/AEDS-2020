/**
* @file   funcoes.h
* @brief  Arquivo com as funçoes de buscas em largura em grafos.
* @author <Erik Neves>
* @date   2020-10-29
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoes.h"

#define branco  (01)
#define cinza   (02)
#define preto   (03)

// FUNÇÕES DE MANIPULAÇÃO DA FILA - INICIO
static Error Inicializar_lista(Lista_arestras * lista){

    lista->NumeroDeArestras = 0;
    lista->primeira = NULL;
    lista->ultima = NULL;

    return Sucesso;
}
static Error Insere_dado(Vertice * vertice,Lista_arestras * lista){
    /* INSERE NO FINAL DA LISTA */
    Arestra * NovaArestra = (Arestra*)malloc(sizeof(Arestra));

    if(lista->NumeroDeArestras == 0){
        NovaArestra->proximo = NULL;
        NovaArestra->anterior = NULL;
        lista->primeira = NovaArestra;
        lista->ultima = NovaArestra;
    }else{
        NovaArestra->proximo = lista->ultima;
        NovaArestra->anterior = NULL;
        lista->ultima->anterior = NovaArestra;
        lista->ultima = NovaArestra;
    }   

    NovaArestra->vertice = vertice;
    lista->NumeroDeArestras++; 

    return Sucesso;
}
static Vertice * Remove_dado(Lista_arestras * lista){
    Vertice * Aux = lista->primeira->vertice;
    Arestra * segunda = lista->primeira->anterior;

    if(lista->NumeroDeArestras == 0)return NULL;

    free(lista->primeira);
    lista->NumeroDeArestras--;
    lista->primeira = segunda;

    return Aux;
}
static Boolean Lista_vazia(Lista_arestras * lista){
    if(lista->NumeroDeArestras == 0 || lista->primeira == NULL || lista->ultima == NULL){
        return true;
    }else{
        return false;
    }
}
static Error Imprimir_lista(Lista_arestras * lista){
    int i,j;
    char LinhaImpressao[(21 + sizeof(DataType))];
    Arestra * Dadoslista = lista->primeira;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da fila: \n");
        printf("Indi.       IDVertice.\n");
        for(i=0,j=1;i<(lista->NumeroDeArestras);i++,j++){ 
            Dadoslista->vertice->ID;
            (void)printf(" %.2d        %.2d\n",j,Dadoslista->vertice->ID);
            Dadoslista = Dadoslista->anterior; 
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
static Error Limpar_lista(Lista_arestras * lista){
    Arestra * Dadoslista = lista->primeira;
    Arestra * ProximoAux = NULL;
    int i; 

    if(Lista_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDeArestras;i++){
        ProximoAux = Dadoslista->anterior;
        free(Dadoslista);
        Dadoslista = ProximoAux;
    }
    Inicializar_lista(lista);
    return Sucesso;
}
// FUNÇÕES DE MANIPULAÇÃO DA FILA - FIM

// FUNÇÕES DE BUSCA EM GRAFOS(POR LARGURA) - INICIO
Vertice * BuscaVertice_Largura(Grafo * grafo,DataType DadoProcurado){
    int i;
    Boolean BuscaEncerrada = false;
    Boolean DadoEncontrado = false;
    Lista_arestras * FilaDeVertices = (Lista_arestras*)malloc(sizeof(Lista_arestras));
    Arestra * ArestraAux;
    Vertice * VerticeAtual = grafo->primeiro;

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(VerticeAtual->proximo != NULL)VerticeAtual = VerticeAtual->proximo;
    }
    
    Inicializar_lista(FilaDeVertices);
    while(BuscaEncerrada == false && DadoEncontrado == false){    
        ArestraAux = VerticeAtual->arestras->primeira;
        VerticeAtual->auxiliar = cinza;
        for(i=0;i<VerticeAtual->arestras->NumeroDeArestras;i++){
            if(VerticeAtual->auxiliar == preto) break;
            Insere_dado(ArestraAux->vertice,FilaDeVertices);
            ArestraAux = ArestraAux->proximo;
        }
        VerticeAtual->auxiliar = preto;
        if(VerticeAtual->VerticeValor == DadoProcurado){
            Limpar_lista(FilaDeVertices);
            DadoEncontrado = true;
            return VerticeAtual;
        }
        if(Lista_vazia(FilaDeVertices) == true){
            BuscaEncerrada = true;
            return NULL;
        }
        VerticeAtual = Remove_dado(FilaDeVertices);
    }
    
    return Sucesso;
}
// FUNÇÕES DE BUSCA EM GRAFOS(POR LARGURA) - FIM