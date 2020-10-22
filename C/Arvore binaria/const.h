/**
* @file   const.h
* @brief  Arquivo com a definição de constantes binaria (RAIZ - ESQUERDA - DIREITA).
* @author <Erik Neves>
* @date   2020-09-10
*/
#pragma once

#ifndef __const_h__
#define __const_h__

// DEFINIÇÃO DO TIPO DOS DADOS
typedef int DataType;
#define PrintfType "d"
#define PrintfType_descripition "Inteiro"

// DEFINIÇÃO DAS ESTRUTURAS
typedef struct itemArvore_S {
    DataType Dado;
    struct itemArvore_S * Direita;
    struct itemArvore_S * Esquerda;
}Arvore;


// DEFINIÇÃO DE BOOLEANO
typedef unsigned int Boolean;
#define true                (00)
#define false               (!true)

// DEFINIÇÃO DE ERROS
typedef unsigned int Error;
#define Encerrar_loop       (00)
#define Sucesso             (00)
#define Erro_arvore_vazia   (03)
#define Erro_dado_repetido  (04)
#define Variavel_de_inicio  (-1)

#endif /* __const_h__ */