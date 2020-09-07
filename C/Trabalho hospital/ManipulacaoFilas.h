/**
* @file   structs.h
* @brief  TAD com assinaturas das funçoes de manipulação das filas.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once

#ifndef __ManiFilas_h__
#define __ManiFilas_h__

// ASSINATURAS DAS FUNÇÕES DE IDENTIFICAÇÕES DE TODAS AS FILAS - INICIO
Error InicializarStructTodasAsFilas(TodasAsFilas * filas,FilaPacientes * FilaVermelha,FilaPacientes * FilaLaranja,FilaPacientes * FilaAmarela,FilaPacientes * FilaVerde,FilaPacientes * FilaBranca);
// ASSINATURAS DAS FUNÇÕES DE IDENTIFICAÇÕES DE TODAS AS FILAS - FIM

// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - INICIO
void InicializarFilaPacientes(FilaPacientes * fila,unsigned int ID);
Error Insere_dadoFilaPacientes(FilaPacientes * fila,int ID,ListaMedico * listaMedicos);
Paciente * Remove_dadoFilaPacientes(FilaPacientes * fila);
Boolean Fila_vaziaPacientes(FilaPacientes * fila);
Error Imprimir_FilaPacientes(FilaPacientes * fila);
Error Limpar_FilaPacientes(FilaPacientes * fila);
Error Limpar_memoriaPaciente(Paciente * Paciente_alvo);
// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - FIM

#endif /* __ManiFilas_h__ */