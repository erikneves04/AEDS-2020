/**
* @file   warnings.h
* @brief  Arquivo com assinaturas das funções de 
*              avisos da rede social.
* @author <Erik Neves>
* @date   2020-11-13
*/
#pragma once

#ifndef __Warning_h__
#define __Warning_h__
#include "constantes.h"

// ASSINATURAS DAS FUNÇÕES DE AVISOS - INICIO
Error PerfilNaoEncontrado();
Error AtivacaoDefault();
Error PerfilDeletado(unsigned int id);
Error PostNaoEncontrado();
Error ArquivoCorrompido();
// ASSINATURAS DAS FUNÇÕES DE AVISOS - FIM

#endif /* __Warning_h__ */