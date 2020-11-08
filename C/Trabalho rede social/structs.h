/**
* @file   structs.h
* @brief  Arquibo com estruturas do software.
* @author <Erik Neves>
* @date   2020-11-08
*/
#pragma once
#include "constantes.h"

#ifndef __structs_h__
#define __structs_h__

// Dados perfil
typedef struct Perfil_t{
    unsigned int PerfilID;
    char NomeCompleto[Tamanho_MAX_NomeCompleto];
    char NomeUsuario[Tamanho_MAX_usuario];
    char Biografia[Tamanho_MAX_bio];
    struct listaArestra * PerfilSeguindo;
}Perfil;
typedef Perfil DataType;

// Manipulação de seguidores
typedef struct listaArestra {
    unsigned int CountFollows; 
    struct Item_lista_t * primeira;
}Followed_list;
typedef Followed_list Lista;

//Armazenamento via Hash Table
typedef struct Item_lista_t{
    DataType * DadosItem;
    struct Item_lista_t * Anterior;
    struct Item_lista_t * Proximo;
}Item_lista;
typedef struct HashTable{
    unsigned int NumeroDeColunas;
    Item_lista ** DadosTabela;
}HashTable;

#endif /* structs_h */