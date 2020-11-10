/*
 * @file   Variaveis&interacoes.c
 * @brief  Arquivo com implementação das funções para interagir com o usuario
 *                  & variavies constantemente acessadas.
 * @author <Erik Neves>
 * @date   2020-11-08
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "constantes.h"
#include "Manipulacao_ListaEncadeada.h"
#include "hash.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int GetColunaPerfil(char * string){
    int count = 0;
    int i;
    
    for(i=0;i<strlen(string);i++){
        count += (int)string[i];
    }
    //printf("%s : %d\n",string,count);
    count =  (count/10);
    //printf("count : %d\n",count);
    return (int)count;
}
static int GetIdPerfil(){
    static int ID = 1;
    return ID++;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
DataType * GetInformacoesCriarPerfil(HashTable * table){
    DataType * NovoPerfil = (DataType*)malloc(sizeof(DataType));
    Item_lista * DadosColuna = NULL;
    Boolean UsuarioValido = false;
    int ColunaId;

    NovoPerfil->PerfilID = GetIdPerfil();
    setbuf(stdin,NULL);
    printf("\nDigite o seu nome completo(Max.:%.3d): ",Tamanho_MAX_NomeCompleto-1);
    scanf("%[^\n]s", NovoPerfil->NomeCompleto);
    
    while(UsuarioValido == false){
        setbuf(stdin,NULL);
        printf("Digite seu nome de usuario(Max.:%.3d): ",Tamanho_MAX_usuario-1);
        scanf("%[^\n]s", NovoPerfil->NomeUsuario);
        setbuf(stdin,NULL);

        ColunaId = (GetColunaPerfil(NovoPerfil->NomeUsuario) - 1);

        if(ColunaId >= table->NumeroDeColunas) UsuarioValido = true;
        if(UsuarioValido == false){
            if(table->DadosTabela[ColunaId] == NULL){
                UsuarioValido = true;
            }else{
                UsuarioValido = true;
                DadosColuna = table->DadosTabela[ColunaId];
                while(DadosColuna != NULL){
                    if(strcmp(DadosColuna->DadosItem->NomeUsuario,NovoPerfil->NomeUsuario) == 0){
                        UsuarioValido = false;
                        break;
                    }
                    DadosColuna = DadosColuna->Proximo;
                }
            }
        }
        if(UsuarioValido == false){
            printf("\n");
            printf("+-------------------------------+\n");
            printf("| Nome de usuario ja cadastrado |\n");
            printf("|        Tente novamente!       |\n");
            printf("+-------------------------------+\n");
            printf("\n");
        }
    }

    printf("Digite sua biografia(Max.:%.3d): ",Tamanho_MAX_bio-1);
    scanf("%[^\n]s", NovoPerfil->Biografia);
    setbuf(stdin,NULL);

    NovoPerfil->PerfilSeguindo = (Followed_list*)malloc(sizeof(Followed_list));
    Inicializar_lista(NovoPerfil->PerfilSeguindo);

    printf("\n");
    printf("+---------------------------+\n");
    printf("| Perfil criado com sucesso |\n");
    printf("+---------------------------+\n");
    printf("\n");

    return NovoPerfil;
}
int GetColunaAlvo(HashTable * table){
    int ColunaID;

    printf("\nDigite o numero da coluna desejada(Max. ID: %.4d): ",table->NumeroDeColunas);
    scanf("%d", &ColunaID);

    return ColunaID;
}
Error PerfilNaoEncontrado(){
    printf("\n+-----------------------+\n");
    printf("| Perfil nao encontrado |\n");
    printf("+-----------------------+\n\n");
    return Sucesso;
}
Error PerfilDeletado(unsigned int id){
    printf("\n+-------------------------------------+\n");
    printf("| Perfil(ID: %.2d) deletado com sucesso |\n",id);
    printf("+-------------------------------------+\n\n");
    return Sucesso;
}
DataType * GetPerfilAlvo(HashTable * table){
    DataType * Alvo = NULL;
    Item_lista * DadosColuna = NULL;
    char NomeProcurado[Tamanho_MAX_usuario];
    int ColunaID;

    setbuf(stdin,NULL);
    printf("\nDigite o nome de usuario do perfil: ");
    scanf("%[^\n]s", NomeProcurado);
    setbuf(stdin,NULL);

    ColunaID = (GetColunaPerfil(NomeProcurado) - 1);
    if(ColunaID < 0 || ColunaID >= table->NumeroDeColunas) return Alvo;
    if(table->DadosTabela[ColunaID] == NULL) return Alvo;

    DadosColuna = table->DadosTabela[ColunaID];
    while(DadosColuna != NULL){
        if(strcmp(NomeProcurado,DadosColuna->DadosItem->NomeUsuario) == 0){
            Alvo = DadosColuna->DadosItem;
            break;
        }
        DadosColuna = DadosColuna->Proximo;
    }

    return Alvo;
}
Error AlterarInformacoesPerfil(HashTable * table,DataType * DadoAlvo){
    int Escolha_do_usuario = Variavel_de_inicio;
    int i;
    int ColunaID;
    Boolean CamposAlterados[Iten_Alteraveis_Perfil];
    Boolean UsuarioValido = false;
    DataType * Aux = (DataType*)malloc(sizeof(DataType));
    Item_lista * DadosColuna = NULL;

    if(DadoAlvo == NULL){
        PerfilNaoEncontrado();
        return Perfil_inexistente;
    }

    for(i=0;i<Iten_Alteraveis_Perfil;i++)CamposAlterados[i] = false;
    RemoverDadoHashTable(table,DadoAlvo->NomeUsuario);

    printf("\n+------------------------------------+\n");
    printf("| Realizar alteracoes no seu perfil: |\n");
    printf("+------------------------------------+\n");

    while(Escolha_do_usuario != Encerrar_loop){
        
        printf("\nQual alteracao deseja realizar: \n");
        printf("[00] Encerrar alteracoes.\n");
        printf("[01] Alterar o nome do perfil.\n");
        printf("[02] Alterar o nome de usuario.\n");
        printf("[03] Alterar a biografia.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");

        switch (Escolha_do_usuario){
            case 0:
                printf("| Encerrando alteracoes |\n");
            break;
            case 1:
                CamposAlterados[0] = true;
                setbuf(stdin,NULL);
                printf("\nDigite o novo nome do perfil(Max.:%.3d): ",Tamanho_MAX_NomeCompleto-1);
                scanf("%[^\n]s", Aux->NomeCompleto);
                setbuf(stdin,NULL);
            break;
            case 2:
                CamposAlterados[1] = true;
                setbuf(stdin,NULL);
                printf("Digite o novo nome de usuario(Max.:%.3d): ",Tamanho_MAX_usuario-1);
                scanf("%[^\n]s", Aux->NomeUsuario);
                setbuf(stdin,NULL);

                ColunaID = (GetColunaPerfil(Aux->NomeUsuario) - 1);

                if(ColunaID >= table->NumeroDeColunas) UsuarioValido = true;
                if(UsuarioValido == false){
                    if(table->DadosTabela[ColunaID] == NULL){
                        UsuarioValido = true;
                    }else{
                        UsuarioValido = true;
                        DadosColuna = table->DadosTabela[ColunaID];
                        while(DadosColuna != NULL){
                            if(strcmp(DadosColuna->DadosItem->NomeUsuario,Aux->NomeUsuario) == 0){
                                UsuarioValido = false;
                                break;
                            }
                            DadosColuna = DadosColuna->Proximo;
                        }
                    }
                }
                if(UsuarioValido == false){
                    CamposAlterados[1] = false;
                    printf("\n");
                    printf("+-------------------------------+\n");
                    printf("| Nome de usuario ja cadastrado |\n");
                    printf("|        Tente novamente!       |\n");
                    printf("+-------------------------------+\n");
                    printf("\n");
                }
            break;
            case 3:
                CamposAlterados[2] = true;
                setbuf(stdin,NULL);
                printf("Digite sua nova biografia(Max.:%.3d): ",Tamanho_MAX_bio-1);
                scanf("%[^\n]s", Aux->Biografia);
                setbuf(stdin,NULL);
            break;
            default:
                printf("\n| Escolha invalida... Tente novamente! |\n\n");
            break;
        }
    }

    printf("\nEssas sao as novas informacoes do perfil: \n");
    if(CamposAlterados[0] == true) printf("Nome: %s\n",Aux->NomeCompleto);
    if(CamposAlterados[0] == false) printf("Nome: %s\n",DadoAlvo->NomeCompleto);
    if(CamposAlterados[1] == true) printf("Usuario: %s\n",Aux->NomeUsuario);
    if(CamposAlterados[1] == false) printf("Usuario: %s\n",DadoAlvo->NomeUsuario);
    if(CamposAlterados[2] == true) printf("Biografia: %s\n",Aux->Biografia);
    if(CamposAlterados[2] == false) printf("Biografia: %s\n",DadoAlvo->Biografia);
    printf("\nDeseja salvar as alteracoes ou deleta-las: \n");
    printf("[00] Salva-las.\n");
    printf("[01] Deleta-las.\n");
    printf("Escolha: ");
    scanf("%d",&Escolha_do_usuario);

    if(Escolha_do_usuario == 0){
        if(CamposAlterados[0] == true) strcpy(DadoAlvo->NomeCompleto,Aux->NomeCompleto);
        if(CamposAlterados[1] == true) strcpy(DadoAlvo->NomeUsuario,Aux->NomeUsuario);
        if(CamposAlterados[2] == true) strcpy(DadoAlvo->Biografia,Aux->Biografia);   
        printf("\n| Alteracoes salvas. |\n\n");
    }else{
        printf("\n| Alteracoes deletadas. |\n\n");
    }
    free(Aux);
    InserirHashTable(table, DadoAlvo);

    return Sucesso;
}
Error StartNewFollow(HashTable * table,DataType * perfil){
    //DataType * NovoFollow = GetPerfilAlvo(table);
    DataType * NovoFollow;
    Boolean ListarPerfis = false;
    int Escolha_do_usuario = Variavel_de_inicio;

    printf("Deseja ver uma lista com os perfis:\n");
    printf("[00] Sim.\n");
    printf("[01] Nao.\n");
    printf("Escolha: ");
    scanf("%d",&ListarPerfis);

    if(ListarPerfis == true) ImprimirTODOSPerfis_HashTable(table);

    while(Escolha_do_usuario != Encerrar_loop){

        NovoFollow = GetPerfilAlvo(table);
        if(NovoFollow == NULL){
            PerfilNaoEncontrado();
        }else if(NovoFollow->PerfilID == perfil->PerfilID){
            printf("\n+-------------------------+\n");
            printf("| Voce nao pode se seguir |\n");
            printf("+-------------------------+\n\n");
        }else if(DadoContido_lista(perfil->PerfilSeguindo,NovoFollow) == true){
            printf("\n+---------------------------+\n");
            printf("| Voce ja segue esse perfil |\n");
            printf("+---------------------------+\n\n");
        }else{
            Insere_dado(NovoFollow,perfil->PerfilSeguindo);
        }

        printf("Deseja seguir mais perfis: \n");
        printf("[00] Nao.\n");
        printf("[01] Sim.\n");
        printf("Escolha: ");
        scanf("%d",&Escolha_do_usuario);
    }
    printf("\n");

    return Sucesso;
}
Error StopFollow(HashTable * table, DataType * perfil){
    Boolean VerListaFollows = false;
    DataType * EncerrarFollow;
    Error RemoveReturn;

    int Escolha_do_usuario = Variavel_de_inicio;

    printf("Deseja ver os perfis que voce segue:\n");
    printf("[00] Sim.\n");
    printf("[01] Nao.\n");
    printf("Escolha: ");
    scanf("%d",&VerListaFollows);
    printf("\n");

    if(VerListaFollows == true) Imprimir_lista(perfil->PerfilSeguindo);

    while(Escolha_do_usuario != Encerrar_loop){

        EncerrarFollow = GetPerfilAlvo(table);
        if(EncerrarFollow == NULL){
            PerfilNaoEncontrado();
        }else{
            RemoveReturn = Remove_dado(EncerrarFollow,perfil->PerfilSeguindo);
            if(RemoveReturn == Perfil_inexistente){
                PerfilNaoEncontrado();
            }else if(RemoveReturn == Sucesso){
                printf("\n+-----------------------------+\n");
                printf("| Follow removido com sucesso |\n");
                printf("+-----------------------------+\n\n");
            }
        }

        printf("Deseja deixar de seguir mais perfis: \n");
        printf("[00] Nao.\n");
        printf("[01] Sim.\n");
        printf("Escolha: ");
        scanf("%d",&Escolha_do_usuario);
    }
    printf("\n");

    return Sucesso;
}
Error Alterar_listaFollows(HashTable * table, DataType * perfil){
    int i;
    int Escolha_do_usuario = Variavel_de_inicio;

    printf("\n+--------------------------------------------+\n");
    printf("| Siga outros perfis para ver suas postagens |\n");
    printf("+--------------------------------------------+\n\n");
    while(Escolha_do_usuario != Encerrar_loop){
        printf("Oque deseja fazer:\n");
        printf("[00] Encerrar buscas.\n");
        printf("[01] Seguir um novo perfil.\n");
        printf("[02] Deixar de serguir um perfil.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");

        switch (Escolha_do_usuario){
            case 0:
                printf("+-----------------------+\n");
                printf("| Manipulacao encerrada |\n");
                printf("+-----------------------+\n\n");
            break;
            case 1:
                StartNewFollow(table,perfil);
            break;
            case 2:
                StopFollow(table,perfil);
            break;
            default:
                printf("+--------------------------------------+\n");
                printf("| Escolha invalida... Tente novamente! |\n");
                printf("+--------------------------------------+\n\n");
            break;
        }
    }
    return Sucesso;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM