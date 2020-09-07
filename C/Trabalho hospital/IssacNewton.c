/*
 * @file   IssacNewton.c
 * @brief  Arquivo da união dos modulos de controle do hospital Issac Newton
 * @author <Erik Neves>
 * @date   2020-09-03
*/

/* CRIAÇÃO DE DIRETORIOS system("mkdir c:...")*/

// O MEDICO DETERMINDA QUANTO TEMPO DEMORA DURA CADA CONSULTA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Interacoes.h"
#include "structs.h"
#include "ManipulacaoFilas.h"
#include "ManipulacaoListas.h"

int main(int argc, char const *argv[]){

    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - INICIO
    int Escolha_do_usuario = Variavel_de_inicio;
    FilaPacientes * FilaIdentifier;
    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - FIM

    
    // DECLARAÇÃO E ALOCAÇÃO DAS FILAS DE MEDICOS E PACIENTES - INICIO
    ListaMedico * ListaMedicos = (ListaMedico*)malloc(sizeof(ListaMedico));
    ListaAtendimentos * listaAtendimentos = (ListaAtendimentos*)malloc(sizeof(ListaAtendimentos));
    TodasAsFilas * FilasDePacientes = (TodasAsFilas*)malloc(sizeof(TodasAsFilas));

    FilaPacientes * FilaVermelha = (FilaPacientes*)malloc(sizeof(FilaPacientes));
    FilaPacientes * FilaLaranja = (FilaPacientes*)malloc(sizeof(FilaPacientes));
    FilaPacientes * FilaAmarela = (FilaPacientes*)malloc(sizeof(FilaPacientes));
    FilaPacientes * FilaVerde = (FilaPacientes*)malloc(sizeof(FilaPacientes));
    FilaPacientes * FilaBranca = (FilaPacientes*)malloc(sizeof(FilaPacientes));
    // DECLARAÇÃO E ALOCAÇÃO DAS FILAS DE MEDICOS E PACIENTES - FIM


    // INICIALIZAÇÃO DAS FILAS DE PACIENTES & MEDICOS- INICIO
    InicializarlistaMedicos(ListaMedicos);
    InicializarlistaAtendimentos(listaAtendimentos);
    InicializarStructTodasAsFilas(FilasDePacientes,FilaVermelha,FilaLaranja,FilaAmarela,FilaVerde,FilaBranca);
    
    InicializarFilaPacientes(FilaVermelha,Vermelha);
    InicializarFilaPacientes(FilaLaranja,Laranja);
    InicializarFilaPacientes(FilaAmarela,Amarela);
    InicializarFilaPacientes(FilaVerde,Verde);
    InicializarFilaPacientes(FilaBranca,Branca);
    // INICIALIZAÇÃO DAS FILAS DE PACIENTES & MEDICOS- FIM

    printf("\t+------------------------------------+\n");
    printf("\t| BEM VINDO AO HOSPITAL ISSAC NEWTON |\n");
    printf("\t+------------------------------------+\n\n");

    while(Escolha_do_usuario != Encerrar_loop){

        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Adicionar paciente.\n");
        printf("[02] Imprimir Fila Pacientes.\n");
        printf("[03] Adicionar medico.\n");
        printf("[04] Remove medico.\n");
        printf("[05] Imprimir medicos.\n");
        printf("[06] Realizar atendimento.\n");
        printf("[07] Imprimir atendimento.\n");
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
            case 1:
                FilaIdentifier = GetUserFila(FilaVermelha,FilaLaranja,FilaAmarela,FilaVerde,FilaBranca);
                Insere_dadoFilaPacientes(FilaIdentifier,Get_TriagemIDDisponivel(),ListaMedicos);
            break;
            case 2:
                FilaIdentifier = GetUserFila(FilaVermelha,FilaLaranja,FilaAmarela,FilaVerde,FilaBranca);
                Imprimir_FilaPacientes(FilaIdentifier);
            break;
            case 3:
                Insere_dadolistaMedicos(ListaMedicos);
            break;
            case 4:
                Remove_dadolistaMedicos(ListaMedicos);
            break;
            case 5:
                Imprimir_listaMedicos(ListaMedicos);
            break;
            case 6:
                FilaIdentifier = FilaVermelha;
                Insere_dadolistaAtendimentos(listaAtendimentos,FilaIdentifier,ListaMedicos);
            break;
            case 7:
                Imprimir_listaAtendimentos(listaAtendimentos);
            break;
            case 8:
            break;
            default:
                printf("\n+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
    }
    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - INICIO
    Limpar_listaMedicos(ListaMedicos);
    Limpar_listaAtendimentos(listaAtendimentos);

    Limpar_FilaPacientes(FilaVermelha);
    Limpar_FilaPacientes(FilaLaranja);
    Limpar_FilaPacientes(FilaAmarela);
    Limpar_FilaPacientes(FilaVerde);
    Limpar_FilaPacientes(FilaBranca);
    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - FIM
    return Sucesso;
}