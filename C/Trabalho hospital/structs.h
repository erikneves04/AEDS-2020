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
typedef struct Horario_s {
    int Hora;
    int Minutos;
}Horario;

// ESTRUTURA FILA DE PACIENTES
typedef struct paciente_S {
    unsigned int TriagemID;
    char NomePaciente[Tamanho_MAX_nome];
    struct Horario_s * HorarioChegada;
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
    struct Horario_s HorarioEntrada;
    struct Horario_s HorarioSaida;
    struct medico_s * Proximo;
}Medico;
typedef struct fila_medicos {
    Medico * Primeiro;
    unsigned int Numero_de_medicos;
}FilaMedicos;

#endif /* structs_h */