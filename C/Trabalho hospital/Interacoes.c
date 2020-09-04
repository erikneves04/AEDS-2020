/*
 * @file   Interacoes.c
 * @brief  Arquivo com implementação das funções para interagir com o usuario.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"

int Get_TriagemIDDisponivel(FilaPacientes * Fila_01,FilaPacientes * Fila_02,FilaPacientes * Fila_03,FilaPacientes * Fila_04,FilaPacientes * Fila_05){
    int ID;
    int Total_IDS;

    Total_IDS = Fila_01->Numero_de_pacientes + Fila_02->Numero_de_pacientes + Fila_03->Numero_de_pacientes + Fila_04->Numero_de_pacientes + Fila_05->Numero_de_pacientes;
    ID = Total_IDS + 1;

    return ID;
}

Error Get_InformacoesPaciente(FilaPacientes * fila,Paciente * Novo_paciente){

    printf("Digite o nome do paciente(Max.:25): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s",Novo_paciente->NomePaciente);
    setbuf(stdin,NULL);

    //printf("Digite o horario da entrada do paciente(hh/mm): ");
    //scanf("%d/%d", Novo_paciente->HorarioChegada->Hora,Novo_paciente->HorarioChegada->Minutos);

    return Sucesso;

}