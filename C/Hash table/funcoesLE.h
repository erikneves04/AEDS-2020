/**
* @file   funcoesLE.h
* @brief  Arquivo com as funçoes de manipulação de listas.
* @author <Erik Neves>
* @date   2020-10-21
*/
#pragma once
#include "const.h"

#ifndef __funcoes_h__
#define __funcoes_h__

Error InicializarLista(Lista * lista);
Error InserirItemLista(Lista * lista, DataType * dadosItem);
Error RemoverItemLista(Lista * lista,DataType * dadosItem);
DataType * GetItemLista(Lista * lista, unsigned int posicao);
Boolean EstadoLista(Lista * lista);
Error LimparLista(Lista * lista);

#endif /* __funcoes_h__ */