/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de Pilha.
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
}
Error Insere_dado(DataType Valor,Lista * lista){
    /* INSERE NO INICIO DA LISTA */
    Item_lista * Novo_dado = (Item_lista*)malloc(sizeof(Item_lista));

    Novo_dado->Dado = Valor;
    Novo_dado->proximo = lista->primeiro;
    lista->Numero_de_itens++;
    lista->primeiro = Novo_dado;

    return Sucesso;
}
DataType Remove_dado(Lista * lista){
    DataType Aux;
    Item_lista * segundo = lista->primeiro->proximo;

    if(lista->Numero_de_itens == 0){
        return Erro_lista_vazia;
    }

    Aux = lista->primeiro->Dado;
    free(lista->primeiro);
    lista->primeiro = segundo;

    lista->Numero_de_itens--;
    return Aux;
}
Boolean Lista_vazia(Lista * lista){
    if(lista->Numero_de_itens == 0 && lista->primeiro == NULL){
        return true;
    }else{
        return false;
    }
}
Error Imprimir_lista(Lista * lista){
    int i;
    char LinhaImpressao[(21 + sizeof(DataType))];
    Item_lista * Dados_lista = lista->primeiro;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da lista: \n");
        printf("Indi.       Info.\n");
        for(i=0;i<(lista->Numero_de_itens);i++){ 
            (void)sprintf(LinhaImpressao," %%%s          %%%s\n",".2d",PrintfType);
            (void)printf(LinhaImpressao,i,Dados_lista->Dado);
            Dados_lista = Dados_lista->proximo; 
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
        Proximo_aux = Dados_lista->proximo;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    Inicializar_lista(lista);
    return Sucesso;
}