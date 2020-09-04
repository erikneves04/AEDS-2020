/**
* @file   structs.h
* @brief  TAD com estruturas do programa & identificação de variaveis.
* @author <Erik Neves>
* @date   2020-09-03
*/
#pragma once
#include "constantes.h"

#ifndef __structs_h__
#define __structs_h__

// ESTRUTURA FILA DE PACIENTES
typedef struct paciente_S {
    unsigned int TriagemID;
    char NomePaciente[Tamanho_MAX_nome];
    int HorarioChegada;
    unsigned int Pulseira;
    struct paciente_S * Proximo;
    struct paciente_S * Anterior;
}Paciente;
typedef struct fila_pacientes {
    unsigned int PulseiraID;
    Paciente * Primeiro;
    Paciente * Ultimo;
    unsigned int Numero_de_pacientes;
}FilaPacientes;

// ESTRUTURA FILA DE MEDICOS
typedef struct medico_s {
    char NomeMedico[Tamanho_MAX_nome];
    int EstaTrabalhando;
    int HorarioEntrada;
    int HorarioSaida;
    int Tempo;
    struct medico_s * Proximo;
    struct medico_s * anterior;
}Medico;
typedef struct fila_medicos {
    unsigned int Numero_de_medicos;
    Medico * Primeiro;
}ListaMedico;

// ESTRUTURA DE ATENDIMENTOS
typedef struct atendimento_S {
    unsigned int TriagemID;
    char Paciente[Tamanho_MAX_nome];
    unsigned int Pulseira;
    char Medico[Tamanho_MAX_nome];
    unsigned int InicioAtendimento;
    unsigned int DuracaoAtendimento;
}Atendimento;
typedef struct lista_atendimentos {
    unsigned int Numero_de_atendimentos;
    Atendimento * Primeiro;
}ListaAtendimentos;

#endif /* structs_h */