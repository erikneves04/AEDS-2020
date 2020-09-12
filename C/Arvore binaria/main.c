/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves>
 * @date   2020-09-10
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
#include "funcoes.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


static DataType UserIteract(void){
    DataType Interact_aux;
    char Identifier[] = "%";

    strcat(Identifier,PrintfType);

    printf("\nDigite o dado(%s): ",PrintfType_descripition);
    scanf(Identifier,&Interact_aux);

    printf("\n");
    return Interact_aux;
}

int main(void){

    int Escolha_do_usuario=Variavel_de_inicio;
    Arvore * arvore;

    while(Escolha_do_usuario!=Encerrar_loop){

        printf("+------------------------------+\n");
        printf("| Implementacao Arvore binaria |\n");
        printf("+------------------------------+\n");
        printf("[00] Encerra o software.\n");
        printf("[0x] FUNÇÕES PRONTAS NO <funcoes.C>n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");


        switch(Escolha_do_usuario){
            case 0:
                printf("+---------------+\n");
                printf("| Encerrando... |\n");
                printf("+---------------+\n\n");
            break;
            case 1:
                Criar_Arvore(arvore,100,NULL,NULL);
                Imprimir_Arvore(arvore);
            break;
            break;
            default:
                printf("+------------------------------------+\n");
                printf("| Escolha invalida. Tente novamente! |\n");
                printf("+------------------------------------+\n\n");
            break;
        }
    }
    return Sucesso;
}