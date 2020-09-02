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

void Inicializar_lista(Lista * lista){
    lista->Numero_de_itens = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
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
Error Remove_dado(Lista * lista){
    DataType Aux = lista->ultimo->Dado;
    Item_lista * segundo = lista->primeiro->anterior;

    if(lista->Numero_de_itens == 0){
        return Erro_lista_vazia;
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
    int i,j;
    char LinhaImpressao[(21 + sizeof(DataType))];
    Item_lista * Dados_lista = lista->primeiro;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da lista: \n");
        printf("Indi.       Info.\n");
        for(i=0,j=1;i<(lista->Numero_de_itens);i++,j++){ 
            (void)sprintf(LinhaImpressao," %%%s          %%%s\n",".2d",PrintfType);
            (void)printf(LinhaImpressao,j,Dados_lista->Dado);
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
    Inicializar_lista(lista);
    return Sucesso;
}