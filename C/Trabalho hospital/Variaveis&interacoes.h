/**
* @file   Interacoes.h
* @brief  Arquivo com assinaturas das funções de variaveis de 
*                controle & interações com o usuario.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once

#ifndef __Interact_h__
#define __Interact_h__

// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int Get_TriagemIDDisponivel();
int Get_HorarioAtual(ListaMedico * fila);
// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
FilaPacientes * GetUserFila(TodasAsFilas * filas);
Error Get_InformacoesMedico(Medico * Novo_medico);
Error Get_InformacoesPaciente(Paciente * Novo_paciente);
Error Get_MedicoAlvo(ListaMedico * lista, char * Nome);
Error Get_InformacoesAtendimento(Atendimento * Novo_atendimento,ListaMedico * ListaMedicos);
Error PrintErrorMedicoInvalido();
Error PrintErrorFilasVazias();
Error PrintErrorListaMedicosVazia();
FilaPacientes * Get_FilaPrioritaria(TodasAsFilas * Filas);
// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM

#endif /* Interact_h */