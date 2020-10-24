/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves>
 * @date   2020-10-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoes.h"


int main(void){

    Grafo * grafo = (Grafo*)malloc(sizeof(Grafo));
    int Escolha_do_usuario=Variavel_de_inicio;

    int GrauAux;

    InicializarGrafo(grafo);

    while(Escolha_do_usuario!=Encerrar_loop){

        printf("+---------------------+\n");
        printf("| Implementacao grafo |\n");
        printf("+---------------------+\n");
        printf("[0] Encerra o software.\n");
        printf("[1] Inserir vertice.\n");
        printf("[2] Redefinir arestas de um vertice.\n");
        printf("[3] Imprimir os dados dos vertices.\n");
        printf("[4] Imprimir as arestras de um vertice.\n");
        printf("[5] Remover vertice.\n");
        printf("[6] Grau de um vertice.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");


        switch(Escolha_do_usuario){ 
            case 0:
                printf(" Encerrando. \n\n");
            break;
            case 1:
                printf("Caso prefira sera possivel anexar as anexas posteriormente.\n");
                printf("Para tal indique o numero de arestas como zero e depois\nutilize a opcao 2.\n");
                InserirItem(grafo,IndexArestras(grafo),UserIteract());
            break;
            case 2:
                RedefinirListaArestras(grafo);
            break;
            case 3:
                ImprimirDadosGrafo(grafo);
            break;
            case 4:
                ImprimirArestrasVertice(grafo);
            break;
            case 5:
                RemoverItem(grafo);
            break;
            case 6:
                GrauAux = CalculaGrauVertice(GetVerticeAlvo(grafo));
                printf("\nO vertice escolhido possui um grau de : %.2d\n\n",GrauAux);
            break;
            default:
                printf(" Invalido. \n\n");
            break;
        }
    }
    return Sucesso;
}