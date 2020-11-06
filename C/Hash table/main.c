/*
 * @file   main.c
 * @brief  
 * @author <Erik Neves>
 * @date   2020-11-05
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoesLE.h"
#include "interact.h"
#include "BuscaBinaria.h"
#include "hash.h"

/*
1. Crie uma Agenda de Contatos (Nome, Telefone, Endereço)
com uma Busca Binária baseada no nome do contato.
2. Crie uma Agenda de Contatos (Nome, Telefone, Endereço)
baseada em Tabela Hash.
*/

int main(void){

    int Escolha_do_usuario=Variavel_de_inicio;
    Lista * ListaPessoas = (Lista*)malloc(sizeof(Lista));
    HashTable * TabelaHash = (HashTable*)malloc(sizeof(HashTable));
    DataType * ReturnAux;

    InicializarLista(ListaPessoas);
    InicializarHashTable(TabelaHash);
    while(Escolha_do_usuario!=Encerrar_loop){

        printf("+----------------------------------------------+\n");
        printf("| Implementacao Tabela Hash & vetores binarios |\n");
        printf("+----------------------------------------------+\n");
        printf("[00] Encerra o software.\n");
        printf("[01] Acessar trechos vetoriais.\n");
        printf("[02] Acessar trechos usando Hash table.\n");
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
                            printf("+--------------------+\n");
                            printf("| Encerrando o bloco |\n");
                            printf("+--------------------+\n\n");
                        break;
                        case 1:
                            InsereOrdenado(ListaPessoas,GetInfosDataType());
                        break;
                        case 2:
                            //so indexar a remoção
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
                Escolha_do_usuario = Variavel_de_inicio;
            break;
            case 2:
                while(Escolha_do_usuario!=Encerrar_loop){
                    printf("+---------------------------+\n");
                    printf("| Implementacao tabela Hash |\n");
                    printf("+---------------------------+\n");
                    printf("[00] Encerra bloco binario.\n");
                    printf("[01] Inserir item.\n");
                    printf("[02] Remover item.\n");
                    printf("[03] Imprimir itens.\n");
                    printf("Escolha: ");
                    scanf("%d", &Escolha_do_usuario);
                    printf("\n");

                    switch (Escolha_do_usuario){
                        case 0:
                            printf("+--------------------+\n");
                            printf("| Encerrando o bloco |\n");
                            printf("+--------------------+\n\n");
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
                Escolha_do_usuario = Variavel_de_inicio;
            break;
            default:
                printf("Escolha invalida\n");
            break;
        }
    }
    return Sucesso;
}