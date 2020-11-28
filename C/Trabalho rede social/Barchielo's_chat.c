/**
* @file   Barchielo's_chat.c
* @brief  Arquivo da união dos modulos de controle da 
*              rede social Barchielo's chat.
* @author <Erik Neves>
* @date   2020-11-15
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "constantes.h"
#include "Variaveis&interacoes.h"
#include "hash.h"
#include "DataBase.h"
#include "Recomendacoes.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


int main(int argc, char const *argv[]){
    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - INICIO
    Perfil * AtualUser = NULL;
    int Escolha_do_usuario = Variavel_de_inicio;
    HashTable * Usuarios = (HashTable*)malloc(sizeof(HashTable));
    Recomendacoes * Recommended = (Recomendacoes*)malloc(sizeof(Recomendacoes));
    // DECLARAÇÃO DE VARIAVEIS AUXILIARES A MAIN - FIM
    
    
    /* INICIALIZAÇÃO DA ESTRUTURA DE ARMAZENAMENTO DOS PERFIS */
    InicializarHashTable(Usuarios);

    /* INICIALIZAÇÃO DA ESTRUTURA DE RECOMENDAÇÕES */
    InicializarRecomendados(Recommended);

    /* CARREGAMENTO DOS DADOS ANTERIORES */
    LoadAllSavedData(Usuarios,Recommended);

    /* IMPRESSÃO DE MENSAGEM DE BEM VINDO */
    printf("\t+-------------------------------+\n");
    printf("\t| BEM VINDO AO BARCHIELO'S CHAT |\n");
    printf("\t+-------------------------------+\n\n");


    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - INICIO
    while(Escolha_do_usuario != Encerrar_loop){
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - INICIO
        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Ativar/trocar perfil atual.\n");
        printf("[02] Criar um novo perfil.\n");
        printf("[03] Deletar perfil atual.\n");
        printf("[04] Deletar outro perfil.\n");
        printf("[05] Imprimir todos os perfis.\n");
        printf("[06] Alterar dados do perfil atual.\n");
        printf("[07] Alterar dados de outro perfil.\n");
        printf("[08] Seguir/deixar de seguir um perfil.\n");
        printf("[09] Fazer/Deletar um post.\n");
        printf("[10] Visitar perfis.\n");
        printf("[11] ** Ver perfis/posts recomendados. **\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - FIM


        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - INICIO
        switch (Escolha_do_usuario){
            case 0:
                /* EXECUÇÕES:
                * Impressão mensagem de encerramento do software
                * Chamada da função para realização do salvamento 
                *            dos dados da rede social
                */
                printf("\n            +-----------------------+\n");
                printf("            | Encerrando o software |\n");
                printf("            +-----------------------+\n\n");
            break;
            case 1:
                /* EXECUÇÕES:
                * Chamada da função para a ativação/troca do perfil que esta em uso.
                */
                AtualUser = AtivarPerfil(Usuarios,AtualUser);
            break;
            case 2:
                /* EXECUÇÕES:
                * Chamada da função para a inserção de um novo perfil.
                * @Param Retorno de uma função que coleta os dados para um novo perfil.
                */
                InserirHashTable(Usuarios,GetInformacoesCriarPerfil(Usuarios,Recommended));
            break;
            case 3:
                /* EXECUÇÕES:
                * Chamada da função que remove o perfil atual do usuario.
                */
                AtualUser = DeletarPerfil(Usuarios,AtualUser,AtualUser,Recommended);
            break;
            case 4:
                /* EXECUÇÕES:
                * Chamada da função que remove um perfil.
                */
                AtualUser = DeletarPerfil(Usuarios,GetPerfilAlvo(Usuarios),AtualUser,Recommended);
            break;
            case 5:
                /* EXECUÇÕES:
                * Chamada da função que imprime para o usuario todos os perfis cadastrados.
                */
                ImprimirTODOSPerfis_HashTable(Usuarios);
            break;
            case 6:
                /* EXECUÇÕES:
                * Chamada da função para realizar alterações nos dados do perfil atual.
                */
                AlterarInformacoesPerfil(Usuarios,AtualUser);
            break;
            case 7:
                /* EXECUÇÕES:
                * Chamada da função para realizar alterações em um perfil.
                */
                AlterarInformacoesPerfil(Usuarios,GetPerfilAlvo(Usuarios));
            break;
            case 8:
                /* EXECUÇÕES:
                * Chamada da função para seguir ou deixar de seguir um perfil existente.
                */
                Alterar_listaFollows(Usuarios,AtualUser);
            break;
            case 9:
                /* EXECUÇÕES:
                * Chamada da função para fazer ou apagar um post.
                */
                Alterar_listaPosts(Usuarios,AtualUser,Recommended);
            break;
            case 10:
                /* EXECUÇÕES:
                * Chamada da função para navegar nos perfis, partindo do atual e podendo atingir
                *              todos que ele segue, incluindo o que os demais seguem.
                */
                NavegarEmUmPerfil(Usuarios,NULL,AtualUser);
            break;
            case 11:
                /* EXECUÇÕES:
                * Chamada da função para navegar nas recomendações de perfis e postagens
                */
                NavegarRecomendados(Usuarios,Recommended,AtualUser);
            break;
            default:
                /* EXECUÇÕES:
                * Impressão informando escolha invalida dentre as opções.
                */
                printf("\n+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
        // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - FIM
    }
    // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - FIM


    /* SAVE DOS DADOS ATUAIS */
    SaveAllData(Usuarios,Recommended);

    /* LIBERAÇÃO DE MEMORIA ANTES DO ENCERRAMENTO */
    LimparRecomendacoes(Recommended);
    LimparUsersHashTable(Usuarios);    

    /* FINALIZAÇÃO COM EXITO DO SOFTWARE */
    return Sucesso;
}