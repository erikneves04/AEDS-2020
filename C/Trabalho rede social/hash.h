/**
* @file   hash.h
* @brief  Arquivo com assinaturas das funções de 
*              manipulação da tabela hash.
* @author <Erik Neves>
* @date   2020-11-05
*/
#pragma once

#ifndef __HashTable_h__
#define __HashTable_h__
#include "constantes.h"
#include "structs.h"

Error InicializarHashTable(HashTable * table);
Error InserirHashTable(HashTable * table, DataType * dadosItem);
DataType * RemoverDadoHashTable(HashTable * table, char nome[Tamanho_MAX_usuario]);
Error ImprimirDadosColuna(HashTable * table, int coluna);

#endif /* __HashTable_h__ */