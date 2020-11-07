/*
 * @file   funcoesLE.c
 * @brief  Implementaçao das funçoes de manipulaçao de listas.
 * @author <Erik Neves>
 * @date   2020-11-07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// Manipulação de listas - INICIO
Error InicializarLista(Lista * lista){
    lista->NumeroDeDados = 0;
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;

    return Sucesso;
}
Error InserirItemLista(Lista * lista, DataType * dadosItem){
    Item_lista * NovoItem = (Item_lista*)malloc(sizeof(Item_lista));

    NovoItem->Anterior = NULL;
    if(lista->Primeiro == NULL){
        lista->Primeiro = NovoItem;
        lista->Ultimo = NovoItem;
        NovoItem->Proximo = NULL;
    }else{
        NovoItem->Proximo = lista->Primeiro;
        lista->Primeiro->Anterior = NovoItem;
        lista->Primeiro = NovoItem;
    }

    NovoItem->DadosItem = dadosItem;
    lista->NumeroDeDados++;
    return Sucesso;
}
Error RemoverItemLista(Lista * lista,DataType * dadosItem){
    int i;
    Boolean DadoEncontrado = false;
    Item_lista * DadosLista = lista->Primeiro;

    for(i=0;i<lista->NumeroDeDados;i++){
        if(DadosLista->DadosItem->Telefone == dadosItem->Telefone){
            if(strcmp(DadosLista->DadosItem->Nome,dadosItem->Nome) == 0){
                DadoEncontrado = true;
                break;
            }
        }
        DadosLista = DadosLista->Proximo;
    }

    if(DadoEncontrado == true){
        if(DadosLista->Anterior != NULL)DadosLista->Anterior->Proximo = DadosLista->Proximo;  
        if(DadosLista->Proximo != NULL)DadosLista->Proximo->Anterior = DadosLista->Anterior;

        lista->NumeroDeDados--;
        DadosLista->Anterior = NULL;
        DadosLista->Proximo = NULL;
        free(DadosLista);
    }else{
        return Dado_nao_encontrado;
    }
    return Sucesso;
}
DataType * GetItemLista(Lista * lista, unsigned int posicao){
    int i;
    Boolean PosicaoEncontrada = false;
    Item_lista * DadosLista = lista->Primeiro;

    if(posicao <= lista->NumeroDeDados && posicao >= 0){
        for(i=0;i<posicao;i++){
            DadosLista = DadosLista->Proximo;
        }
        PosicaoEncontrada = true;
    }

    return (PosicaoEncontrada == true) ? DadosLista->DadosItem : NULL;
}
Boolean EstadoLista(Lista * lista){
    return (lista->NumeroDeDados == 0) ? true : false;
}
Error LimparLista(Lista * lista){
    int i;
    Item_lista * DadosLista = lista->Primeiro;
    Item_lista * DadosAux;

    for(i=0;i<lista->NumeroDeDados;i++){
        DadosAux = DadosLista->Proximo;
        free(DadosLista->DadosItem);
        free(DadosLista);
        DadosLista = DadosAux;
    }

    return Sucesso;
}
// Manipulação de listas - FIM