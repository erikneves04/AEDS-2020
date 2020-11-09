/**
* @file   const.h
* @brief  Arquivo com a definição de constantes.
* @author <Erik Neves>
* @date   2020-11-05
*/
#pragma once

#ifndef __const_h__
#define __const_h__

#define Tamanho_MAX_string  (25)

typedef unsigned int Boolean;
#define true                (00)
#define false               (!true)

typedef unsigned int Error;
#define Encerrar_loop       (00)
#define Sucesso             (00)
#define Erro_lista_vazia    (01)
#define Dado_nao_encontrado (02)
#define Coluna_inexistente  (03)
#define Variavel_de_inicio  (-1)

// Dados pessoais
typedef struct DadosEndereco_t{
    char Rua[Tamanho_MAX_string];
    char Bairro[Tamanho_MAX_string];
    char Cidade[Tamanho_MAX_string];
    unsigned int Numero;
}DadosEndereco;
typedef struct DadosPessoa_t{
    char Nome[Tamanho_MAX_string];
    long int Telefone; 
    DadosEndereco * Endereco;
}Pessoa;
typedef Pessoa DataType;

//Armazenamento e acesso na memoria
typedef struct Item_lista_t{
    DataType * DadosItem;
    struct Item_lista_t * Anterior;
    struct Item_lista_t * Proximo;
}Item_lista;
typedef struct ItensLista{
    unsigned int NumeroDeDados;
    Item_lista * Primeiro;
    Item_lista * Ultimo;
}Lista;

#endif /* __const_h__ */