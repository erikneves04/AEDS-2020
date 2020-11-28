/**
* @file   Buscas.h
* @brief  Arquivo com as assinaturas das funções para buscar dados no software.
* @author <Erik Neves>
* @date   2020-11-18
*/

#pragma once

#ifndef __search_
#define __search_

#include "structs.h"
#include "constantes.h"

Error * BuscarDeSeguidores_Largura(DataType * Inicial,HashTable * table);

#endif /* __search_ */