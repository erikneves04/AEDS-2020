/**
* @file   warnings.c
* @brief  Arquivo com a implementação das funções 
*              de avisos da rede social.
* @author <Erik Neves>
* @date   2020-11-13
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


Error PerfilNaoEncontrado(){
    /**
    * Função resposavel por informar um erro por parte do usuario.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+-----------------------+\n");
    printf("| Perfil nao encontrado |\n");
    printf("+-----------------------+\n\n");
    return Sucesso;
}
Error AtivacaoDefault(){
    /**
    * Função resposavel por informar um erro por parte do usuario.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+-----------------------------------------+\n");
    printf("| Primeiro eh necessario ativar um perfil |\n");
    printf("+-----------------------------------------+\n\n");
    return Sucesso;
}
Error PerfilDeletado(unsigned int id){
    /**
    * Função resposavel por informar um erro por parte do usuario.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+-------------------------------------+\n");
    printf("| Perfil(ID: %.2d) deletado com sucesso |\n",id);
    printf("+-------------------------------------+\n\n");
    return Sucesso;
}
Error PostNaoEncontrado(){
    /**
    * Função resposavel por informar um erro por parte do usuario.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+-------------------------+\n");
    printf("| Postagem nao encontrada |\n");
    printf("+-------------------------+\n\n");
    return Sucesso;
}
Error ArquivoCorrompido(){
    /**
    * Função resposavel por informar um erro por parte do usuario.
    * @return Sucesso caso ocorra tudo certo.
    */
    printf("\n+---------------------------+\n");
    printf("| Banco de dados corrompido |\n");
    printf("+---------------------------+\n\n");
    return Sucesso;
}