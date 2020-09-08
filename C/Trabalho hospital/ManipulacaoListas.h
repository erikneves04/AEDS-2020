/**
* @file   ManipulacaoListas.h
* @brief  Arquivo com assinaturas das funções de manipulação das listas.
* @author <Erik Neves>
* @date   2020-09-04
*/
#pragma once

#ifndef __ManiListas_h__
#define __ManiListas_h__

// ASSINATURAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - INICIO
Error InicializarlistaMedicos(ListaMedico * lista);
Error Insere_dadolistaMedicos(ListaMedico * lista);
Error Remove_dadolistaMedicos(ListaMedico * lista);
Boolean Lista_vaziaMedicos(ListaMedico * lista);
Error Imprimir_listaMedicos(ListaMedico * lista);
Error Limpar_listaMedicos(ListaMedico * lista);
Error Update_TempoMedico(ListaMedico * lista,char * Nome_medico,int TempoUltimoAtendimento);
Error Update_PlantaoMedico(ListaMedico * lista);
// ASSINATURAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - FIM


// ASSINATURAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - INICIO
Error InicializarlistaAtendimentos(ListaAtendimentos * lista);
Error Insere_dadolistaAtendimentos(ListaAtendimentos * listaAtendimentos, FilaPacientes * fila,ListaMedico * ListaMedicos);
Boolean Lista_vaziaAtendimentos(ListaAtendimentos * lista);
Error Imprimir_listaAtendimentos(ListaAtendimentos * lista);
Error Limpar_listaAtendimentos(ListaAtendimentos * lista);
// ASSINATURAS FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - FIM

#endif /* __ManiListas_h__ */