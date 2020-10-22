/**
* @file   funcoes.h
* @brief  Arquivo com as funçoes de manipulação de grafos.
* @author <Erik Neves>
* @date   2020-10-21
*/
#pragma once

#ifndef __funcoes_h__
#define __funcoes_h__

Error InicializarGrafo(Grafo * grafo);
Error InserirItem(Grafo * grafo);
Error RedefinirListaArestras(Grafo * grafo);
Error ImprimirDadosGrafo(Grafo * grafo);
Error ImprimirArestrasVertice(Grafo * grafo);
Error RemoverItem(Grafo * grafo);

#endif /* __funcoes_h__ */