/**
* @file   funcoes.h
* @brief  Arquivo com as assinaturas das funções de manipulação de lista encadeada.
* @author <Erik Neves>
* @date   2020-11-07
*/
#pragma once

#ifndef __funcoes_h__
#define __funcoes_h__
#include "structs.h"

// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (DATATYPE) - INICIO
Error Inicializar_lista(Lista * lista);
Error Insere_dado(DataType * Valor,Lista * lista);
Error Remove_dado(DataType * Valor,Lista * lista);
Boolean Lista_vazia(Lista * lista);
Error Imprimir_lista(Lista * lista);
Error Limpar_lista(Lista * lista);
Boolean DadoContido_lista(Lista * lista, DataType * DadoAlvo);
// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (DATATYPE) - INICIO


// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (POST) - INICIO
Error Inicializar_listaPost(ListaPostagens * lista);
Error Insere_dadoPost(Post * Valor,ListaPostagens * lista);
Error Remove_dadoPost(Post * Valor,ListaPostagens * lista);
Boolean Lista_vaziaPost(ListaPostagens * lista);
Error Imprimir_listaPost(ListaPostagens * lista,DataType * Visual);
Error Limpar_listaPost(ListaPostagens * lista);
Boolean DadoContido_listaPost(ListaPostagens * lista, unsigned int IDDadoAlvo);
// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (POST) - INICIO

#endif /* __funcoes_h__ */