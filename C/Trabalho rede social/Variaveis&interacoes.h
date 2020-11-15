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
int GetIdPerfil();
int GetIdPost();
// ASSINATURAS DAS FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// ASSINATURAS DAS FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
DataType * AtivarPerfil(HashTable * table,DataType * PerfilAtual);
DataType * GetInformacoesCriarPerfil(HashTable * table);
DataType * GetPerfilAlvo(HashTable * table);
Post * GetPostAlvo(ListaPostagens * lista);
Error AlterarInformacoesPerfil(HashTable * table,DataType * DadoAlvo);
Error Alterar_listaFollows(HashTable * table, DataType * perfil);
Error RealizarPostagem(HashTable * table, DataType * perfil);
Error DeletarPostagem(HashTable * table, DataType * perfil);
Error Alterar_listaPosts(HashTable * table, DataType * perfil);
Error NavegarEmUmPerfil(HashTable * table,DataType * perfil, DataType * PerfilInicial);
// ASSINATURAS DAS FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM

#endif /* Interact_h */