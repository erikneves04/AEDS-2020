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
#include "Manipulacao_ListaEncadeada.h"


Item_lista * GetColuna(HashTable * table,int ColunaID){
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
    DataType * DataAux;

    if(table->DadosTabela[ColunaId] == NULL) return NULL; // Coluna inexistente
    Aux = table->DadosTabela[ColunaId];
   
    while(Aux != NULL){
        if(strcmp(nome,Aux->DadosItem->NomeUsuario) == 0){
            table->DadosTabela[ColunaId] = Aux->Proximo;
            DataAux = Aux->DadosItem;
            return DataAux;
        }
        DadoAnterior = Aux;
        Aux = Aux->Proximo;
    }

    return NULL;
}
Error DeletarPerfil(HashTable * table){
    DataType * Alvo = GetPerfilAlvo(table);
    DataType * RemoveReturn = NULL;
    Item_lista * DadosColuna;
    int ColunaID;

    if(Alvo == NULL){
        PerfilNaoEncontrado();
        return Perfil_inexistente;
    }
    ColunaID = (GetColunaPerfil(Alvo->NomeUsuario) - 1);
    DadosColuna = table->DadosTabela[ColunaID];

    RemoveReturn = RemoverDadoHashTable(table,Alvo->NomeUsuario);

    if(RemoveReturn == NULL){
        PerfilNaoEncontrado();
        return Perfil_inexistente;
    }else{
        PerfilDeletado(RemoveReturn->PerfilID);
        free(RemoveReturn);
    }   

    return Sucesso;
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
Error ImprimirTODOSPerfis_HashTable(HashTable * table){
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;
    int i;
    Boolean TituloAtivado = false;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            if(TituloAtivado == false){
                TituloAtivado = true;
                printf("\n\t+---------------------------------+\n");
                printf("\t| Imprimindo os perfis existentes |\n");
                printf("\t+---------------------------------+\n\n");
                printf(" ID: | User name:\n");
            }
            dados = DadosColuna->DadosItem;
            printf(" %.2d  | %-25s\n",dados->PerfilID,dados->NomeUsuario);
            DadosColuna = DadosColuna->Proximo;
        }
    }
    if(TituloAtivado == false){
        printf("\n+------------------------------------------+\n");
        printf("| Desculpe, mas nao ha perfis cadastrados. |\n");
        printf("+------------------------------------------+\n");
    }
    printf("\n");
    return (TituloAtivado == true) ? Sucesso : Perfil_inexistente;
}
Error ImprimirTODOSCurtidas_HashTable(HashTable * table){
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;
    int i;
    Boolean TituloAtivado = false;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            if(TituloAtivado == false){
                TituloAtivado = true;
                printf("\n+------------------------+\n");
                printf("| Curtidas deste post: |\n");
                printf("+----------------------+\n\n");
                printf("| %-25s |\n","User name:");
            }
            dados = DadosColuna->DadosItem;
            printf("| %-25s |\n",dados->NomeUsuario);
            DadosColuna = DadosColuna->Proximo;
        }
    }
    if(TituloAtivado == false){
        printf("\n+-------------------------------------------+\n");
        printf("| Desculpe, mas nao ha curtidas neste post. |\n");
        printf("+-------------------------------------------+\n");
    }
    printf("\n");
    return (TituloAtivado == true) ? Sucesso : Perfil_inexistente;
}
Boolean DadoExistenteHashTable(HashTable * table, DataType * dadosItem){
    Boolean DadoEncontrado = false;
    int IDColuna = (GetColunaPerfil(dadosItem->NomeUsuario) - 1);
    Item_lista * DadosColuna;

    DadosColuna = GetColuna(table,IDColuna);

    while(DadosColuna != NULL){
        if(DadosColuna->DadosItem->PerfilID == dadosItem->PerfilID){
            DadoEncontrado = true;
            break;
        }
        DadosColuna = DadosColuna->Proximo;
    } 

    return DadoEncontrado;
}
Error LimparUsersHashTable(HashTable * table){
    int i;
    Item_lista * DadosColuna;
    Item_lista * DadosAux;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            DadosAux = DadosColuna->Proximo;
            Limpar_lista(DadosColuna->DadosItem->PerfilSeguindo);
            Limpar_listaPost(DadosColuna->DadosItem->Postagens);
            if(DadosColuna != NULL )free(DadosColuna);
            DadosColuna = DadosAux;
        }
    }
    free(table);

    return Sucesso;
}
Error LimparPostHashTable(HashTable * table){
    int i;
    Item_lista * DadosColuna;
    Item_lista * DadosAux;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            DadosAux = DadosColuna->Proximo;
            free(DadosColuna);
            DadosColuna = DadosAux;
        }
    }
    free(table);

    return Sucesso;
}