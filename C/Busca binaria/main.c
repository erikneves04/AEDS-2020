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
#include "funcoesLE.h"
#include "interact.h"
#include "BuscaBinaria.h"

int main(void){

    int Escolha_do_usuario=Variavel_de_inicio;
    Lista * ListaPessoas = (Lista*)malloc(sizeof(Lista));
    DataType * ReturnAux;

    InicializarLista(ListaPessoas);

    while(Escolha_do_usuario!=Encerrar_loop){
        printf("+--------------------------------+\n");
        printf("| Implementacao vetores binarios |\n");
        printf("+--------------------------------+\n");
        printf("[00] Encerra bloco binario.\n");
        printf("[01] Inserir item.\n");
        printf("[02] Remover item.\n");
        printf("[03] Imprimir itens.\n");
        printf("[04] Buscar item.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");

        switch (Escolha_do_usuario){
            case 0:
                printf("+-----------------------+\n");
                printf("| Encerrando o software |\n");
                printf("+-----------------------+\n\n");
            break;
            case 1:
                InsereOrdenado(ListaPessoas,GetInfosDataType());
            break;
            case 2:
                RemoverItemLista(ListaPessoas,GetDataTypeAlvo(ListaPessoas,GetStringAlvo()));
            break;
            case 3:
                ImprimirDadosLista(ListaPessoas);
            break;
            case 4:
                ReturnAux = BuscaDadoItem(ListaPessoas,GetStringAlvo());
                if(ReturnAux == NULL) AvisoPessoaInexistente();
                ImprimirDadosPessoa(ReturnAux);
            break;
            default:
                printf("Escolha invalida\n");
            break;
        }
    }
                
    return Sucesso;
}