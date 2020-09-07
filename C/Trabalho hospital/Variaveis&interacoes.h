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

Error Get_InformacoesPaciente(Paciente * Novo_paciente);
int Get_TriagemIDDisponivel();
FilaPacientes * GetUserFila(TodasAsFilas * filas);
Error Get_InformacoesMedico(Medico * Novo_medico);
int Get_HorarioAtual(ListaMedico * fila);
Error Get_MedicoAlvo(ListaMedico * lista, char * Nome);
Error Get_InformacoesAtendimento(Atendimento * Novo_atendimento,ListaMedico * ListaMedicos);
Error PrintErrorMedicoInvalido();
FilaPacientes * Get_FilaPrioritaria(TodasAsFilas * Filas);

#endif /* Interact_h */