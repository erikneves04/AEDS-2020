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
#include "warnings.h"


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
        free(table->DadosTabela);
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
    DataType * DataAux = NULL;

    if(table->DadosTabela[ColunaId] == NULL) return NULL; // Coluna inexistente
    Aux = table->DadosTabela[ColunaId];
    
    while(Aux != NULL){
        if(strcmp(nome,Aux->DadosItem->NomeUsuario) == 0){
            if(DadoAnterior == NULL){
                table->DadosTabela[ColunaId] = Aux->Proximo;
                if(Aux->Proximo != NULL) Aux->Proximo->Anterior = NULL;
            }else{
                DadoAnterior->Proximo = Aux->Proximo;
                if(Aux->Proximo != NULL) Aux->Proximo->Anterior = NULL;
            }
            DataAux = Aux->DadosItem;
            free(Aux);
            break;
        }
        DadoAnterior = Aux;
        Aux = Aux->Proximo;
    }

    return DataAux;
}
DataType * DeletarPerfil(HashTable * table, DataType * Alvo){
    DataType * RemoveReturn = NULL;

    if(Alvo == NULL){
        PerfilNaoEncontrado();
        return Alvo;
    }

    RemoveReturn = RemoverDadoHashTable(table,Alvo->NomeUsuario);

    if(RemoveReturn == NULL){
        PerfilNaoEncontrado();
        return Alvo;
    }else{
        Imprimir_listaPost(RemoveReturn->PostagensCurtidas,RemoveReturn);
        PerfilDeletado(RemoveReturn->PerfilID);
        RemoveCurtidas(RemoveReturn->PostagensCurtidas,RemoveReturn);
        Limpar_listaPost(RemoveReturn->PostagensCurtidas,false);
        Limpar_lista(RemoveReturn->PerfilSeguindo);
        Limpar_listaPost(RemoveReturn->Postagens,true);
        free(RemoveReturn);
        RemoveReturn = NULL;
        Alvo = NULL;
    }   

    return Alvo;
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
Error ImprimirTODOSCurtidas_HashTable(Post * postagem){
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;
    int i;
    Boolean TituloAtivado = false;
    HashTable * table;

    table = postagem->Curtidas;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            if(TituloAtivado == false){
                TituloAtivado = true;
                printf("\n+----------------------+\n");
                printf("| Curtidas deste post: |\n");
                printf("+----------------------+\n");
                printf("| %s\n","User name:");
            }
            dados = DadosColuna->DadosItem;
            printf("| %s\n",dados->NomeUsuario);
            DadosColuna = DadosColuna->Proximo;
        }
    }
    if(TituloAtivado == false){
        printf("\n| -> Nao ha curtidas neste post. |\n");
    }
    printf("\n");
    return (TituloAtivado == true) ? Sucesso : Perfil_inexistente;
}
Boolean DadoExistenteHashTable(HashTable * table, DataType * dadosItem){
    Boolean DadoEncontrado = false;
    int IDColuna;
    Item_lista * DadosColuna;

    if(dadosItem == NULL) return false;
    IDColuna = (GetColunaPerfil(dadosItem->NomeUsuario) - 1);
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
            Limpar_listaPost(DadosColuna->DadosItem->Postagens,true);
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