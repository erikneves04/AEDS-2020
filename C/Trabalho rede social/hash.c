/**
* @file   hash.c
* @brief  Arquivo com implementação das funções de 
*              manipulação da tabela hash.
* @author <Erik Neves>
* @date   2020-11-05
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
#include "Variaveis&interacoes.h"
#include "structs.h"
#include "Manipulacao_ListaEncadeada.h"
#include "warnings.h"
#include "Recomendacoes.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


Item_lista * GetColuna(HashTable * table,int ColunaID){
    /**
    * Função responsavel por identificar uma coluna em uma tabela hash. 
    * @return ponteiro para o primeiro item da coluna procurada 
    *              ou NULL caso a coluna não exista.
    */
    Item_lista * DadosColuna = NULL;

    if(ColunaID < 0 || ColunaID > table->NumeroDeColunas) return NULL;

    DadosColuna = table->DadosTabela[ColunaID];

    return DadosColuna;
}
int GetMaiorIDAtual(HashTable * table){
    /**
    * Função responsavel por identificar o maios ID da tabela.
    * @return inteiro ID.
    */
    DataType * dados = NULL;
    Item_lista * DadosColuna = NULL;
    int i;
    int MaiorID = 0;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            dados = DadosColuna->DadosItem;
            if(dados->PerfilID > MaiorID)MaiorID = dados->PerfilID;
            DadosColuna = DadosColuna->Proximo;
        }
    }
    return MaiorID;
}

Error InicializarHashTable(HashTable * table){
    /**
    * Função responsavel por inicializar a estrutura da tabela hash.
    * @return Sucesso caso ocorra tudo certo.
    */
    table->NumeroDeColunas = 0;
    table->DadosTabela = (Item_lista**)malloc(sizeof(Item_lista*));
    table->NumeroDePerfis = 0;

    return Sucesso;
}
Error InserirHashTable(HashTable * table, DataType * dadosItem){
    /**
    * Função responsavel por inserir um dado(DataType) na tabela hash. 
    * @return Sucesso caso ocorra tudo certo.
    */
    int ColunaID = GetColunaPerfil(dadosItem->NomeUsuario);
    int i;
    Item_lista ** NewTable = NULL;
    Item_lista * NovoItemTabela = (Item_lista*)malloc(sizeof(Item_lista));
    Item_lista * DadosColuna = NULL;

    NovoItemTabela->DadosItem = dadosItem;
    NovoItemTabela->Proximo = NULL;
    table->NumeroDePerfis++;
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
    /**
    * Função responsavel por remover um dado(DataType) da tabela hash. 
    * @return ponteiro para um DataType caso ocorra tudo certo.
    */
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
            table->NumeroDePerfis--;
            break;
        }
        DadoAnterior = Aux;
        Aux = Aux->Proximo;
    }

    return DataAux;
}
Error RemoverIndexPost_PerfisQCurtiram(Post * postagem){
    /**
    * Função responsavel por remover as curtidas de um usuario nos demais posts. 
    * @return Sucesso caso ocorra tudo certo.
    */
    int i;
    Item_lista * DadosCurtidas;

    for(i=0;i<postagem->Curtidas->NumeroDeColunas;i++){
        DadosCurtidas = postagem->Curtidas->DadosTabela[i];
        while(DadosCurtidas != NULL){
            Remove_dadoPost(postagem,DadosCurtidas->DadosItem->PostagensCurtidas);
            DadosCurtidas = DadosCurtidas->Proximo;
        }
    }

    return Sucesso;
}
DataType * DeletarPerfil(HashTable * table, DataType * Alvo,DataType * Atual, Recomendacoes * recomendacoes){
    /**
    * Função responsavel por deletar um dado(DataType) e limpar sua memoria no sistema. 
    * @return ponteiro para um DataType caso ocorra tudo certo.
    */
    DataType * RemoveReturn = NULL;
    Item_Post * DadosPosts = NULL;
    Item_lista * DadosPerfis = NULL;
    Boolean AtualAlvo = false;
    int i;

    if(Alvo == NULL){
        AtivacaoDefault();
        return Alvo;
    }

    RemoveReturn = RemoverDadoHashTable(table,Alvo->NomeUsuario);

    if(RemoveReturn == NULL){
        PerfilNaoEncontrado();
    }else{
        if(RemoveReturn->PerfilID == Atual->PerfilID)AtualAlvo = true;
        RemoveIndexPerfilRecomedado(RemoveReturn,recomendacoes);
        PerfilDeletado(RemoveReturn->PerfilID);
        RemoveCurtidas(RemoveReturn->PostagensCurtidas,RemoveReturn);
        
        DadosPosts = RemoveReturn->Postagens->Primeira;
        for(i=0;i<RemoveReturn->Postagens->NumeroDePostagens;i++){
            RemoveIndexPostRecomedado(DadosPosts->dadosItem,recomendacoes);
            RemoverIndexPost_PerfisQCurtiram(DadosPosts->dadosItem);
            DadosPosts = DadosPosts->Proxima;
        }
        Limpar_listaPost(RemoveReturn->PostagensCurtidas,false);
        
        DadosPerfis = RemoveReturn->PerfilSeguindo->primeira;
        for(i=0;i<RemoveReturn->PerfilSeguindo->CountFollows;i++){
            Remove_dado(RemoveReturn,DadosPerfis->DadosItem->Seguidores);
            DadosPerfis = DadosPerfis->Proximo;
        }
        Limpar_lista(RemoveReturn->PerfilSeguindo);

        DadosPerfis = RemoveReturn->Seguidores->primeira;
        for(i=0;i<RemoveReturn->Seguidores->CountFollows;i++){
            Remove_dado(RemoveReturn,DadosPerfis->DadosItem->PerfilSeguindo);
            DadosPerfis = DadosPerfis->Proximo;
        }
        Limpar_lista(RemoveReturn->Seguidores);

        Limpar_listaPost(RemoveReturn->Postagens,true);
        free(RemoveReturn);
        RemoveReturn = NULL;
        Alvo = NULL;
    }   
    return (AtualAlvo == true) ? NULL : Atual;
}
Error ImprimirDadosColuna(HashTable * table, int coluna){
    /**
    * Função responsavel por imprimir os dados de uma coluna.
    *  -> Por default essa função não está sendo utilizada. 
    * @return Sucesso caso ocorra tudo certo.
    */
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
    /**
    * Função responsavel por imprimir todos os perfis cadastrados.
    * @return Sucesso caso ocorra tudo certo.
    */
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
    /**
    * Função responsavel por imprimir as curtidas de um determinado post.
    * @return Sucesso caso ocorra tudo certo.
    */
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
    /**
    * Função responsavel por verificar se um dado existe em uma tabela hash.
    * @return Booleano(true or false).
    */
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
    /**
    * Função responsavel por limpar os perfis de uma tabela hash.
    * @return Sucesso caso ocorra tudo certo.
    */
    int i;
    Item_lista * DadosColuna;
    Item_lista * DadosAux;

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            DadosAux = DadosColuna->Proximo;
            Limpar_lista(DadosColuna->DadosItem->PerfilSeguindo);
            Limpar_lista(DadosColuna->DadosItem->Seguidores);
            Limpar_listaPost(DadosColuna->DadosItem->Postagens,true);
            if(DadosColuna != NULL )free(DadosColuna);
            DadosColuna = DadosAux;
        }
    }
    free(table);

    return Sucesso;
}
Error LimparPostHashTable(HashTable * table){
    /**
    * Função responsavel por limpar as curtidas de um post.
    * @return Sucesso caso ocorra tudo certo.
    */
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
DataType * GetPerfilAlvo_NoInteract(HashTable * table, char NomeProcurado[Tamanho_MAX_usuario]){
    /**
    * Função responsavel por localizar um perfil procurado.
    * @return ponteiro para um perfil.
    */
    DataType * Alvo = NULL;
    Item_lista * DadosColuna = NULL;
    int ColunaID;

    ColunaID = (GetColunaPerfil(NomeProcurado) - 1);
    if(ColunaID < 0 || ColunaID >= table->NumeroDeColunas) return Alvo;
    if(table->DadosTabela[ColunaID] == NULL) return Alvo;

    DadosColuna = table->DadosTabela[ColunaID];
    while(DadosColuna != NULL){
        if(strcmp(NomeProcurado,DadosColuna->DadosItem->NomeUsuario) == 0){
            Alvo = DadosColuna->DadosItem;
            break;
        }
        DadosColuna = DadosColuna->Proximo;
    }

    return Alvo;
}