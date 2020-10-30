/**
* @file   funcoes.h
* @brief  Arquivo com as assinaturas de buscas em grafos.
* @author <Erik Neves>
* @date   2020-10-29
*/

#pragma once

#ifndef __BLargura_h__
#define __BLargura_h__

Vertice * BuscaVertice_Largura(Grafo * grafo,DataType DadoProcurado);
Vertice * BuscaVertice_Profundidade(Grafo * grafo,DataType DadoProcurado);

#endif /* __BLargura_h__ */