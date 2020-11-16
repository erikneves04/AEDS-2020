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
Error RemoverIndexPost_PerfisQCurtiram(Post * postagem);
DataType * DeletarPerfil(HashTable * table, DataType * Alvo);
Error ImprimirDadosColuna(HashTable * table, int coluna);
Error ImprimirTODOSPerfis_HashTable(HashTable * table);
Error ImprimirTODOSCurtidas_HashTable(Post * postagem);
Boolean DadoExistenteHashTable(HashTable * table, DataType * dadosItem);
Error LimparUsersHashTable(HashTable * table);
Error LimparPostHashTable(HashTable * table);
DataType * GetPerfilAlvo_NoInteract(HashTable * table, char NomeProcurado[Tamanho_MAX_usuario]);

#endif /* __HashTable_h__ */