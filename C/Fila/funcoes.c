/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de fila.
 * @author <Erik Neves>
 * @date   2020-08-31
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

Error Inicializar_lista(Lista * lista,DataTypeCompare compare,PrintDataType print){
    lista->Numero_de_itens = 0;
    lista->primeiro = NULL;
    lista->ComparaDataType = compare;
    lista->PrintItemDataType = print;

    return Sucesso;
}
Error Insere_dado(DataType Valor,Lista * lista){
    /* INSERE NO FINAL DA LISTA */
    Item_lista * Novo_dado = (Item_lista*)malloc(sizeof(Item_lista));

    if(lista->Numero_de_itens == 0){
        Novo_dado->proximo = lista->primeiro;
        Novo_dado->anterior = NULL;
        lista->primeiro = Novo_dado;
        lista->ultimo = Novo_dado;
    }else{
        Novo_dado->proximo = lista->ultimo;
        Novo_dado->anterior = NULL;
        lista->ultimo->anterior = Novo_dado;
        lista->ultimo = Novo_dado;
    }

    Novo_dado->Dado = Valor;
    lista->Numero_de_itens++;

    return Sucesso;
}
DataType Remove_dado(Lista * lista){
    DataType Aux = lista->primeiro->Dado;
    Item_lista * segundo = lista->primeiro->anterior;

    if(lista->Numero_de_itens == 0){
        return (DataType)Erro_lista_vazia;
    }
    free(lista->primeiro);
    lista->Numero_de_itens--;
    lista->primeiro = segundo;
    return Aux;
}
Boolean Lista_vazia(Lista * lista){
    if(lista->Numero_de_itens == 0 && lista->primeiro == NULL && lista->ultimo == NULL){
        return true;
    }else{
        return false;
    }
}
Error Imprimir_lista(Lista * lista){
    int i;
    Item_lista * Dados_lista = lista->primeiro;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da lista: \n");
        printf("Indi.   Info.\n");
        for(i=0;i<(lista->Numero_de_itens);i++){
            (void)printf(" %.2d     ",i);
            lista->PrintItemDataType(Dados_lista->Dado);
            printf("\n");
            Dados_lista = Dados_lista->anterior; 
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
Error Limpar_lista(Lista * lista){
    Item_lista * Dados_lista = lista->primeiro;
    Item_lista * Proximo_aux = NULL;
    int i; 

    if(Lista_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->Numero_de_itens;i++){
        Proximo_aux = Dados_lista->anterior;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    free(lista);
    return Sucesso;
}