/**
* @file   const.h
* @brief  Arquivo com a definição de constantes.
* @author <Erik Neves>
* @date   2020-10-21
*/
#pragma once

#ifndef __const_h__
#define __const_h__

typedef unsigned int Boolean;
#define true                (00)
#define false               (!true)

typedef unsigned int Error;
#define Encerrar_loop       (00)
#define Sucesso             (00)
#define Erro_lista_vazia    (01)
#define Dado_nao_encontrado (02)
#define Variavel_de_inicio  (-1)

typedef int DataType; // Nao utlize strings <Estou resolvendo esse bug>
typedef Boolean (*DataTypeCompare)(DataType,DataType);
#define PrintfType "d"
#define PrintfType_descripition "Inteiro"

typedef struct arestra {
    struct vertice * vertice;
    struct arestra * proximo;
    struct arestra * anterior;
}Arestra;
typedef struct listaArestra {
    int NumeroDeArestras; 
    Arestra * primeira;
    Arestra * ultima;
}Lista_arestras;

typedef struct vertice {
    int ID;
    Lista_arestras * arestras;
    DataType VerticeValor;
    struct vertice * proximo;
    unsigned int auxiliar;
}Vertice;
typedef struct grafo {
    int NumeroDeVertices;
    Vertice * primeiro;
    DataTypeCompare FuncaoDeComparacao;
}Grafo;

#endif /* __const_h__ */