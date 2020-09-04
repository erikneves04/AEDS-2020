/**
* @file   Interacoes.h
* @brief  TAD interações com o usuario.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once

#include "structs.h"

#ifndef __Interact_h__
#define __Interact_h__

Error Get_InformacoesPaciente(FilaPacientes * fila,Paciente * Novo_paciente);
int Get_TriagemIDDisponivel(FilaPacientes * Fila_01,FilaPacientes * Fila_02,FilaPacientes * Fila_03,FilaPacientes * Fila_04,FilaPacientes * Fila_05);

#endif /* Interact_h */