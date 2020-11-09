/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de lista duplamente encadeada.
 * @author <Erik Neves>
 * @date   2020-11-07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"

Error Inicializar_lista(Lista * lista){
    Lista * Aux = (Lista*)malloc(sizeof(Lista));
    lista = Aux;

    lista->CountFollows = 0;
    lista->primeira = NULL;

    return Sucesso;
}
Error Insere_dado(DataType * Valor,Lista * lista){
    /* INSERE NO INICIO DA LISTA */
    Item_lista * Novo_dado = (Item_lista*)malloc(sizeof(Item_lista));

    Novo_dado->DadosItem = Valor;
    Novo_dado->Proximo = lista->primeira;
    Novo_dado->Anterior = NULL;
    if(lista->primeira != NULL){
        lista->primeira->Anterior = Novo_dado;
    }
    lista->CountFollows++;
    lista->primeira = Novo_dado;

    return Sucesso;
}
Error Remove_dado(DataType * Valor,Lista * lista){
    int i;
    Item_lista * Dado_anterior = NULL;
    Item_lista * Dado_proximo  = NULL;
    Item_lista * Dados_lista = lista->primeira;

    Boolean Valor_encontrado = false;

    for(i=0;i<lista->CountFollows;i++){
        if(strcmp(Dados_lista->DadosItem->NomeCompleto,Valor->NomeCompleto) == 0){
            Valor_encontrado = true;
            break;
        }
        Dado_anterior = Dados_lista;
        Dados_lista = Dados_lista->Proximo;
        Dado_proximo = Dados_lista->Proximo;
    }

    if(Valor_encontrado == true){
        lista->CountFollows--;
        if(Dados_lista->Anterior != NULL){
            Dados_lista->Anterior->Proximo = Dados_lista->Proximo;
            if(Dados_lista->Proximo != NULL){
                Dados_lista->Proximo->Anterior = Dados_lista->Anterior;
            }
        }else{
            Dados_lista->Proximo->Anterior = NULL;
            lista->primeira = Dados_lista->Proximo;
        }
        free(Dados_lista);
    }else if(Valor_encontrado == false){
        return Perfil_inexistente;
    }
    return Sucesso;
}
Boolean Lista_vazia(Lista * lista){
    return (lista->CountFollows == 0) ? true : false;
}
Error Imprimir_lista(Lista * lista){
    int i;
    Item_lista * Dados_lista = lista->primeira;

    if(Lista_vazia(lista) != true){
        printf("Imprimindo dados da lista: \n");
        printf("Indi.       Info.       Ant.\n");
        for(i=0;i<(lista->CountFollows);i++){
            // TO DO impressão
            Dados_lista = Dados_lista->Proximo; 
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
Error Limpar_lista(Lista * lista){
    Item_lista * Dados_lista = lista->primeira;
    Item_lista * Proximo_aux = NULL;
    int i; 

    if(Lista_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->CountFollows;i++){
        Proximo_aux = Dados_lista->Proximo;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    free(lista);
    return Sucesso;
}