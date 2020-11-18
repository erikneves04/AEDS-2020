/**
* @file   Recomendacoes.h
* @brief  Arquivo com assinaturas das funções de manipulação dos dados recomendados.
* @author <Erik Neves>
* @date   2020-11-17
*/
#pragma once

#ifndef __Recom_h__
#define __Recom_h__

#include "structs.h"
#include "constantes.h"

Error InicializarRecomendados(Recomendacoes * lista);
Error InserirNovoPerfilRecomendado(DataType * New, Recomendacoes * lista);
Error RemoveIndexPerfilRecomedado(DataType * Alvo, Recomendacoes * lista);
Error ImprimirPerfisRecomendados(Recomendacoes * lista);
Error InserirNovoPostRecomendado(Post * New, Recomendacoes * lista);
Error RemoveIndexPostRecomedado(Post * Alvo, Recomendacoes * lista);
Error ImprimirPostsRecomendados(Recomendacoes * lista);
Error LimparRecomendacoes(Recomendacoes * recomendacoes);

#endif /* __Recom_h__ */