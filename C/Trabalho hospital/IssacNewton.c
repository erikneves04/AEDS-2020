/*
 * @file   IssacNewton.c
 * @brief  Arquivo da união dos modulos de controle do hospital Issac Newton
 * @author <Erik Neves>
 * @date   2020-09-03
*/

/* CRIAÇÃO DE DIRETORIOS system("mkdir c:...")*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Interacoes.h"
#include "structs.h"
#include "ManipulacaoFilas.h"

int main(int argc, char const *argv[]){
    int Escolha_do_usuario = Variavel_de_inicio;

    //DECLARAÇÃO DAS FILAS DE MEDICOS E PACIENTES - INICIO
    FilaMedicos * FilaMedicos;

    FilaPacientes * FilaVermelha;
    FilaPacientes * FilaLaranja;
    FilaPacientes * FilaAmarela;
    FilaPacientes * FilaVerde;
    FilaPacientes * FilaBranca;
    //DECLARAÇÃO DAS FILAS DE MEDICOS E PACIENTES - FIM


    // INICIALIZAÇÃO DAS FILAS DE PACIENTES & MEDICOS- INICIO
    //InicializarFilaMedicos(FilaMedicos)

    InicializarFilaPacientes(FilaVermelha,Vermelha);
    InicializarFilaPacientes(FilaLaranja,Laranja);
    InicializarFilaPacientes(FilaAmarela,Amarela);
    InicializarFilaPacientes(FilaVerde,Verde);
    InicializarFilaPacientes(FilaBranca,Branca);
    // INICIALIZAÇÃO DAS FILAS DE PACIENTES & MEDICOS- FIM

    printf("\t+-------------------------------------+\n");
    printf("\t| BEM VINDO AO HOSPITAL ISSAC NEWSTON |\n");
    printf("\t+-------------------------------------+\n\n");

    while(Escolha_do_usuario != Encerrar_loop){

        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[0x] .\n");
        printf("[0x] .\n");
        printf("[0x] .\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);

        switch (Escolha_do_usuario){
            case 0:
                printf("\n            +-----------------------+\n");
                printf("            | Encerrando o software |\n");
                printf("            +-----------------------+\n");
                printf("+-----------------------------------------------+\n");
                printf("| Um backup dos dados desta execucao foi criado |\n");
                printf("|  e pode ser acessado no diretorio '/Backups'  |\n");
                printf("+-----------------------------------------------+\n\n");
                
            break;
            default:
                printf("\n+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
    }
    return Sucesso;
}
