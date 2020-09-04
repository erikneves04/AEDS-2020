/*
 * @file   ManipulacaoFilas.c
 * @brief  Arquivo com funções de manipulação da lista ordenada.
 * @author <Erik Neves>
 * @date   2020-09-04
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Interacoes.h"
#include "structs.h"

// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - INICIO
void InicializarlistaMedicos(ListaMedico * lista){
    lista->Numero_de_medicos = 0;
    lista->Primeiro = NULL;
}
Error Insere_dadolistaMedicos(ListaMedico * lista){
    Medico * Novo_medico = (Medico*)malloc(sizeof(Medico));

    Novo_medico->EstaTrabalhando = Em_servico;
    Novo_medico->Tempo = 0;
    Novo_medico->HorarioEntrada = Get_HorarioAtual(lista);
    Get_InformacoesMedico(Novo_medico);

    if(lista->Primeiro != NULL){
        lista->Primeiro->anterior = Novo_medico;
    }
    Novo_medico->Proximo = lista->Primeiro;
    Novo_medico->anterior = NULL;

    lista->Primeiro = Novo_medico;
    lista->Numero_de_medicos++;

    return Sucesso;
}
void Remove_dadolistaMedicos(ListaMedico * lista){
    int i;
    char MedicoAlvo[] = "HOSPITAL ISSAC NEWTON AEDS 2020";
    Medico * medicos = lista->Primeiro;
    Get_MedicoAlvo(lista,MedicoAlvo);

    for(i=0;i<lista->Numero_de_medicos;i++){
        if(strcmp(MedicoAlvo,strlwr(medicos->NomeMedico)) == 0){
            medicos->EstaTrabalhando = Fora_de_servico;
            break;
        }
        medicos = medicos->Proximo;
    }
    lista->Numero_de_medicos--;
    if(medicos->anterior != NULL){
        medicos->anterior->Proximo = medicos->Proximo;
        if(medicos->Proximo != NULL){
            medicos->Proximo->anterior = medicos->anterior;
        }
    }else{
        if(medicos->Proximo != NULL) medicos->Proximo->anterior = NULL;
        lista->Primeiro = medicos->Proximo;
    }
    free(medicos);
}
Boolean Lista_vaziaMedicos(ListaMedico * lista){
    return (lista->Numero_de_medicos == 0 && lista->Primeiro == NULL) ? true : false;
}
Error Imprimir_listaMedicos(ListaMedico * lista){
    int i;
    Medico * medicos = lista->Primeiro;

    if(Lista_vaziaMedicos(lista) == false){
        printf("\n  +-----------------------------------------+\n");
        printf("  | Imprimindo os dados da lista de medicos |\n");
        printf("  +-----------------------------------------+\n\n");

        printf("Nome do medico           Tempo    Entrada    Saida\n");
        for(i=0;i<lista->Numero_de_medicos;i++){
            printf("%-25s %.3d       %.3d       %.3d\n",medicos->NomeMedico,medicos->Tempo,medicos->HorarioEntrada,medicos->HorarioSaida);
            medicos = medicos->Proximo;
        }   
        printf("\n");
    }else{
        printf("\n+----------------------------------+\n");
        printf("| Esta lista de medicos esta vazia |\n");
        printf("+----------------------------------+\n\n");

        return Erro_lista_vazia;
    }

    return Sucesso;
}
Error Limpar_listaMedicos(ListaMedico * lista){
    Medico * medicos = lista->Primeiro;
    Medico * proximo_medicoAUX;
    int i;

    for(i=0;i<lista->Numero_de_medicos;i++){
        proximo_medicoAUX = medicos->Proximo;
        free(medicos);
        medicos = proximo_medicoAUX;
    }
    lista->Numero_de_medicos = 0;
    lista->Primeiro = NULL;
    free(lista);
    return Sucesso;
}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - FINAL


// IMPLEMETAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - INICIO
void InicializarlistaAtendimentos(ListaAtendimentos * lista){
    lista->Numero_de_atendimentos = 0;
    lista->Primeiro = NULL;
}
Error Insere_dadolistaAtendimentos(ListaAtendimentos * lista);
void Remove_dadolistaAtendimentos(ListaAtendimentos * lista);
Boolean Lista_vaziaAtendimentos(ListaAtendimentos * lista);
Error Imprimir_listaAtendimentos(ListaAtendimentos * lista);
Error Limpar_listaAtendimentos(ListaAtendimentos * lista){
    Atendimento * atendimentos = lista->Primeiro;
    Atendimento * proximoAtendimentoAUX;
    int i;

    for(i=0;i<lista->Numero_de_atendimentos;i++){
        proximoAtendimentoAUX = atendimentos->Proximo;
        free(atendimentos);
        atendimentos = proximoAtendimentoAUX;
    }
    lista->Numero_de_atendimentos = 0;
    lista->Primeiro = NULL;
    free(lista);
    return Sucesso;
}
// IMPLEMETAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - FIM