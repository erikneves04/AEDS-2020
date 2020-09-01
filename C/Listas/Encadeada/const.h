/**
* @file   const.h
* @brief  Arquivo com a definição de constantes.
* @author <Erik Neves>
* @date   2020-08-31
*/
#pragma once

#ifndef __const_h__
#define __const_h__

typedef unsigned int Boolean;
#define true                (00)
#define false               (!true)

typedef unsigned int Error;
#define Sucesso             (00)
#define Erro_lista_vazia    (01)
#define Dado_nao_encontrado (02)
#define Variavel_de_inicio  (-1)

typedef struct item_list {
    int Dado;
    struct item_list * proximo;
}Item_lista;
typedef struct lista {
    int Numero_de_itens;
    Item_lista * primeiro;
}Lista;

#endif /* __const_h__ */