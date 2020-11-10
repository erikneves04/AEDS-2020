/*
 * @file   Barchielo's_chat.c
 * @brief  Arquivo da união dos modulos de controle de rede social 
 *                         Barchielo's chat.
 * @author <Erik Neves>
 * @date   2020-11-08
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "constantes.h"
#include "Variaveis&interacoes.h"
#include "hash.h"
// INCLUSÃO DE BIBLIOTECAS - FIM

int main(int argc, char const *argv[]){

    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - INICIO
    int Escolha_do_usuario = Variavel_de_inicio;
    HashTable * Usuarios = (HashTable*)malloc(sizeof(HashTable));
    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - FIM
    
    InicializarHashTable(Usuarios);

    // IMPRESSÃO DE MENSAGEM DE BEM VINDO - INCIO
    printf("\t+-------------------------------+\n");
    printf("\t| BEM VINDO AO BARCHIELO'S CHAT |\n");
    printf("\t+-------------------------------+\n\n");
    // IMPRESSÃO DE MENSAGEM DE BEM VINDO - FIM


    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - INICIO
    while(Escolha_do_usuario != Encerrar_loop){
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - INICIO
        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Criar perfil.\n");
        printf("[02] Alterar dados perfil.\n");
        printf("[03] Deletar perfil.\n");
        printf("[04] Imprimir todos os perfis.\n");
        printf("[05] Seguir / parar de seguir.\n");
        printf("[06] Alterar posts.\n");
        printf("[07] .\n");
        printf("[08] .\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - FIM


        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - INICIO
        switch (Escolha_do_usuario){
            case 0:
                /* EXECUÇÕES:
                * Impressão mensagem de encerramento do software
                */
                printf("\n            +-----------------------+\n");
                printf("            | Encerrando o software |\n");
                printf("            +-----------------------+\n\n");
            break;
            case 1:
                /* EXECUÇÕES:
                * 
                */
                InserirHashTable(Usuarios,GetInformacoesCriarPerfil(Usuarios));
            break;
            case 2:
                /* EXECUÇÕES:
                * 
                */
                AlterarInformacoesPerfil(Usuarios,GetPerfilAlvo(Usuarios));
            break;
            case 3:
                /* EXECUÇÕES:
                * 
                */
                DeletarPerfil(Usuarios);
            break;
            case 4:
                /* EXECUÇÕES:
                * 
                */
                ImprimirTODOSPerfis_HashTable(Usuarios);
            break;
            case 5:
                /* EXECUÇÕES:
                * 
                */
                Alterar_listaFollows(Usuarios,GetPerfilAlvo(Usuarios));
            break;
            case 6:
                /* EXECUÇÕES:
                * 
                */
                Alterar_listaPosts(Usuarios,GetPerfilAlvo(Usuarios));
            break;
            case 7:
                /* EXECUÇÕES:
                * 
                */
                NavegarEmUmPerfil(Usuarios,NULL,GetPerfilAlvo(Usuarios));
            break;
            case 8:
                /* EXECUÇÕES:
                * 
                */
            break;
            case 9:
                /* EXECUÇÕES:
                * 
                */
            break;
            case 10:
                /* EXECUÇÕES:
                * 
                */
            break;
            default:
                /* EXECUÇÕES:
                * Impressão informando escolha invalida dentre as opções
                */
                printf("\n+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - FIM
    }
    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - FIM


    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - INICIO
    // LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO - FIM
    

    // FINALIZAÇÃO COM EXITO DO SOFTWARE - INICIO
    return Sucesso;
    // FINALIZAÇÃO COM EXITO DO SOFTWARE - FIM
}