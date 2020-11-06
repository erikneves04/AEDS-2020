/**
* @file   interact.h
 * @brief  Assinaturas Implementaçao das funçoes de interação com o usuario.
* @author <Erik Neves>
* @date   2020-11-05
*/
#pragma once

#ifndef __Interact_h__
#define __Interact_h__
#include "const.h"

DataType * GetInfosDataType();
char * GetStringAlvo();
Error AvisoPessoaInexistente();
int GetColunaAlvo(HashTable * table);

#endif /* __Interact_h__ */