/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de lista encadeada.
 * @author <Erik Neves>
 * @date   2020-10-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// Manipulação de arestras - INICIO
Error Inicializar_listaArestras(Lista_arestras * lista){
    lista->NumeroDeArestras = 0;
    lista->primeira = NULL;

    return Sucesso;
}
Error Insere_dado_listaArestras(Vertice * vertice,Lista_arestras * lista){
    /* INSERE NO INICIO DA LISTA */
    Arestra * Nova_arestra = (Arestra*)malloc(sizeof(Arestra));

    Nova_arestra->vertice = vertice;
    Nova_arestra->proximo = lista->primeira;
    lista->NumeroDeArestras++;
    lista->primeira = Nova_arestra;

    return Sucesso;
}
Error Remover_dado_listaArestras(Lista_arestras * lista, Vertice * vertice){
    Arestra * DadosArestras = lista->primeira;
    Arestra * DadoAnterior = NULL;
    Arestra * ArestraAux;
    int i;

    for(i=0;i<lista->NumeroDeArestras;i++){
        if(DadosArestras->vertice->ID == vertice->ID){
            if(DadoAnterior == NULL){
                if(lista->primeira != NULL){
                    lista->NumeroDeArestras--;
                    ArestraAux = lista->primeira;
                    lista->primeira = lista->primeira->proximo;
                    free(ArestraAux);
                }
            }else{
                lista->NumeroDeArestras--;
                DadoAnterior->proximo = DadosArestras->proximo;
                free(DadosArestras);
            }
        }
        DadoAnterior = DadosArestras;
        DadosArestras = DadosArestras->proximo;
    }    
    return Sucesso;
}
Error ImprimirListaArestras(Lista_arestras * lista){
    int i;
    Arestra * arestras = lista->primeira;

    printf("\n+-----------------------------------+\n");
    printf("| Imprimindo as arestras do vertice |\n");
    printf("+-----------------------------------+\n");

    printf("Arestra     Destino_ID:\n");
    for(i=0;i<lista->NumeroDeArestras;i++){
        printf("  %.3d          %.2d\n",i,arestras->vertice->ID);
    }
    printf("\n");
    
    return Sucesso;
}
Boolean Lista_vazia_Arestras(Lista_arestras * lista){
    if(lista->NumeroDeArestras == 0 && lista->primeira == NULL){
        return true;
    }else{
        return false;
    }
}
Error Limpar_lista_Arestras(Lista_arestras * lista){
    Arestra * Dados_lista = lista->primeira;
    Arestra * Proximo_aux = NULL;
    int i; 

    if(Lista_vazia_Arestras(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDeArestras;i++){
        Proximo_aux = Dados_lista->proximo;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    
    return Sucesso;
}
// Manipulação de arestras - FIM

// Manipulação de vertices - INICIO
Error Inicializar_listaVertices(Grafo * lista){
    lista->NumeroDeVertices = 0;
    lista->primeiro = NULL;

    return Sucesso;
}
Error Insere_dado_listaVertices(DataType valor,Grafo * grafo,Vertice * Novo_vertice){
    /* INSERE NO INICIO DA LISTA */

    Novo_vertice->VerticeValor = valor;
    Novo_vertice->proximo = grafo->primeiro;
    grafo->NumeroDeVertices++;
    grafo->primeiro = Novo_vertice;

    // falta anexar a lista com as arestras

    return Sucesso;
}
Error Remove_dado_listaVertices(Vertice * VerticeAlvo,Grafo * grafo){
    int i;
    Vertice * DadosGrafo = grafo->primeiro;
    Vertice * DadoAnterior = NULL;
    Vertice * DadosAux;

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(DadosGrafo->ID == VerticeAlvo->ID){
            Limpar_lista_Arestras(DadosGrafo->arestras);
            if(DadoAnterior == NULL){
                DadosAux = grafo->primeiro;
                grafo->primeiro = grafo->primeiro->proximo;
                grafo->NumeroDeVertices--;
                free(DadosAux);
            }else{
                DadoAnterior->proximo = DadosGrafo->proximo;
                grafo->NumeroDeVertices--;
                free(DadosGrafo);
            }
            break;
        }
        DadoAnterior = DadosGrafo;
        DadosGrafo = DadosGrafo->proximo;
    }

    
    return Sucesso;
}
Boolean Lista_vazia_Vertices(Grafo * lista){
    if(lista->NumeroDeVertices == 0 && lista->primeiro == NULL){
        return true;
    }else{
        return false;
    }
}
Error Limpar_lista_Vertices(Grafo * lista){
    Vertice * Dados_lista = lista->primeiro;
    Vertice * Proximo_aux = NULL;
    int i; 

    if(Lista_vazia_Vertices(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDeVertices;i++){
        Proximo_aux = Dados_lista->proximo;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    
    return Sucesso;
}
// Manipulação de vertices - FIM