/**
* @file   BuscaBinaria.h
 * @brief  Assinaturas das funçoes de manipulaçao de 
 *            listas ordenadas e buscas binarias.
* @author <Erik Neves>
* @date   2020-11-05
*/
#pragma once

#ifndef __buscasBinarias_h__
#define __buscasBinarias_h__
#include "const.h"

Error InsereOrdenado(Lista * lista, DataType * dadosItem);
Error ImprimirDadosLista(Lista * lista);
DataType * BuscaDadoItem(Lista * lista,char search[Tamanho_MAX_string]);
Error ImprimirDadosPessoa(DataType * dados);

#endif /* __buscasBinarias_h__ */