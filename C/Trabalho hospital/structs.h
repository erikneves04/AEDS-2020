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

// ESTRUTURA DE TEMPO PARA BACKUP
typedef struct tempo_s {
    unsigned int Dia;
    unsigned int Mes;
    unsigned int Ano;
    unsigned int Hora;
    unsigned int Minutos;
}DataTime;

// ESTRUTURA FILA DE PACIENTES
typedef struct paciente_S {
    unsigned int TriagemID;
    char NomePaciente[Tamanho_MAX_nome];
    int HorarioChegada;
    unsigned int Pulseira;
    unsigned int NumUpgrades;
    struct paciente_S * Proximo;
    struct paciente_S * Anterior;
}Paciente;
typedef struct fila_pacientes {
    unsigned int PulseiraID;
    Paciente * Primeiro;
    Paciente * Ultimo;
    unsigned int Numero_de_pacientes;
}FilaPacientes;

// ESTRUTURA QUE DA ACESSO A TODAS AS FILAS DE PACIENTES
typedef struct Allpaciente_S {
    FilaPacientes * FilaVermelha;
    FilaPacientes * FilaLaranja;
    FilaPacientes * FilaAmarela;
    FilaPacientes * FilaVerde;
    FilaPacientes * FilaBranca;
}TodasAsFilas;

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
    unsigned int ChegadaAoHospital;
    unsigned int InicioAtendimento;
    unsigned int DuracaoAtendimento;
    struct atendimento_S * Proximo;
    struct atendimento_S * Anterior;
}Atendimento;
typedef struct lista_atendimentos {
    unsigned int Numero_de_atendimentos;
    Atendimento * Primeiro;
}ListaAtendimentos;

#endif /* structs_h */