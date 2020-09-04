/*
 * @file   Interacoes.c
 * @brief  Arquivo com implementação das funções para interagir com o usuario & variavies constantemente acessadas.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constantes.h"
#include "structs.h"

int Get_TriagemIDDisponivel(){
    static int ID = 0;
    return ID++;
}
int Get_HorarioAtual(ListaMedico * fila){
    int Tempo = 0;
    int i;
    Medico * Medicos = fila->Primeiro;

    for(i=0;i<fila->Numero_de_medicos;i++){
        if(Tempo < Medicos->Tempo && Medicos->EstaTrabalhando == Em_servico){
            Tempo = Medicos->Tempo;
        }
        Medicos = Medicos->Proximo;
    }
    
    return Tempo;
}

Error Get_InformacoesPaciente(Paciente * Novo_paciente){

    printf("Digite o nome do paciente(Max.:25): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s",Novo_paciente->NomePaciente);
    setbuf(stdin,NULL);

    printf("\n");
    return Sucesso;

}
FilaPacientes * GetUserFila(FilaPacientes * FilaVermelha,FilaPacientes * FilaLaranja,FilaPacientes * FilaAmarela,FilaPacientes * FilaVerde,FilaPacientes * FilaBranca){

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
Error Get_InformacoesMedico(Medico * Novo_medico){

    printf("Digite o nome do medico: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s", Novo_medico->NomeMedico);
    setbuf(stdin,NULL);
    printf("Digite o horario de saida do medico(Entrada: %.3d): ",Novo_medico->HorarioEntrada);
    scanf("%d", &Novo_medico->HorarioSaida);

    return Sucesso;
}
Error Get_MedicoAlvo(ListaMedico * lista, char StringUser[]){

    Boolean MedicoEncontrado = false;
    Medico * medicos = lista->Primeiro;
    int i;
    char NomeAux[] = "HOSPITAL ISSAC NEWTON AEDS 2020";

    printf("\n+---------------------------------------------------+\n");
    printf("| Digite o nome do medico para encerrar seu plantao |\n");
    printf("+---------------------------------------------------+\n");
    for(i=0;i<lista->Numero_de_medicos;i++){
        printf("|- %-25s |\n",medicos->NomeMedico);
        medicos = medicos->Proximo;
    }
    printf("+----------------------------+\n\n");
    medicos = lista->Primeiro;

    while(MedicoEncontrado == false){
        printf("Nome do medico: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]s", NomeAux);
        setbuf(stdin,NULL);
        strlwr(NomeAux);
        for(i=0;i<lista->Numero_de_medicos;i++){
            if(strcmp(NomeAux,strlwr(medicos->NomeMedico)) == 0){
                MedicoEncontrado = true;
                strcpy(StringUser,NomeAux);
                break;
            }
            medicos = medicos->Proximo;
        }
        printf("\n");
    }
    return Sucesso;
}