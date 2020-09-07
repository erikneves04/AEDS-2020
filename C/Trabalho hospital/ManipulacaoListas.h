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

// ASSINATIRAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - INICIO
void InicializarlistaMedicos(ListaMedico * lista);
Error Insere_dadolistaMedicos(ListaMedico * lista);
void Remove_dadolistaMedicos(ListaMedico * lista);
Boolean Lista_vaziaMedicos(ListaMedico * lista);
Error Imprimir_listaMedicos(ListaMedico * lista);
Error Limpar_listaMedicos(ListaMedico * lista);
Error Update_TempoMedico(ListaMedico * lista,char * Nome_medico,int TempoUltimoAtendimento);
// ASSINATIRAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - FIM

// ASSINATIRAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - INICIO
void InicializarlistaAtendimentos(ListaAtendimentos * lista);
Error Insere_dadolistaAtendimentos(ListaAtendimentos * listaAtendimentos, FilaPacientes * fila,ListaMedico * ListaMedicos);
void Remove_dadolistaAtendimentos(ListaAtendimentos * lista);
Boolean Lista_vaziaAtendimentos(ListaAtendimentos * lista);
Error Imprimir_listaAtendimentos(ListaAtendimentos * lista);
Error Limpar_listaAtendimentos(ListaAtendimentos * lista);
// ASSINATIRAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - FIM

#endif /* __ManiListas_h__ */