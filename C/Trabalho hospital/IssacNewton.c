/*
 * @file   IssacNewton.c
 * @brief  Arquivo da união dos modulos de controle do hospital Issac Newton.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "constantes.h"
#include "ManipulacaoFilas.h"
#include "ManipulacaoListas.h"
#include "Variaveis&interacoes.h"
#include "MakeBackup.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


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


    // IMPRESSÃO DE MENSAGEM DE BEM VINDO - INCIO
    printf("\t+------------------------------------+\n");
    printf("\t| BEM VINDO AO HOSPITAL ISSAC NEWTON |\n");
    printf("\t+------------------------------------+\n\n");
    // IMPRESSÃO DE MENSAGEM DE BEM VINDO - FIM


    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - INICIO
    while(Escolha_do_usuario != Encerrar_loop){
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - INICIO
        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Adicionar paciente.\n");
        printf("[02] Adicionar medico.\n");
        printf("[03] Realizar atendimento.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - FIM


        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - INICIO
        switch (Escolha_do_usuario){
            case 0:
                /* EXECUÇÕES:
                * Impressão dos dados de atendimentos
                * Impressão mensagem de encerramento do software
                * Chamada da função de criação do aquivo.txt com os dados dos atendimentos
                */
                Imprimir_listaAtendimentos(listaAtendimentos);
                printf("\n            +-----------------------+\n");
                printf("            | Encerrando o software |\n");
                printf("            +-----------------------+\n");
                CriaTXTBackup(listaAtendimentos);
            break;
            case 1:
                /* EXECUÇÕES:
                * Recebe a fila de acordo com a inserção do usuario
                * Chamada da função para inserção do paciente
                */
                FilaIdentifier = GetUserFila(FilasDePacientes);
                Insere_dadoFilaPacientes(FilaIdentifier,Get_TriagemIDDisponivel(),ListaMedicos);
            break;
            case 2:
                /* EXECUÇÕES:
                * Chamada da função para inserção do medico
                */
                Insere_dadolistaMedicos(ListaMedicos);
            break;
            case 3:
                /* EXECUÇÕES:
                * Recebe a fila prioritaria
                * Chamada da função para realizar atendimentos
                * Chamada da função para atualização das pulseiras dos pacientes
                * Chamada da função para verificar o fim de um plantão medico
                */
                FilaIdentifier = Get_FilaPrioritaria(FilasDePacientes);
                Insere_dadolistaAtendimentos(listaAtendimentos,FilaIdentifier,ListaMedicos);
                Update_FilaPaciente(FilasDePacientes,ListaMedicos);
                Update_PlantaoMedico(ListaMedicos);
            break;
            default:
                /* EXECUÇÕES:
                * Impressão informando escolha invalida dentre as opções
                */
                printf("\n+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - FIM
    }
    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - FIM


    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - INICIO
    Limpar_listaMedicos(ListaMedicos);
    Limpar_listaAtendimentos(listaAtendimentos);
    Limpar_memoriaStructTodasAsFilas(FilasDePacientes);

    Limpar_FilaPacientes(FilaVermelha);
    Limpar_FilaPacientes(FilaLaranja);
    Limpar_FilaPacientes(FilaAmarela);
    Limpar_FilaPacientes(FilaVerde);
    Limpar_FilaPacientes(FilaBranca);
    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - FIM
    

    // FINALIZAÇÃO COM EXITO DO SOFTWARE - INICIO
    return Sucesso;
    // FINALIZAÇÃO COM EXITO DO SOFTWARE - FIM
}