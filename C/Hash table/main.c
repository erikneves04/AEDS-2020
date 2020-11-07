/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves * @date   2020-11-07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "interact.h"
#include "hash.h"

int main(void){

    int Escolha_do_usuario=Variavel_de_inicio;
    HashTable * TabelaHash = (HashTable*)malloc(sizeof(HashTable));

    InicializarHashTable(TabelaHash);
    while(Escolha_do_usuario!=Encerrar_loop){
        printf("+---------------------------+\n");
        printf("| Implementacao tabela Hash |\n");
        printf("+---------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Inserir item.\n");
        printf("[02] Remover item.\n");
        printf("[03] Imprimir itens.\n");
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
                InserirHashTable(TabelaHash,GetInfosDataType());
            break;
            case 2:
                RemoverDadoHashTable(TabelaHash,GetStringAlvo());
            break;
            case 3:
                ImprimirDadosColuna(TabelaHash,GetColunaAlvo(TabelaHash));
            break;
            default:
                printf("Escolha invalida\n");
            break;
        }
    }       
    return Sucesso;
}