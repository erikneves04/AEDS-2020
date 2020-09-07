/*
 * @file   MakeBackup.c
 * @brief  Arquivo para a criação de backups das execuções do codigo
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constantes.h"
#include "structs.h"

Error CriaTXTBackup(ListaAtendimentos * listaAtendimentos){

    struct tm * DataTimeH;
    time_t segundos;
    FILE * arquivo;
    char NomeArquivo[16];
    char StringPulseira[10];
    char StringAux[100];
    DataTime * DadosTempo = (DataTime*)malloc(sizeof(DataTime));
    int i;
    Atendimento * atendimentos = listaAtendimentos->Primeiro;

    time(&segundos);
    DataTimeH = localtime(&segundos);

    DadosTempo->Dia = DataTimeH->tm_mday;
    DadosTempo->Mes = (DataTimeH->tm_mon + 1);
    DadosTempo->Ano = (DataTimeH->tm_year + 1900);
    DadosTempo->Hora = DataTimeH->tm_hour;
    DadosTempo->Minutos = DataTimeH->tm_min;

    (void)sprintf(NomeArquivo,"%.2d_%.2d - %.2d_%.2d_%.4d.txt",DadosTempo->Hora,DadosTempo->Minutos,DadosTempo->Dia,DadosTempo->Mes,DadosTempo->Ano);

    arquivo = fopen(NomeArquivo,"w+");
    if(!arquivo)printf("error");
    fprintf(arquivo,"+------------------------------------------------------------------------------------------------------------+\n");
    fprintf(arquivo,"|                   DADOS DA EXECUCAO DO SOFTARE DO HOSPITAL ISSAC NEWTON %.2d:%.2d - %.2d/%.2d/%.4d                 |\n",DadosTempo->Hora,DadosTempo->Minutos,DadosTempo->Dia,DadosTempo->Mes,DadosTempo->Ano);
    fprintf(arquivo,"+------------------------------------------------------------------------------------------------------------+\n");
    sprintf(StringAux,"|%-25s | %.9s | %-10s | %.7s | %.7s | %.7s | %-25s|\n","Nome paciente:","TriagemID"," Pulseira","Inicio ","Duracao","Chegada","Nome medico:");
    fprintf(arquivo,StringAux);
    fprintf(arquivo,"+------------------------------------------------------------------------------------------------------------+\n");
    for(i=0;i<listaAtendimentos->Numero_de_atendimentos;i++){
        switch (atendimentos->Pulseira){
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
                default:
                    strcpy(StringPulseira,"Default");
                break;
            }
        sprintf(StringAux,"|%-25s | %.9d |  %-10s| %.6d  | %.7d | %.7d | %-25s|\n",atendimentos->Paciente,atendimentos->TriagemID,StringPulseira,atendimentos->InicioAtendimento,(atendimentos->DuracaoAtendimento + atendimentos->InicioAtendimento),atendimentos->ChegadaAoHospital,atendimentos->Medico);
        fprintf(arquivo,StringAux);
        atendimentos = atendimentos->Proximo;
    }
    fprintf(arquivo,"+------------------------------------------------------------------------------------------------------------+\n");
    fclose(arquivo);
    system("move *.txt Backups\\");

    return Sucesso;
}