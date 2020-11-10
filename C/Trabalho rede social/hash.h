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

Item_lista * GetColuna(HashTable * table,int ColunaID);
Error InicializarHashTable(HashTable * table);
Error InserirHashTable(HashTable * table, DataType * dadosItem);
DataType * RemoverDadoHashTable(HashTable * table, char nome[Tamanho_MAX_usuario]);
Error DeletarPerfil(HashTable * table);
Error ImprimirDadosColuna(HashTable * table, int coluna);
Error ImprimirTODOSPerfis_HashTable(HashTable * table);
Boolean DadoExistenteHashTable(HashTable * table, DataType * dadosItem);

#endif /* __HashTable_h__ */