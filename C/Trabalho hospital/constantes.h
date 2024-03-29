/**
* @file   constantes.h
* @brief  Arquivo com a definição de constantes e valores fixos do software.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once

#ifndef __const_h__
#define __const_h__

// DEFINIÇÃO DE BOOLEANOS
typedef unsigned int Boolean;
#define true                 (00)
#define false                (!true)

//DEFINIÇÃO DE CONSTANTES
#define Encerrar_loop        (00)
#define Sucesso              (00)
#define Variavel_de_inicio   (-1)
#define Tamanho_MAX_nome     (26)

// DEFINIÇÃO DE ERROS
typedef unsigned int Error;
#define Erro_fila_vazia      (01)
#define Erro_lista_vazia     (01)
#define Dado_nao_encontrado  (02)
#define Paciente_inexistente (03)
#define Acao_cancelada       (04)
#define Medico_inexistente   (05)
#define Arquivo_corrompido   (06)

// DEFINIÇÃO DAS PULSEIRAS
#define Vermelha             (05)
#define Laranja              (04)
#define Amarela              (03)
#define Verde                (02)
#define Branca               (01)
#define Default              (00)

// DEFINIÇÃO DO ESTADO DO MEDICO
#define Em_servico           (00)
#define Fora_de_servico      (01)

#endif /* __const_h__ */