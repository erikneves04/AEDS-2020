/**
* @file   interact.h
* @brief  Assinaturas Implementaçao das funçoes de interação com o usuario.
* @author <Erik Neves>
* @date   2020-11-07
*/
#pragma once

#ifndef __Interact_h__
#define __Interact_h__
#include "const.h"

DataType * GetInfosDataType();
char * GetStringAlvo();
Error AvisoPessoaInexistente();
DataType * GetDataTypeAlvo(Lista * lista, char Nome[Tamanho_MAX_string]);

#endif /* __Interact_h__ */