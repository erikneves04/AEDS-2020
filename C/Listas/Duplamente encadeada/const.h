/**
* @file   const.h
* @brief  Arquivo com a definição de constantes.
* @author <Erik Neves>
* @date   2020-11-07
*/
#pragma once

#ifndef __const_h__
#define __const_h__

// DEFINIÇÃO DE TIPO BOLEANO
typedef unsigned int Boolean;
#define true                (00)
#define false               (!true)

// DEFINIÇÃO DE ERROS
typedef unsigned int Error;
#define Encerrar_loop       (00)
#define Sucesso             (00)
#define Erro_lista_vazia    (01)
#define Dado_nao_encontrado (02)
#define Variavel_de_inicio  (-1)

// DECLARAÇÃO DO TIPO DE DADOS
typedef int DataType;
typedef Boolean (*DataTypeCompare)(DataType,DataType);
typedef Error (*PrintDataType)(DataType);

// STRUCTS DA LISTA
typedef struct Item_lista_t {
    DataType Dado;
    struct Item_lista_t * proximo;
	struct Item_lista_t * anterior;
}Item_lista;
typedef struct lista {
    unsigned int Numero_de_itens;
    Item_lista * primeiro;
    DataTypeCompare ComparaDataType;
    PrintDataType PrintItemDataType;
}Lista;

#endif /* __const_h__ */