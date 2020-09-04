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

// PADRONIZAÇÃO DE HORARIO
struct Horario_s {
    unsigned int Hora;
    unsigned int Minutos;
};

// ESTRUTURA FILA DE PACIENTES
typedef struct paciente_S {
    unsigned int TriagemID;
    char NomePaciente[Tamanho_MAX_nome];
    struct Horario_s HorarioChegada;
    unsigned int Pulseira;
    Paciente * Proximo;
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
    struct Horario_s HorarioEntrada;
    struct Horario_s HorarioSaida;
    Medico * Proximo;
}Medico;
typedef struct fila_medicos {
    Medico * Primeiro;
    unsigned int Numero_de_medicos;
}FilaMedicos;

#endif /* structs_h */