/*
 * @file   Interacoes.c
 * @brief  Arquivo com implementação das funções para interagir com o usuario
 *                  & variavies constantemente acessadas.
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
// INCLUSÃO DE BIBLIOTECAS - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int Get_TriagemIDDisponivel(){
    /* 
    * Função responsavel por retornar o valor de triagem disponivel. 
    * @return (int) ID 
    */
    static int ID = 0;
    return ID++;
}
int Get_HorarioAtual(ListaMedico * fila){
    /* 
    * Função responsavel por calcular o horario atual.
    * (CALCULADO COM BASE NO MAIOR TEMPO ENTRE OS MEDICOS) 
    * @return (int) ID 
    */
    int Tempo = 0;
    int i;
    Medico * Medicos = fila->Primeiro;

    for(i=0;i<fila->Numero_de_medicos;i++){
        if(Tempo < Medicos->Tempo){
            Tempo = Medicos->Tempo;
        }
        Medicos = Medicos->Proximo;
    }
    
    return Tempo;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
Error Get_InformacoesPaciente(Paciente * Novo_paciente){
    /*
    * Função que interage com o usuario para receber o nome do paciente.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("Digite o nome do paciente(Max.:25): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s",Novo_paciente->NomePaciente);
    setbuf(stdin,NULL);

    printf("\n");
    return Sucesso;
}
FilaPacientes * GetUserFila(TodasAsFilas * filas){
    /*
    * Função que interage com o usuario para identificar a fila do paciente.
    * @return (FilaPacientes) ponteiro para a fila escolhida pelo usuario.
    */
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
        printf("|- Branca     |\n");
        printf("+-------------+\n");
        printf("Escolha: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]s", StringFila);
        setbuf(stdin,NULL);

        strlwr(StringFila);

        if(strcmp(StringFila,"vermelha") == 0){
            return filas->FilaVermelha;
        }else if(strcmp(StringFila,"laranja") == 0){
            return filas->FilaLaranja;
        }else if(strcmp(StringFila,"amarela") == 0){
            return filas->FilaAmarela;
        }else if(strcmp(StringFila,"verde") == 0){
            return filas->FilaVerde;
        }else if(strcmp(StringFila,"branca") == 0){
            return filas->FilaBranca;
        }else{
            FilaEncontrada = false;
            printf("\nEsolha invalida... Tente novamente!\n");
        }
        printf("\n");
    }

}
Error Get_InformacoesMedico(Medico * Novo_medico){
    /*
    * Função que interage com o usuario para receber 
    *       os dados do medico a ser inserido.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\nDigite o nome do medico(Max.:25): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s", Novo_medico->NomeMedico);
    setbuf(stdin,NULL);
    printf("Digite o horario de saida do medico(Entrada: %.3d): ",Novo_medico->HorarioEntrada);
    scanf("%d", &Novo_medico->HorarioSaida);
    printf("OBS.: Por questoes de seguranca somente um medico pode deixar o plantao por vez.\n\n");

    return Sucesso;
}
Error Get_MedicoAlvo(ListaMedico * lista, char StringUser[]){
    /*
    * Função que interage com o usuario para receber o nome do medico alvo.
    * @return Sucesso caso ocorra tudo certo.
    */
    Boolean MedicoEncontrado = false;
    Medico * medicos = lista->Primeiro;
    int i;
    char NomeAux[] = "HOSPITAL ISSAC NEWTON AEDS 2020";

    printf("\n+---------------------------------------------------+\n");
    printf("| Digite o nome do medico para encerrar seu plantao |\n");
    printf("+---------------------------------------------------+\n");
    printf("|- %-25s |\n","Exit  - para cancelar");
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

        if(strcmp(NomeAux,"exit") == 0){
            MedicoEncontrado = true;
        }

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
Error Get_InformacoesAtendimento(Atendimento * Novo_atendimento,ListaMedico * ListaMedicos){
    /*
    * Função que interage com o usuario para receber 
    *       os dados de um atendimentos.
    * @return Sucesso caso ocorra tudo certo.
    */
    Novo_atendimento->DuracaoAtendimento;
    Novo_atendimento->Medico;
    char StringPulseira[10];
    Boolean SeeMedicos = false;

    switch (Novo_atendimento->Pulseira){
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

    printf("\n\t+--------------------------------+\n");
    printf("\t| Insira os dados do atendimento |\n");
    printf("\t+--------------------------------+\n");
    
    printf("Nome paciente: %-25s Pulseira: %-10s\n",Novo_atendimento->Paciente,StringPulseira);
    printf("Inicio do atendimento: %.4d              TriagemID: %.4d\n",Novo_atendimento->InicioAtendimento,Novo_atendimento->TriagemID);
    printf("Digite a duracao do atendimento: ");
    scanf("%d", &Novo_atendimento->DuracaoAtendimento);
    
    printf("Gostaria de ver uma lista com o nome dos medicos em plantao?\n");
    printf("[00] Sim.\n");
    printf("[01] Nao.\n");
    printf("Escolha: ");
    scanf("%d", &SeeMedicos);

    if(SeeMedicos == true) Imprimir_listaMedicos(ListaMedicos);

    printf("Digite o nome do medico: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s", Novo_atendimento->Medico);
    setbuf(stdin,NULL);
    printf("\n");
    
    return Sucesso;
}
Error PrintErrorMedicoInvalido(){
    /*
    * Função que imprime pro usuario quando é interrompido um atendimento.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+-------------------------------------------+\n");
    printf("|       O medico inserido eh invalido.      |\n");
    printf("|           Atendimento cancelado.          |\n");
    printf("| O paciente foi novamente inserido na fila |\n");
    printf("+-------------------------------------------+\n\n");

    return Sucesso;
}
Error PrintErrorFilasVazias(){
    /*
    * Função que imprime pro usuario quando é interrompido um atendimento.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+--------------------------------------------------+\n");
    printf("| Nenhum paciente esta aguardando por atendimento. |\n");
    printf("+--------------------------------------------------+\n\n");

    return Sucesso;
}
FilaPacientes * Get_FilaPrioritaria(TodasAsFilas * Filas){
    /*
    * Função que retorna a fila com mair prioridade e que nao esteja vazia;.
    * @return (FilaPacientes) ponteiro que indica a fila.
    */
    if(Filas->FilaVermelha->Numero_de_pacientes != 0) return Filas->FilaVermelha;
    if(Filas->FilaLaranja->Numero_de_pacientes != 0) return Filas->FilaLaranja;
    if(Filas->FilaAmarela->Numero_de_pacientes != 0) return Filas->FilaAmarela;
    if(Filas->FilaVerde->Numero_de_pacientes != 0) return Filas->FilaVerde;
    if(Filas->FilaBranca->Numero_de_pacientes != 0) return Filas->FilaBranca;
    return NULL;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM