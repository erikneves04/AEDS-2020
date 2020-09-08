/*
 * @file   MakeBackup.c
 * @brief  Arquivo com a implementação da função para criação de 
 *                 backups das execuções do codigo
 * @author <Erik Neves>
 * @date   2020-09-03
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constantes.h"
#include "structs.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


Error CriaTXTBackup(ListaAtendimentos * listaAtendimentos){
    /*
    * Essa função é responsavel pela criação do backup em formato de 
    *       texto dos atendimentos realizados no codigo.
    *  @return Sucesso caso tudo ocorra certo
    */

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

    if(listaAtendimentos->Numero_de_atendimentos == 0)return Erro_lista_vazia;

    (void)sprintf(NomeArquivo,"%.2d_%.2d - %.2d_%.2d_%.4d.txt",DadosTempo->Hora,DadosTempo->Minutos,DadosTempo->Dia,DadosTempo->Mes,DadosTempo->Ano);

    arquivo = fopen(NomeArquivo,"w+");
    if(!arquivo)return Arquivo_corrompido;

    fprintf(arquivo,"+------------------------------------------------------------------------------------------------------------+\n");
    fprintf(arquivo,"|                   DADOS DA EXECUCAO DO SOFTWARE DO HOSPITAL ISSAC NEWTON %.2d:%.2d - %.2d/%.2d/%.4d                |\n",DadosTempo->Hora,DadosTempo->Minutos,DadosTempo->Dia,DadosTempo->Mes,DadosTempo->Ano);
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

    printf("+-----------------------------------------------+\n");
    printf("| Um backup dos dados desta execucao foi criado |\n");
    printf("|  e pode ser acessado no diretorio '/Backups'  |\n");
    printf("+-----------------------------------------------+\n\n");

    system("move *.txt Backups\\");

    return Sucesso;
}