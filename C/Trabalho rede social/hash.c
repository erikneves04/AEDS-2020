/*
 * @file   hash.c
 * @brief  Arquivo com implementação das funções de 
 *              manipulação da tabela hash.
 * @author <Erik Neves>
 * @date   2020-11-05
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Variaveis&interacoes.h"
#include "structs.h"


static Item_lista * GetColuna(HashTable * table,int ColunaID){
    Item_lista * DadosColuna = NULL;

    if(ColunaID < 0 || ColunaID > table->NumeroDeColunas) return NULL;

    DadosColuna = table->DadosTabela[ColunaID];

    return DadosColuna;
}

Error InicializarHashTable(HashTable * table){
    table->NumeroDeColunas = 0;
    table->DadosTabela = (Item_lista**)malloc(sizeof(Item_lista*));

    return Sucesso;
}
Error InserirHashTable(HashTable * table, DataType * dadosItem){
    int ColunaID = GetColunaPerfil(dadosItem->NomeUsuario);
    int i;
    Item_lista ** NewTable = NULL;
    Item_lista * NovoItemTabela = (Item_lista*)malloc(sizeof(Item_lista));
    Item_lista * DadosColuna = NULL;

    NovoItemTabela->DadosItem = dadosItem;
    NovoItemTabela->Proximo = NULL;
    if(table->NumeroDeColunas < ColunaID){
        NewTable = (Item_lista**)realloc(table->DadosTabela,sizeof(Item_lista*) * ColunaID);
        for(i=table->NumeroDeColunas;i<ColunaID;i++){
            NewTable[i] = NULL;
        }
        table->DadosTabela = NewTable;
        table->NumeroDeColunas = ColunaID;
    }
    if(table->DadosTabela[ColunaID-1] == NULL){
        table->DadosTabela[ColunaID-1] = NovoItemTabela;
    }else{
        DadosColuna = table->DadosTabela[ColunaID-1];
        while(DadosColuna->Proximo != NULL){
            DadosColuna = DadosColuna->Proximo;
        }
        DadosColuna->Proximo = NovoItemTabela;
    }
    return Sucesso;
}
DataType * RemoverDadoHashTable(HashTable * table, char nome[Tamanho_MAX_usuario]){
    int ColunaId = (GetColunaPerfil(nome) - 1);
    Item_lista * Aux = NULL;
    Item_lista * DadoAnterior = NULL;

    if(table->DadosTabela[ColunaId] == NULL) return NULL; // Coluna inexistente
    Aux = table->DadosTabela[ColunaId];
   
    while(Aux != NULL){
        if(strcmp(nome,Aux->DadosItem->NomeCompleto) == 0){
            return Aux->DadosItem;
            break;
        }
        DadoAnterior = Aux;
        Aux = Aux->Proximo;
    }

    return NULL;
}
Error ImprimirDadosColuna(HashTable * table, int coluna){
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;


    DadosColuna = GetColuna(table,coluna-1);

    if(DadosColuna == NULL) return Perfil_inexistente;

    printf("Imprimindo os dados da coluna %.4d:\n",coluna);
    while(DadosColuna != NULL){
        dados = DadosColuna->DadosItem;
        printf("ID: %.2d\n",dados->PerfilID);
        printf("Nome: %s\n",dados->NomeCompleto);
        printf("User: %s\n",dados->NomeUsuario);
        printf("Biografia: %s\n",dados->Biografia);
        DadosColuna = DadosColuna->Proximo;
        printf("\n");
    }

    return Sucesso;
}