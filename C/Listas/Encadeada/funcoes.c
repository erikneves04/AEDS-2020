/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de lista encadeada.
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
Error Remove_dado(DataType Valor,Lista * lista){
    int i;
    Item_lista * Dado_anterior = NULL;
    Item_lista * Dado_proximo  = NULL;
    Item_lista * Dados_lista = lista->primeiro;

    Boolean Valor_encontrado = false;

    for(i=0;i<lista->Numero_de_itens;i++){
        if(Dados_lista->Dado == Valor){
            Valor_encontrado = true;
            break;
        }
        Dado_anterior = Dados_lista;
        Dados_lista = Dados_lista->proximo;
        Dado_proximo = Dados_lista->proximo;
    }

    if(Valor_encontrado == true){
        lista->Numero_de_itens--;
        if(Dado_anterior == NULL){
            lista->primeiro = lista->primeiro->proximo;
        }else{
            Dado_anterior->proximo = Dados_lista->proximo;
        }
        free(Dados_lista);
    }else if(Valor_encontrado == false){
        return Dado_nao_encontrado;
    }
    return Sucesso;
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