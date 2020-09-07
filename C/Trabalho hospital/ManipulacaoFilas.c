/*
 * @file   ManipulacaoFilas.c
 * @brief  Arquivo com funções de manipulação das filas.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"
#include "ManipulacaoListas.h"
#include "Variaveis&interacoes.h"

// IMPLEMENTAÇÃO FUNÇÃO DE IDENTIFICAÇÃO DE TODAS AS FILAS - INICIO
Error InicializarStructTodasAsFilas(TodasAsFilas * filas,FilaPacientes * FilaVermelha,FilaPacientes * FilaLaranja,FilaPacientes * FilaAmarela,FilaPacientes * FilaVerde,FilaPacientes * FilaBranca){
    filas->FilaVermelha = FilaVermelha;
    filas->FilaLaranja = FilaLaranja;
    filas->FilaAmarela = FilaAmarela;
    filas->FilaVerde = FilaVerde;
    filas->FilaBranca = FilaBranca;

    return Sucesso;
}
Error Limpar_memoriaStructTodasAsFilas(TodasAsFilas * filas){
    if(filas != NULL) free(filas);
    return Sucesso;
}
// IMPLEMENTAÇÃO FUNÇÃO DE IDENTIFICAÇÃO DE TODAS AS FILAS - FIM

// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - INICIO
void InicializarFilaPacientes(FilaPacientes * fila,unsigned int ID){
    fila->Numero_de_pacientes = 0;
    fila->Primeiro = NULL;
    fila->Ultimo = NULL;
    fila->PulseiraID = ID;
}
Error Insere_dadoFilaPacientes(FilaPacientes * fila, int ID,ListaMedico * listaMedicos){
    Paciente * Novo_paciente = (Paciente*)malloc(sizeof(Paciente));

    Get_InformacoesPaciente(Novo_paciente);
    Novo_paciente->Pulseira = fila->PulseiraID;
    Novo_paciente->TriagemID = ID;
    Novo_paciente->HorarioChegada = Get_HorarioAtual(listaMedicos);
    Novo_paciente->NumUpgrades = 1;

    Novo_paciente->Proximo = fila->Ultimo;
    Novo_paciente->Anterior = NULL;
    if(fila->Ultimo == NULL){
        fila->Primeiro = Novo_paciente;
        fila->Ultimo = Novo_paciente;
    }else{
        fila->Ultimo->Anterior = Novo_paciente;
        fila->Ultimo = Novo_paciente;
    }
    fila->Numero_de_pacientes++;

    return Sucesso;
}
static Error Insere_dadoFilaPacientesStatic(FilaPacientes * fila,Paciente * Novo_paciente){
    Novo_paciente->Proximo = fila->Ultimo;
    Novo_paciente->Anterior = NULL;
    if(fila->Ultimo == NULL){
        fila->Primeiro = Novo_paciente;
        fila->Ultimo = Novo_paciente;
    }else{
        fila->Ultimo->Anterior = Novo_paciente;
        fila->Ultimo = Novo_paciente;
    }
    fila->Numero_de_pacientes++;

    return Sucesso;
}
Paciente * Remove_dadoFilaPacientes(FilaPacientes * fila){
    Paciente * Primeiro_paciente = fila->Primeiro;
    
    fila->Primeiro = Primeiro_paciente->Anterior;
    fila->Numero_de_pacientes--;
    if(fila->Primeiro != NULL){
        fila->Primeiro->Proximo = NULL;
    }
    if(fila->Numero_de_pacientes == 0){
        fila->Ultimo = NULL;
    }

    Primeiro_paciente->Anterior = NULL;
    Primeiro_paciente->Proximo = NULL;

    return Primeiro_paciente;
}
Boolean Fila_vaziaPacientes(FilaPacientes * fila){
    return (fila->Numero_de_pacientes == 0 && fila->Primeiro == NULL && fila->Ultimo == NULL) ? true : false;
}
Error Imprimir_FilaPacientes(FilaPacientes * fila){
    Paciente * Pacientes = fila->Primeiro;
    int i;
    char StringPulseira[10];

    switch (fila->PulseiraID){
        case 00:
            strcpy(StringPulseira,"Default");
        break;
        case 01:
            strcpy(StringPulseira,"Branca");
        break;
        case 02:
            strcpy(StringPulseira,"Verde");
        break;
        case 03:
            strcpy(StringPulseira,"Amarela");
        break;
        case 04:
            strcpy(StringPulseira,"Laranja");
        break;
        case 05:
            strcpy(StringPulseira,"Vermelha");
        break;
    }

    if(Fila_vaziaPacientes(fila) == false){
        printf("\n  +------------------------------------------------------+\n");
        printf("  | Imprimindo os dados da fila de pacientes( %-8s ) |\n",StringPulseira);
        printf("  +------------------------------------------------------+\n\n");

        printf("Nome                     PulseiraID     TriagemID     Entrada\n");
        for(i=0;i<fila->Numero_de_pacientes;i++){
            printf("%-25s %-10s      %.4d         %.4d\n",Pacientes->NomePaciente,StringPulseira,Pacientes->TriagemID,Pacientes->HorarioChegada);
            Pacientes = Pacientes->Anterior;
        }   
        printf("\n");
    }else{
        printf("\n+------------------------------------+\n");
        printf("| Esta lista de pacientes esta vazia |\n");
        printf("+------------------------------------+\n\n");

        return Erro_fila_vazia;
    }

    return Sucesso;
}
Error Limpar_FilaPacientes(FilaPacientes * fila){
    int i;
    Paciente * pacientes = fila->Primeiro;
    Paciente * Proximo_paciente = NULL;

    for(i=0;i<fila->Numero_de_pacientes;i++){
        Proximo_paciente = pacientes->Proximo;
        free(pacientes);
        pacientes = Proximo_paciente;
    }

    fila->Numero_de_pacientes = 0;
    fila->Primeiro = NULL;
    fila->Ultimo = NULL;
    free(fila);
    return Sucesso;
}
Error Limpar_memoriaPaciente(Paciente * Paciente_alvo){
    if(Paciente_alvo == NULL){
        return Paciente_inexistente;
    }
    free(Paciente_alvo);
    return Sucesso;
}
Error Update_FilaPaciente(TodasAsFilas * Filas,ListaMedico * ListaMedicos){
    int i;
    Paciente * Pacientes;
    Paciente * PacienteParaUpgrade;

    Pacientes = Filas->FilaVerde->Primeiro;
    for(i=0;i<Filas->FilaVerde->Numero_de_pacientes;i++){
        printf("Tentou\n");
        if((Get_HorarioAtual(ListaMedicos) - Pacientes->HorarioChegada) >= (60 * Pacientes->NumUpgrades)){
            printf("%d\n",Pacientes->NumUpgrades);
            PacienteParaUpgrade = Remove_dadoFilaPacientes(Filas->FilaVerde);
            PacienteParaUpgrade->NumUpgrades++;
            PacienteParaUpgrade->Pulseira = Verde;
            Insere_dadoFilaPacientesStatic(Filas->FilaAmarela,PacienteParaUpgrade);
        }
    }

    Pacientes = Filas->FilaAmarela->Primeiro;
    for(i=0;i<Filas->FilaAmarela->Numero_de_pacientes;i++){
        if((Get_HorarioAtual(ListaMedicos) - Pacientes->HorarioChegada) > (60 * Pacientes->NumUpgrades)){
            PacienteParaUpgrade = Remove_dadoFilaPacientes(Filas->FilaAmarela);  
            PacienteParaUpgrade->NumUpgrades++;      
            PacienteParaUpgrade->Pulseira = Amarela;
            Insere_dadoFilaPacientesStatic(Filas->FilaLaranja,PacienteParaUpgrade);
        }
    }

    Pacientes = Filas->FilaLaranja->Primeiro;
    for(i=0;i<Filas->FilaLaranja->Numero_de_pacientes;i++){
        if((Get_HorarioAtual(ListaMedicos) - Pacientes->HorarioChegada) > (60 * Pacientes->NumUpgrades)){
            PacienteParaUpgrade = Remove_dadoFilaPacientes(Filas->FilaLaranja);
            PacienteParaUpgrade->NumUpgrades++;
            PacienteParaUpgrade->Pulseira = Laranja;
            Insere_dadoFilaPacientesStatic(Filas->FilaVermelha,PacienteParaUpgrade);
        }
    }

    return Sucesso;
}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - FIM