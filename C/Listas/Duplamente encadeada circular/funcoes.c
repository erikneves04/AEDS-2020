/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de lista duplamente encadeada circular.
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
Error Insere_dado(int Valor,Lista * lista){
    /* INSERE NO INICIO DA LISTA */

    int i;
    Item_lista * Novo_dado = (Item_lista*)malloc(sizeof(Item_lista));
    Item_lista * Dados_lista = lista->primeiro;
    Item_lista * Ultimo_dado = NULL;
    Boolean Ultimo_encontrado = false;

    for(i=0;i<lista->Numero_de_itens;i++){
        if(i == (lista->Numero_de_itens - 1) && Dados_lista != NULL){
            Ultimo_encontrado = true;
            Ultimo_dado = Dados_lista;
        }
        Dados_lista = Dados_lista->proximo;
    }

    if(Ultimo_encontrado == true){
        Novo_dado->proximo = lista->primeiro;
        Novo_dado->anterior = Ultimo_dado;
        Ultimo_dado->proximo = Novo_dado;
        lista->primeiro->anterior = Novo_dado;
    }else{
        Novo_dado->proximo = Novo_dado;
        Novo_dado->anterior = Novo_dado;
    }

    Novo_dado->Dado = Valor;
    lista->Numero_de_itens++;
    lista->primeiro = Novo_dado;

    return Sucesso;
}
Error Remove_dado(int Valor,Lista * lista){
    int i;
    Item_lista * Dados_lista = lista->primeiro;
    Item_lista * Dado_anterior;
    Item_lista * Dado_proximo;

    Boolean Valor_encontrado = false;

    for(i=0;i<lista->Numero_de_itens;i++){
        if(Dados_lista->Dado == Valor){
            Valor_encontrado = true;
            break;
        }
        Dados_lista = Dados_lista->proximo;
    }

    if(Valor_encontrado == true){    
        if(lista->Numero_de_itens == 1){
            lista->primeiro = NULL;
        }else{
            Dado_anterior = Dados_lista->anterior;
            Dado_proximo = Dados_lista->proximo;

            Dado_anterior->proximo = Dado_proximo;
            Dado_proximo->anterior = Dado_anterior;

            if(Dados_lista == lista->primeiro){
                lista->primeiro = Dado_proximo;
            }
        }
        lista->Numero_de_itens--;
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
    Item_lista * Dados_lista = lista->primeiro;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da lista: \n");
        printf("Indi.       Info.       Ant.\n");
        for(i=0;i<(lista->Numero_de_itens);i++){
            printf(" %.2d          %.2d          %.2d\n",i,Dados_lista->Dado,Dados_lista->anterior->Dado);
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