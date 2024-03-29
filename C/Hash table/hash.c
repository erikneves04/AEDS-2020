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
#include "const.h"
#include "interact.h"

static int IdentificaColuna_HashTable(char * string){
    int count = 0;
    int i;
    
    for(i=0;i<strlen(string);i++){
        count += (int)string[i];
    }
    
    return ((int)count/10);
}
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
    int ColunaID = IdentificaColuna_HashTable(dadosItem->Nome);
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
Error RemoverDadoHashTable(HashTable * table, char nome[Tamanho_MAX_string]){
    int ColunaId = (IdentificaColuna_HashTable(nome) - 1);
    Item_lista * Aux;
    Item_lista * DadoAnterior = NULL;

    if(table->DadosTabela[ColunaId] == NULL) return Dado_nao_encontrado;
    Aux = table->DadosTabela[ColunaId];
   
    while(Aux != NULL){
        if(strcmp(nome,Aux->DadosItem->Nome) == 0){
            if(DadoAnterior == NULL){
                table->DadosTabela[ColunaId] = Aux->Proximo;
                free(Aux->DadosItem->Endereco);
                free(Aux->DadosItem);
                free(Aux);
            }else{
                DadoAnterior->Proximo = Aux->Proximo;
                free(Aux);
            }
            break;
        }
        DadoAnterior = Aux;
        Aux = Aux->Proximo;
    }

    return Sucesso;
}
Error ImprimirDadosColuna(HashTable * table, int coluna){
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;


    DadosColuna = GetColuna(table,coluna);

    if(DadosColuna == NULL) return Dado_nao_encontrado;

    printf("Imprimindo os dados da coluna %.4d:\n",coluna+1);
    while(DadosColuna != NULL){
        dados = DadosColuna->DadosItem;
        printf("\nNome: %-25s   Telefone: %d\n",dados->Nome,dados->Telefone);
        printf("Rua: %-25s    Numero: %.4d\n",dados->Endereco->Rua,dados->Endereco->Numero);
        printf("Bairro: %-25s Cidade: %-25s\n\n",dados->Endereco->Bairro,dados->Endereco->Cidade);
        DadosColuna = DadosColuna->Proximo;
    }

    return Sucesso;
}