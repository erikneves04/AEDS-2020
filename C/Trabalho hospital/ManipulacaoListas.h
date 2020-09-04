/**
* @file   ManipulacaoListas.h
* @brief  TAD com assinaturas das funçoes de manipulação das filas.
* @author <Erik Neves>
* @date   2020-09-04
*/
#pragma once

#include "structs.h"

#ifndef __ManiListas_h__
#define __ManiListas_h__

void InicializarlistaMedicos(ListaMedico * fila);
Error Insere_dadolistaMedicos(ListaMedico * fila);
void Remove_dadolistaMedicos(ListaMedico * lista);
Boolean Lista_vaziaMedicos(ListaMedico * lista);
Error Imprimir_listaMedicos(ListaMedico * lista);

#endif /* __ManiListas_h__ */