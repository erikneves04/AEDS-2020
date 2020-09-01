/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves>
 * @date   2019-11-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoes.h"

static int Int_iteract(){
    int Interact_aux;

    printf("\nDigite o valor: ");
    scanf("%d", &Interact_aux);
    printf("\n");

    return Interact_aux;
}

int main(void){

    Lista * lista = (Lista*)malloc(sizeof(Lista));
    int Escolha_do_usuario=Variavel_de_inicio;

    Inicializar_lista(lista);
    while(Escolha_do_usuario!=0){

        printf("+---------------------------------------+\n");
        printf("| Implementacao lista encadeada simples |\n");
        printf("+---------------------------------------+\n");
        printf("[0] Encerra o software.\n");
        printf("[1] Inserir valor.\n");
        printf("[2] Remover valor.\n");
        printf("[3] Imprimir dados.\n");
        printf("[4] Estado da lista.\n");
        printf("[5] Limpar lista.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");


        switch(Escolha_do_usuario){
            
            case 0:
                printf(" Encerrando. \n\n");
            break;
            case 1:
                Insere_dado(Int_iteract(),lista);
            break;
            case 2:
                Remove_dado(Int_iteract(),lista);
            break;
            case 3:
                Imprimir_lista(lista);
            break;
            case 4:
                printf("\n%d\n\n",Lista_vazia(lista));
            break;
            case 5:
                Limpar_lista(lista);
            break;
            default:
                printf(" Invalido. \n\n");
            break;
        }
    }
    return Sucesso;
}