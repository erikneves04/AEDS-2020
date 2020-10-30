/**
* @file   funcoes.h* @brief  Arquivo com as funçoes de buscas em grafos.
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
static Error Inicializar_Fila(Lista_arestras * lista){

    lista->NumeroDeArestras = 0;
    lista->primeira = NULL;
    lista->ultima = NULL;

    return Sucesso;
}
static Error Insere_dadoFila(Vertice * vertice,Lista_arestras * lista){
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
static Vertice * Remove_dadoFila(Lista_arestras * lista){
    Vertice * Aux = lista->primeira->vertice;
    Arestra * segunda = lista->primeira->anterior;

    if(lista->NumeroDeArestras == 0)return NULL;

    free(lista->primeira);
    lista->NumeroDeArestras--;
    lista->primeira = segunda;

    return Aux;
}
static Boolean Fila_vazia(Lista_arestras * lista){
    if(lista->NumeroDeArestras == 0 || lista->primeira == NULL || lista->ultima == NULL){
        return true;
    }else{
        return false;
    }
}
static Error Imprimir_Fila(Lista_arestras * lista){
    int i,j;
    Arestra * Dadoslista = lista->primeira;

    if(Fila_vazia(lista) != true){
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
static Error Limpar_Fila(Lista_arestras * lista){
    Arestra * Dadoslista = lista->primeira;
    Arestra * ProximoAux = NULL;
    int i; 

    if(Fila_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDeArestras;i++){
        ProximoAux = Dadoslista->anterior;
        free(Dadoslista);
        Dadoslista = ProximoAux;
    }
    Inicializar_Fila(lista);
    return Sucesso;
}
// FUNÇÕES DE MANIPULAÇÃO DA FILA - FIM

// FUNÇÕES DE MANIPULAÇÃO DA PILHA - INICIO
static Error Inicializar_Pilha(Lista_arestras * lista){

    lista->NumeroDeArestras = 0;
    lista->primeira = NULL;
    lista->ultima = NULL;

    return Sucesso;
}
static Error Insere_dadoPilha(Vertice * vertice,Lista_arestras * lista){
    Arestra * NovoVertice = (Arestra*)malloc(sizeof(Arestra));

    NovoVertice->vertice = vertice;
    NovoVertice->proximo = lista->primeira;
    lista->NumeroDeArestras++;
    lista->primeira = NovoVertice;

    return Sucesso;
}
static Vertice * Remove_dadoPilha(Lista_arestras * lista){

    Arestra * segunda = lista->primeira->proximo;
    Vertice * VerticeTopo = lista->primeira->vertice;

    //free(lista->primeira);
    lista->primeira = segunda;
    lista->NumeroDeArestras--;

    return VerticeTopo;
}
static Boolean Pilha_vazia(Lista_arestras * lista){
    if(lista->NumeroDeArestras == 0 || lista->primeira == NULL){
        return true;
    }else{
        return false;
    }
}
static Error Imprimir_Pilha(Lista_arestras * lista){
    int i;
    Arestra * DadosArestras = lista->primeira;

    if(Pilha_vazia(lista) != true){
        printf("Imprimindo dados da pilha: \n");
        printf("ID.\n");
        for(i=0;i<(lista->NumeroDeArestras);i++){ 
            printf("%.2d\n",DadosArestras->vertice->ID);
            DadosArestras = DadosArestras->proximo;
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
static Error Limpar_Pilha(Lista_arestras * lista){
    Arestra * DadosPilha = lista->primeira;
    Arestra * ProximaAux = NULL;
    int i; 

    if(Pilha_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDeArestras;i++){
        ProximaAux = DadosPilha->proximo;
        free(DadosPilha);
        DadosPilha = ProximaAux;
    }
    Inicializar_Pilha(lista);
    return Sucesso;
}
// FUNÇÕES DE MANIPULAÇÃO DA PILHA - FIM

// FUNÇÕES DE BUSCA EM GRAFOS - INICIO
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
    
    Inicializar_Fila(FilaDeVertices);
    while(BuscaEncerrada == false && DadoEncontrado == false){    
        ArestraAux = VerticeAtual->arestras->primeira;
        VerticeAtual->auxiliar = cinza;
        for(i=0;i<VerticeAtual->arestras->NumeroDeArestras;i++){
            if(VerticeAtual->auxiliar == preto) break;
            Insere_dadoFila(ArestraAux->vertice,FilaDeVertices);
            ArestraAux = ArestraAux->proximo;
        }
        VerticeAtual->auxiliar = preto;
        //Imprimir_Fila(FilaDeVertices);
        if(VerticeAtual->VerticeValor == DadoProcurado){
            Limpar_Fila(FilaDeVertices);
            DadoEncontrado = true;
            return VerticeAtual;
        }
        if(Fila_vazia(FilaDeVertices) == true){
            BuscaEncerrada = true;
            return NULL;
        }
        VerticeAtual = Remove_dadoFila(FilaDeVertices);
    }
}
Vertice * BuscaVertice_Profundidade(Grafo * grafo,DataType DadoProcurado){
    int i;
    Boolean BuscaEncerrada = false;
    Boolean DadoEncontrado = false;
    Lista_arestras * PilhaDeVertices = (Lista_arestras*)malloc(sizeof(Lista_arestras));
    Arestra * ArestraAux;
    Vertice * VerticeAtual = grafo->primeiro;

    for(i=0;i<grafo->NumeroDeVertices;i++){
        VerticeAtual->auxiliar = branco;
        if(VerticeAtual->proximo != NULL)VerticeAtual = VerticeAtual->proximo;
    }

    Inicializar_Pilha(PilhaDeVertices);
    Insere_dadoPilha(VerticeAtual,PilhaDeVertices);
    while(BuscaEncerrada == false && DadoEncontrado == false){
        ArestraAux = VerticeAtual->arestras->primeira;
        for(i=0;i<VerticeAtual->arestras->NumeroDeArestras;i++){
            if(ArestraAux->vertice->auxiliar != preto){
                ArestraAux->vertice->auxiliar = cinza;
                Insere_dadoPilha(ArestraAux->vertice,PilhaDeVertices);
                break;
            }else{
                ArestraAux = ArestraAux->proximo;
            }
        }
        if(i == VerticeAtual->arestras->NumeroDeArestras - 1) VerticeAtual->auxiliar = preto;
        if(VerticeAtual->arestras->NumeroDeArestras == 0) VerticeAtual->auxiliar = preto;
        //Imprimir_Pilha(PilhaDeVertices);
        if(VerticeAtual->VerticeValor == DadoProcurado){
            Limpar_Pilha(PilhaDeVertices);
            DadoEncontrado = true;
            return VerticeAtual;
        }
        if(Pilha_vazia(PilhaDeVertices) == true){
            BuscaEncerrada = true;
            return NULL;
        }
        VerticeAtual = Remove_dadoPilha(PilhaDeVertices);
        if(VerticeAtual->auxiliar != preto){
            Insere_dadoPilha(VerticeAtual,PilhaDeVertices);
        }
        printf("Novo vertice %d\n",VerticeAtual->ID);
    }

}
// FUNÇÕES DE BUSCA EM GRAFOS- FIM