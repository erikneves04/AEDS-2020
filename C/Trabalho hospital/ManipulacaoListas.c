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
#include "structs.h"
#include "ManipulacaoFilas.h"
#include "Variaveis&interacoes.h"

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
Error Remove_dadolistaMedicos(ListaMedico * lista){
    int i;
    char * Cancelar = "exit";
    char MedicoAlvo[] = "HOSPITAL ISSAC NEWTON AEDS 2020";
    Medico * medicos = lista->Primeiro;
    Get_MedicoAlvo(lista,MedicoAlvo);

    if(strcmp(MedicoAlvo,Cancelar) == 0){
        return Acao_cancelada;
    }else{
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
    
    return Sucesso;
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
Error Update_TempoMedico(ListaMedico * lista,char * Nome_medico,int TempoUltimoAtendimento){
    int i;
    Medico * medicos = lista->Primeiro;
    Boolean MedicoEncontrado = false;
    for(i=0;i<lista->Numero_de_medicos;i++){
        if(strcmp(strlwr(Nome_medico),strlwr(medicos->NomeMedico)) == 0){
            medicos->Tempo += TempoUltimoAtendimento;
            MedicoEncontrado = true;
            break;
        }
        medicos = medicos->Proximo;
    }
    return (MedicoEncontrado == true) ? true : false;
}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE MEDICOS - FINAL


// IMPLEMETAÇÃO FUNÇÕES DE MANIPULAÇÃO DA LISTA DE ATENDIMENTOS - INICIO
void InicializarlistaAtendimentos(ListaAtendimentos * lista){
    lista->Numero_de_atendimentos = 0;
    lista->Primeiro = NULL;
}
Error Insere_dadolistaAtendimentos(ListaAtendimentos * lista_atendimentos, FilaPacientes * fila,ListaMedico * ListaMedicos){
    Atendimento * Atendimentos = lista_atendimentos->Primeiro;
    Atendimento * Novo_atendimento = (Atendimento*)malloc(sizeof(Atendimento));
    Paciente * paciente;
    Boolean MedicoEncontrado;
    Boolean LocalToAddEncontrado = false;
    int i;

    if(fila == NULL) return Erro_lista_vazia;
    paciente = fila->Primeiro;
    
    strcpy(Novo_atendimento->Paciente,paciente->NomePaciente);
    Novo_atendimento->TriagemID = paciente->TriagemID;
    Novo_atendimento->ChegadaAoHospital = paciente->HorarioChegada;
    Novo_atendimento->Pulseira = fila->PulseiraID;
    Novo_atendimento->InicioAtendimento = Get_HorarioAtual(ListaMedicos);
    Get_InformacoesAtendimento(Novo_atendimento,ListaMedicos);
    MedicoEncontrado = Update_TempoMedico(ListaMedicos,Novo_atendimento->Medico,Novo_atendimento->DuracaoAtendimento);

    if(MedicoEncontrado == false){
        PrintErrorMedicoInvalido();
        return Medico_inexistente;
    }

    // Inserir ordenado com base no tempo do inicio do atendimento
    if(lista_atendimentos->Numero_de_atendimentos == 0){
        Novo_atendimento->Proximo == NULL;
        Novo_atendimento->Anterior == NULL;
        lista_atendimentos->Primeiro = Novo_atendimento;
        LocalToAddEncontrado = true;
    }else{
        for(i=0;i<lista_atendimentos->Numero_de_atendimentos;i++){
            if((Atendimentos->InicioAtendimento) > (Novo_atendimento->InicioAtendimento)){
                LocalToAddEncontrado = true;
                if(Atendimentos->Anterior == NULL){
                    Novo_atendimento->Proximo = Atendimentos;
                    Novo_atendimento->Anterior = NULL;
                    Atendimentos->Anterior = Novo_atendimento;
                    lista_atendimentos->Primeiro = Novo_atendimento;
                }else if(Atendimentos->Proximo == NULL){;
                    Atendimentos->Proximo = Novo_atendimento;
                    Novo_atendimento->Proximo = NULL;
                    Novo_atendimento->Anterior = Atendimentos;
                }else{
                    Atendimentos->Anterior->Proximo = Novo_atendimento;
                    Novo_atendimento->Anterior = Atendimentos->Anterior;
                    Atendimentos->Anterior = Novo_atendimento;
                    Novo_atendimento->Proximo = Atendimentos;
                }
            }
            if(Atendimentos->Proximo != NULL){
                Atendimentos = Atendimentos->Proximo;
            }
        }
    }

    if(LocalToAddEncontrado == false){
        Atendimentos->Proximo = Novo_atendimento;
        Novo_atendimento->Proximo = NULL;
        Novo_atendimento->Anterior = Atendimentos;
    }   
    
    lista_atendimentos->Numero_de_atendimentos++;
    Limpar_memoriaPaciente(Remove_dadoFilaPacientes(fila));
    return Sucesso;
}
Boolean Lista_vaziaAtendimentos(ListaAtendimentos * lista){
    return (lista->Numero_de_atendimentos == 0 && lista->Primeiro == NULL) ? true : false;
}
Error Imprimir_listaAtendimentos(ListaAtendimentos * lista){
    int i;
    char StringPulseira[10];
    Atendimento * Atendimentos_aux = lista->Primeiro;

    if(Lista_vaziaAtendimentos(lista) == false){
        printf("\n  +----------------------------------------------+\n");
        printf("  | Imprimindo os dados da lista de Atendimentos |\n");
        printf("  +----------------------------------------------+\n\n");

        for(i=0;i<lista->Numero_de_atendimentos;i++){
            switch (Atendimentos_aux->Pulseira){
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
            printf("Identificador de triagem: %.4d  Pulseira %-10s\n",Atendimentos_aux->TriagemID,StringPulseira);
            printf("Paciente : %-25s\n",Atendimentos_aux->Paciente);
            printf("Medico: %-25s\n", Atendimentos_aux->Medico);
            printf("Inicio: %.4d  Termino: %.4d  Entrada: %.4d\n",Atendimentos_aux->InicioAtendimento,(Atendimentos_aux->DuracaoAtendimento + Atendimentos_aux->InicioAtendimento),Atendimentos_aux->ChegadaAoHospital);
            printf("\n");
            Atendimentos_aux = Atendimentos_aux->Proximo;
        }   
        printf("\n");
    }else{
        printf("\n+---------------------------------------+\n");
        printf("| Esta lista de atendimentos esta vazia |\n");
        printf("+---------------------------------------+\n\n");

        return Erro_lista_vazia;
    }

    return Sucesso;
}
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