/**
* @file   DataBase.c
* @brief  Arquivo com as implementações das funções de
*                saves dos dados do software.
* @author <Erik Neves>
* @date   2020-11-14
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
#include "warnings.h"
#include "structs.h"
#include "hash.h"
#include "Variaveis&interacoes.h"
#include "Manipulacao_ListaEncadeada.h"
#include "Recomendacoes.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


Error LoadAllSavedData(HashTable * table,Recomendacoes * recomendacoes){
    /**
    * Função responsavel por carregar os dados dos arquivos na memória do programa.
    * @return Sucesso caso tudo ocorra de forma correta.
    */
    int i,j,k;
    int aux;
    int NumPosts;
    int NumLikes;
    int NumPerfisRecomendados;
    int NumPostsRecomendados;
    int PostIDAux;
    FILE * ArquivoPerfis;
    FILE * ArquivoPostagens;
    FILE * ArquivoFollows;
    FILE * ArquivoLikes;
    FILE * ArquivoRecomendacoes;
    DataType * PerfisAux;
    StructFiles DadosLeitura;
    Post * PostsAux;
    Item_Post * ItemPostAux;
    long int NumeroDePerfis = 0;
    char UsersNameAux[Tamanho_MAX_usuario];
    int EscritaNomeUsuario = sizeof(char) * Tamanho_MAX_usuario;
    int EscritaPost = sizeof(char) * Tamanho_MAX_post;

    int * NumeroDeFollows;
    int ** NumeroDeLikes;

    DataType ** Perfis;

    int NumeroStaticPerfis,NumeroStaticPosts;

    ArquivoPerfis = fopen(".\\saves\\Perfis.bin","r+b");
    ArquivoPostagens = fopen(".\\saves\\Posts.bin","r+b");
    ArquivoFollows = fopen(".\\saves\\Follows.bin","r+b");
    ArquivoLikes = fopen(".\\saves\\Likes.bin","r+b");
    ArquivoRecomendacoes = fopen(".\\saves\\Recomendacoes.bin","r+b");


    if(ArquivoPerfis == NULL || ArquivoPostagens == NULL || ArquivoFollows == NULL || ArquivoLikes == NULL || ArquivoRecomendacoes == NULL){
        ArquivoCorrompido();
        return Arquivo_corrompido;
    }

    fseek(ArquivoPerfis, 0, SEEK_END);
    aux = ftell(ArquivoPerfis);
    NumeroDePerfis = ((aux - (2 * sizeof(int)))/sizeof(StructFiles));
    fseek(ArquivoPerfis, 0, SEEK_SET);

    if(aux == 0) return Arquivo_vazio;
    
    fread(&NumeroStaticPerfis,sizeof(int),1,ArquivoPerfis);
    for(i=0;i<NumeroStaticPerfis;i++)GetIdPerfil();
    fread(&NumeroStaticPosts,sizeof(int),1,ArquivoPerfis);
    for(i=0;i<NumeroStaticPosts;i++)GetIdPost();
    
    NumeroDeFollows = (int*)malloc(sizeof(int) * NumeroDePerfis);
    NumeroDeLikes = (int**)malloc(NumeroDePerfis * sizeof(int*));
    Perfis = (DataType**)malloc(sizeof(DataType*) * NumeroDePerfis);

    for(i=0;i<NumeroDePerfis;i++){
        PerfisAux = (DataType*)malloc(sizeof(DataType));
        Perfis[i] = PerfisAux;
        fread(&DadosLeitura,sizeof(StructFiles),1,ArquivoPerfis);
        strcpy(PerfisAux->Biografia,DadosLeitura.Biografia);
        strcpy(PerfisAux->NomeCompleto,DadosLeitura.NomeCompleto);
        strcpy(PerfisAux->NomeUsuario,DadosLeitura.NomeUsuario);
        PerfisAux->PerfilID = DadosLeitura.PerfilID;
        NumeroDeFollows[i] = DadosLeitura.NumFollows;

        PerfisAux->PerfilSeguindo = (Followed_list*)malloc(sizeof(Followed_list));
        Inicializar_lista(PerfisAux->PerfilSeguindo);
        PerfisAux->Seguidores = (Followed_list*)malloc(sizeof(Followed_list));
        Inicializar_lista(PerfisAux->Seguidores);
        PerfisAux->Postagens = (ListaPostagens*)malloc(sizeof(ListaPostagens));
        Inicializar_listaPost(PerfisAux->Postagens);
        PerfisAux->PostagensCurtidas = (ListaPostagens*)malloc(sizeof(ListaPostagens));
        Inicializar_listaPost(PerfisAux->PostagensCurtidas);

        NumeroDeLikes[i] = (int*)calloc(DadosLeitura.NumPosts,sizeof(int));
        for(j=0;j<DadosLeitura.NumPosts;j++){
            PostsAux = (Post*)malloc(sizeof(Post));
            PostsAux->Curtidas = (HashTable*)malloc(sizeof(HashTable));;
            InicializarHashTable(PostsAux->Curtidas);
            fread(&PostsAux->ID,sizeof(unsigned int),1,ArquivoPostagens);
            fread(PostsAux->Postagem,EscritaPost,1,ArquivoPostagens);
            fread(&NumLikes,sizeof(int),1,ArquivoPostagens);
            NumeroDeLikes[i][j] = NumLikes;
            Insere_dadoPost(PostsAux,PerfisAux->Postagens);
        }
        InserirHashTable(table,PerfisAux);
    }

    for(i=0;i<NumeroDePerfis;i++){
        ItemPostAux = Perfis[i]->Postagens->Primeira;
        for(j=0;j<Perfis[i]->Postagens->NumeroDePostagens;j++){
            if(ItemPostAux->Proxima != NULL) ItemPostAux = ItemPostAux->Proxima;
        }
        for(k=0;k<Perfis[i]->Postagens->NumeroDePostagens;k++){
            for(j=0;j<NumeroDeLikes[i][k];j++){
                fread(UsersNameAux,EscritaNomeUsuario,1,ArquivoLikes);
                PerfisAux = GetPerfilAlvo_NoInteract(table,UsersNameAux);
                InserirHashTable(ItemPostAux->dadosItem->Curtidas,PerfisAux);
                Insere_dadoPost(ItemPostAux->dadosItem,PerfisAux->PostagensCurtidas);
            }
            ItemPostAux = ItemPostAux->Anterior;
        }
    }
    
    for(i=0;i<NumeroDePerfis;i++){
        for(j=0;j<NumeroDeFollows[i];j++){
            fread(UsersNameAux,EscritaNomeUsuario,1,ArquivoFollows);
            PerfisAux = GetPerfilAlvo_NoInteract(table,UsersNameAux);
            Insere_dado(PerfisAux,Perfis[i]->PerfilSeguindo);
            Insere_dado(Perfis[i],PerfisAux->Seguidores);
        }
    }
    

    /*
    InserirNovoPerfilRecomendado
    InserirNovoPostRecomendado
    */
    fseek(ArquivoRecomendacoes, 0, SEEK_END);
    aux = ftell(ArquivoRecomendacoes);
    fseek(ArquivoRecomendacoes, 0, SEEK_SET);

    if(aux == 0){
        NumPerfisRecomendados = 0;
        NumPostsRecomendados = 0;
    }else{
        fread(&NumPerfisRecomendados,sizeof(int),1,ArquivoRecomendacoes);
        fread(&NumPostsRecomendados,sizeof(int),1,ArquivoRecomendacoes);
    }

    for(i=0;i<NumPerfisRecomendados;i++){
        fread(UsersNameAux,EscritaNomeUsuario,1,ArquivoRecomendacoes);
        PerfisAux = GetPerfilAlvo_NoInteract(table,UsersNameAux);
        InserirNovoPerfilRecomendado(PerfisAux,recomendacoes);   
    }
    for(i=0;i<NumPostsRecomendados;i++){
        fread(UsersNameAux,EscritaNomeUsuario,1,ArquivoRecomendacoes);
        PerfisAux = GetPerfilAlvo_NoInteract(table,UsersNameAux);
        fread(&PostIDAux,sizeof(int),1,ArquivoRecomendacoes);
        PostsAux = GetDado_listaPost_NoInteract(PerfisAux->Postagens,PostIDAux);
        InserirNovoPostRecomendado(PostsAux,recomendacoes);
    }

    for(i=0;i<NumeroDePerfis;i++)free(NumeroDeLikes[i]);
    free(NumeroDeLikes);
    free(Perfis);
    free(NumeroDeFollows);
    return Sucesso;
}
Error SaveAllData(HashTable * table,Recomendacoes * recomendacoes){
    /**
    * Função responsavel por salvar os dados do programa nos aquivos.
    * @return Sucesso caso tudo ocorra de forma correta.
    */
    int i,j,k;
    int aux;
    FILE * ArquivoPerfis;
    FILE * ArquivoPostagens;
    FILE * ArquivoFollows;
    FILE * ArquivoLikes;
    FILE * ArquivoRecomendacoes;
    Item_Post * DadosPostagens;
    Item_Post * PostsREC;
    Item_lista * PerfisREC;
    Item_lista * DadosColuna;
    Item_lista * DadosCurtidas;
    Item_lista * DadosFollows;
    StructFiles DadosEscrita;
    int EscritaPost = sizeof(char) * Tamanho_MAX_post;
    int EscritaNomeUsuario = sizeof(char) * Tamanho_MAX_usuario;

    ArquivoPerfis = fopen(".\\saves\\Perfis.bin","w+b");
    ArquivoPostagens = fopen(".\\saves\\Posts.bin","w+b");
    ArquivoFollows = fopen(".\\saves\\Follows.bin","w+b");
    ArquivoLikes = fopen(".\\saves\\Likes.bin","w+b");
    ArquivoRecomendacoes = fopen(".\\saves\\Recomendacoes.bin","w+b");

    if(ArquivoPerfis == NULL || ArquivoPostagens == NULL || ArquivoFollows == NULL || ArquivoLikes == NULL || ArquivoRecomendacoes == NULL){
        ArquivoCorrompido();
        return Arquivo_corrompido;
    }

    aux = (GetIdPerfil()-1);
    fwrite(&aux,sizeof(int),1,ArquivoPerfis);
    aux = (GetIdPost()-1);
    fwrite(&aux,sizeof(int),1,ArquivoPerfis);

    for(i=0;i<table->NumeroDeColunas;i++){
        DadosColuna = table->DadosTabela[i];
        while(DadosColuna != NULL){
            strcpy(DadosEscrita.Biografia,DadosColuna->DadosItem->Biografia);
            strcpy(DadosEscrita.NomeCompleto,DadosColuna->DadosItem->NomeCompleto);
            strcpy(DadosEscrita.NomeUsuario,DadosColuna->DadosItem->NomeUsuario);
            DadosEscrita.PerfilID = DadosColuna->DadosItem->PerfilID;
            DadosEscrita.NumPosts = DadosColuna->DadosItem->Postagens->NumeroDePostagens;
            DadosEscrita.NumFollows = DadosColuna->DadosItem->PerfilSeguindo->CountFollows;
            fwrite(&DadosEscrita,sizeof(StructFiles),1,ArquivoPerfis);

            DadosPostagens = DadosColuna->DadosItem->Postagens->Primeira;
            for(j=0;j<DadosEscrita.NumPosts;j++){
                fwrite(&DadosPostagens->dadosItem->ID,sizeof(unsigned int),1,ArquivoPostagens);
                fwrite(DadosPostagens->dadosItem->Postagem,EscritaPost,1,ArquivoPostagens);
                fwrite(&DadosPostagens->dadosItem->Curtidas->NumeroDePerfis,sizeof(int),1,ArquivoPostagens);
                for(k=0;k<DadosPostagens->dadosItem->Curtidas->NumeroDeColunas;k++){
                    DadosCurtidas = DadosPostagens->dadosItem->Curtidas->DadosTabela[k];
                    while(DadosCurtidas != NULL){
                        fwrite(DadosCurtidas->DadosItem->NomeUsuario,EscritaNomeUsuario,1,ArquivoLikes);
                        DadosCurtidas = DadosCurtidas->Proximo;
                    }
                }
    
                DadosPostagens = DadosPostagens->Proxima;
            }

            DadosFollows = DadosColuna->DadosItem->PerfilSeguindo->primeira;
            for(j=0;j<DadosEscrita.NumFollows;j++){
                fwrite(DadosFollows->DadosItem->NomeUsuario,EscritaNomeUsuario,1,ArquivoFollows);
                DadosFollows = DadosFollows->Proximo;
            }
            DadosColuna = DadosColuna->Proximo;
        }   
    }
    
    aux = recomendacoes->perfis->CountFollows;
    fwrite(&aux,sizeof(int),1,ArquivoRecomendacoes);
    aux = recomendacoes->posts->NumeroDePostagens;
    fwrite(&aux,sizeof(int),1,ArquivoRecomendacoes);

    PerfisREC = recomendacoes->perfis->primeira;
    for(i=0;i<recomendacoes->perfis->CountFollows;i++){
        fwrite(PerfisREC->DadosItem->NomeUsuario,EscritaNomeUsuario,1,ArquivoRecomendacoes);
        PerfisREC = PerfisREC->Proximo;
    }

    PostsREC = recomendacoes->posts->Primeira;
    for(i=0;i<recomendacoes->posts->NumeroDePostagens;i++){
        fwrite(PostsREC->dadosItem->Owner,EscritaNomeUsuario,1,ArquivoRecomendacoes);
        fwrite(&PostsREC->dadosItem->ID,sizeof(int),1,ArquivoRecomendacoes);
        PostsREC = PostsREC->Proxima;
    }

    return Sucesso;
}