/*
 * @file   Interacoes.c
 * @brief  Arquivo com implementação das funções para interagir com o usuario.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

    printf("\n");
    return Sucesso;

}

FilaPacientes * GetFilaTriagem(FilaPacientes * FilaVermelha,FilaPacientes * FilaLaranja,FilaPacientes * FilaAmarela,FilaPacientes * FilaVerde,FilaPacientes * FilaBranca){

    char StringFila[15];
    Boolean FilaEncontrada = false;

    printf("\n+------------------+\n");
    printf("| Selecione a fila |\n");
    printf("+------------------+\n");

    while(FilaEncontrada == false){
        FilaEncontrada = true;

        printf("+-------------+\n");
        printf("|   OPCOES:   |\n");
        printf("|- Vermelha   |\n");
        printf("|- Laranja    |\n");
        printf("|- Amarela    |\n");
        printf("|- Verde      |\n");
        printf("|- Branco     |\n");
        printf("+-------------+\n");
        printf("Escolha: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]s", StringFila);
        setbuf(stdin,NULL);

        strlwr(StringFila);

        if(strcmp(StringFila,"vermelha") == 0){
            return FilaVermelha;
        }else if(strcmp(StringFila,"laranja") == 0){
            return FilaLaranja;
        }else if(strcmp(StringFila,"amarela") == 0){
            return FilaAmarela;
        }else if(strcmp(StringFila,"verde") == 0){
            return FilaVerde;
        }else if(strcmp(StringFila,"branco") == 0){
            return FilaBranca;
        }else{
            FilaEncontrada = false;
            printf("Esolha invalida... Tente novamente!\n");
        }
        printf("\n");
    }

}
