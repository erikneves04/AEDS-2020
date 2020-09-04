/**
* @file   structs.h
* @brief  TAD com assinaturas das funçoes de manipulação das filas.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once

#ifndef __ManiFilas_h__
#define __ManiFilas_h__

// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - INICIO
void InicializarFilaPacientes(FilaPacientes * fila,unsigned int ID);
Error Insere_dadoFilaPacientes(FilaPacientes * fila,int ID);
Paciente * Remove_dadoFilaPacientes(FilaPacientes * fila);
Boolean Fila_vaziaPacientes(FilaPacientes * fila);
Error Imprimir_FilaPacientes(FilaPacientes * fila);
Error Limpar_FilaPacientes(FilaPacientes * fila);
Error Limpar_memoriaPaciente(Paciente * Paciente_alvo);
// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - FINAL


// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - INICIO
void InicializarFilaMedicos();
Error Insere_dadoFilaMedicos();
void Remove_dadoFilaMedicos();
Boolean Lista_vaziaFilaMedicos();
Error Imprimir_listaFilaMedicos();
Error Limpar_listaFilaMedicos();
// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - FINAL

// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DAS TRIAGENS - INICIO
// ASSINATURAS DAS FUNÇÕES DE MANIPULAÇÃO DAS FILAS DAS TRIAGENS - FINAL


#endif /* __ManiFilas_h__ */