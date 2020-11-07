/**
* @file   funcoes.h
* @brief  Arquivo com as funçoes de manipulação de grafos.
* @author <Erik Neves>
* @date   2020-10-21
*/
#pragma once

#ifndef __funcoes_h__
#define __funcoes_h__

DataType UserIteract(void);
Lista_arestras * IndexArestras(Grafo * grafo);
Vertice * GetVerticeAlvo(Grafo * grafo);

Boolean ComparaDoisDados(DataType Dado01,DataType Dado02);

int CalculaGrauVertice(Vertice * vertice);
Error InicializarGrafo(Grafo * grafo,DataTypeCompare funcao);
Error InserirItem(Grafo * grafo,Lista_arestras * listaA,DataType valor);
Error RedefinirListaArestras(Grafo * grafo);
Error ImprimirDadosGrafo(Grafo * grafo);
Error ImprimirArestrasVertice(Grafo * grafo);
Error RemoverItem(Grafo * grafo);

#endif /* __funcoes_h__ */