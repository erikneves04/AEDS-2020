/**
* @file   Variaveis&interacoes.h
* @brief  Arquivo com assinaturas das funções de variaveis de 
*                controle & interações com o usuario.
* @author <Erik Neves>
* @date   2020-11-08
*/
#pragma once

#ifndef __Interact_h__
#define __Interact_h__
#include "structs.h"

// ASSINATURAS DAS FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int GetColunaPerfil(char * string);
// ASSINATURAS DAS FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// ASSINATURAS DAS FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
DataType * GetInformacoesCriarPerfil(HashTable * table);
int GetColunaAlvo(HashTable * table);
DataType * GetPerfilAlvo(HashTable * table);
Error AlterarInformacoesPerfil(HashTable * table,DataType * DadoAlvo);
Error PerfilNaoEncontrado();
// ASSINATURAS DAS FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM

#endif /* Interact_h */