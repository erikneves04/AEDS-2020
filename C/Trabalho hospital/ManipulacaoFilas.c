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
#include "Interacoes.h"
#include "structs.h"


// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - INICIO
void InicializarFilaPacientes(FilaPacientes * fila,unsigned int ID){
    fila->Numero_de_pacientes = 0;
    fila->Primeiro = NULL;
    fila->Ultimo = NULL;
    fila->PulseiraID = ID;
}
Error Insere_dadoFilaPacientes(FilaPacientes * fila, int ID){
    Paciente * Novo_paciente = (Paciente*)malloc(sizeof(Paciente));

    Get_InformacoesPaciente(fila,Novo_paciente);
    Novo_paciente->Pulseira = fila->PulseiraID;
    Novo_paciente->TriagemID = ID;

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

    Primeiro_paciente->Anterior = NULL;
    Primeiro_paciente->Proximo = NULL;
    
    fila->Primeiro = Primeiro_paciente->Anterior;
    fila->Primeiro->Proximo = NULL;
    fila->Numero_de_pacientes--;

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
            printf("%-25s %-10s      %.4d         %.2d:%.2d\n",Pacientes->NomePaciente,StringPulseira,Pacientes->TriagemID,0,0);
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
Error Limpar_FilaPacientes(){
}
Error Limpar_memoriaPaciente(Paciente * Paciente_alvo){
    if(Paciente_alvo == NULL){
        return Paciente_inexistente;
    }
    free(Paciente_alvo);
    return Sucesso;
}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - FINAL





// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - INICIO
void InicializarFilaMedicos(){}
Error Insere_dadoFilaMedicos(){}
void Remove_dadoFilaMedicos(){}
Boolean Lista_vaziaFilaMedicos(){}
Error Imprimir_listaFilaMedicos(){}
Error Limpar_listaFilaMedicos(){}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - FINAL