/**
* @file   funcoes.h
* @brief  Arquivo com as funçoes de manipulação de lista encadeada.
* @author <Erik Neves>
* @date   2020-10-21
*/
#pragma once

#ifndef __funcoes_h__
#define __funcoes_h__

// Manipulação de arestras - INICIO
Error Inicializar_listaArestras(Lista_arestras * lista);
Error Insere_dado_listaArestras(Vertice * vertice,Lista_arestras * lista);
Error Remover_dado_listaArestras(Lista_arestras * lista, Vertice * vertice);
Error ImprimirListaArestras(Lista_arestras * lista);
Boolean Lista_vazia_Arestras(Lista_arestras * lista);
Error Limpar_lista_Arestras(Lista_arestras * lista);
// Manipulação de arestras - FIM

// Manipulação de vertices - INICIO
Error Inicializar_listaVertices(Grafo * lista);
Error Insere_dado_listaVertices(DataType valor,Grafo * grafo,Vertice * Novo_vertice);
Error Remove_dado_listaVertices(Vertice * VerticeAlvo,Grafo * grafo);
Boolean Lista_vazia_Vertices(Grafo * lista);
Error Limpar_lista_Vertices(Grafo * lista);
// Manipulação de vertices - FIM

#endif /* __funcoes_h__ */