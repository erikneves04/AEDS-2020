/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves>
 * @date   2020-11-07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoes.h"

static DataType UserIteract(void){
    DataType NovoDataType;

    printf("Digite o valor(inteiro): ");
    scanf("%d", &NovoDataType);

    return NovoDataType;
}
Boolean CompararDados(DataType Dado01,DataType Dado02){
    Boolean DadosIguais = false;
    if(Dado01 == Dado02) DadosIguais = true;
    return (DadosIguais == true) ? true : false;
}
Error ImprimirDataType(DataType Dado){
    printf("%d",Dado);
    return Sucesso;
}

int main(void){

    Lista * lista = (Lista*)malloc(sizeof(Lista));
    int Escolha_do_usuario=Variavel_de_inicio;

    Inicializar_lista(lista,CompararDados,ImprimirDataType);
    while(Escolha_do_usuario!=Encerrar_loop){

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
                Insere_dado(UserIteract(),lista);
            break;
            case 2:
                Remove_dado(UserIteract(),lista);
            break;
            case 3:
                Imprimir_lista(lista);
            break;
            case 4:
                if(Lista_vazia(lista) == true){
                    printf("\n Esta vazia: true\n\n");
                }else{
                    printf("\n Esta vazia: false\n\n");
                }
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