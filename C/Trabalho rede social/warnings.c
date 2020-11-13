/*
 * @file   warnings.c
 * @brief  Arquivo com  a implementação das funções 
 *              de avisos da rede social.
 * @author <Erik Neves>
 * @date   2020-11-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"

Error PerfilNaoEncontrado(){
    printf("\n+-----------------------+\n");
    printf("| Perfil nao encontrado |\n");
    printf("+-----------------------+\n\n");
    return Sucesso;
}
Error AtivacaoDefault(){
    printf("\n+-----------------------------------------+\n");
    printf("| Primeiro eh necessario ativar um perfil |\n");
    printf("+-----------------------------------------+\n\n");
    return Sucesso;
}
Error PerfilDeletado(unsigned int id){
    printf("\n+-------------------------------------+\n");
    printf("| Perfil(ID: %.2d) deletado com sucesso |\n",id);
    printf("+-------------------------------------+\n\n");
    return Sucesso;
}
Error PostNaoEncontrado(){
    printf("\n+-------------------------+\n");
    printf("| Postagem nao encontrada |\n");
    printf("+-------------------------+\n\n");
    return Sucesso;
}