/**
* @file   structs.h
* @brief  Arquivo com estruturas do software.
* @author <Erik Neves>
* @date   2020-11-08
*/
#pragma once

#ifndef __structs_h__
#define __structs_h__

#include "constantes.h"

// Dados perfil
typedef struct Perfil_t{
    unsigned int PerfilID;
    char NomeCompleto[Tamanho_MAX_NomeCompleto];
    char NomeUsuario[Tamanho_MAX_usuario];
    char Biografia[Tamanho_MAX_bio];
    struct listaArestra * PerfilSeguindo;
    struct listaArestra * Seguidores;
    struct ListaPostagens_t * Postagens;
    struct ListaPostagens_t * PostagensCurtidas;
}Perfil;
typedef Perfil DataType;

// Manipulação de seguidores
typedef struct listaArestra{
    unsigned int CountFollows; 
    struct Item_lista_t * primeira;
}Followed_list;
typedef Followed_list Lista;

// Manipulação de postagens
typedef struct post_t{
    unsigned int ID;
    char Postagem[Tamanho_MAX_post];
    char Owner[Tamanho_MAX_usuario];
    struct HashTable * Curtidas;
}Post;
typedef struct item_post{
    struct post_t * dadosItem;
    struct item_post * Anterior;
    struct item_post * Proxima;
}Item_Post;
typedef struct ListaPostagens_t{
    unsigned int NumeroDePostagens;
    Item_Post * Primeira;
}ListaPostagens;

// Armazenamento via Hash Table
typedef struct Item_lista_t{
    DataType * DadosItem;
    struct Item_lista_t * Anterior;
    struct Item_lista_t * Proximo;
}Item_lista;
typedef struct HashTable{
    unsigned int NumeroDeColunas;
    unsigned int NumeroDePerfis;
    Item_lista ** DadosTabela;
}HashTable;

// Armazenamento binário em arquivos
typedef struct EstruturaBin{
    char Biografia[Tamanho_MAX_bio];
    char NomeCompleto[Tamanho_MAX_NomeCompleto];
    char NomeUsuario[Tamanho_MAX_usuario];
    unsigned int PerfilID;
    int NumPosts;
    unsigned int NumFollows;
}StructFiles;

// Recomendações 
typedef struct Recomendacoes_t{
    Lista * perfis;
    ListaPostagens * posts;
}Recomendacoes;

#endif /* structs_h */