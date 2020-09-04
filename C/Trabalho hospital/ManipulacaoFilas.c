/*
 * @file   ManipulacaoFilas.c
 * @brief  Arquivo com funções de manipulação das filas.
 * @author <Erik Neves>
 * @date   2020-09-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Interacoes.h"
#include "structs.h"


// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - INICIO
void InicializarFilaPacientes(FilaPacientes * fila,unsigned int ID){
    fila = (FilaPacientes*)malloc(sizeof(FilaPacientes));

    fila->Numero_de_pacientes = 0;
    fila->Primeiro = NULL;
    fila->PulseiraID = ID;
}

Error Insere_dadoFilaPacientes(){
}
void Remove_dadoFilaPacientes(){
}
Boolean Lista_vaziaFilaPacientes(){
}
Error Imprimir_listaFilaPacientes(){
}
Error Limpar_listaFilaPacientes(){
}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE PACIENTES - FINAL





// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - INICIO
void InicializarFilaMedicos(){}
Error Insere_dadoFilaMedicos(){}
void Remove_dadoFilaMedicos(){}
Boolean Lista_vaziaFilaMedicos(){}
Error Imprimir_listaFilaMedicos(){}
Error Limpar_listaFilaMedicos(){}
// IMPLEMENTAÇÃO FUNÇÕES DE MANIPULAÇÃO DAS FILAS DE MEDICOS - FINAL