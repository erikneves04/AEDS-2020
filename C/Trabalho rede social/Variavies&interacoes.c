/**
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
#include "warnings.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int GetColunaPerfil(char * string){
    /**
    * Função responsavel por calcular a coluna de uma string em uma tabela hash.
    * @return identificador para uma coluna.
    */
    int count = 0;
    int i;
    
    for(i=0;i<strlen(string);i++){
        count += (int)string[i];
    }
    count =  (count/10);
    return (int)count;
}
int GetIdPerfil(){
    /**
    * Função responsavel por calcular o id de um novo perfil.
    * @return identificador.
    */
    static int ID = 1;
    return ID++;
}
int GetIdPost(){
    /**
    * Função responsavel por calcular o id de um novo post.
    * @return identificador.
    */
    static int PostID = 1;
    return PostID++;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
DataType * AtivarPerfil(HashTable * table,DataType * PerfilAtual){
    /**
    * Função responsavel por localizar um perfil para ser ativado.
    * @return ponteiro para um perfil.
    */
    DataType * PerfilAlvo = NULL;
    Item_lista * DadosColuna;
    Boolean PerfilEncontrado = false;
    Boolean ListarPerfis = false;
    Boolean ColunaInvalida = false;
    Error ReturnUser;
    char NomeProcurado[Tamanho_MAX_usuario];
    int ColunaID;

    printf("\n\t+-----------------------+\n");
    printf("\t| Ativacao de um perfil |\n");
    printf("\t+-----------------------+\n");

    if(PerfilAtual != NULL){
        printf("Ola @%s, esperamos que retorne em breve.\n\n",PerfilAtual->NomeUsuario);
    }

    printf("Deseja ver uma lista com os perfis cadastrados:\n");
    printf("[00] Sim.\n");
    printf("[01] Nao.\n");
    printf("Escolha: ");
    scanf("%d",&ListarPerfis);

    if(ListarPerfis == true) ReturnUser = ImprimirTODOSPerfis_HashTable(table);

    if(ReturnUser != Perfil_inexistente && table->NumeroDeColunas != 0){
        setbuf(stdin,NULL);
        printf("\nDigite o nome de usuario do perfil: ");
        scanf("%[^\n]s", NomeProcurado);
        setbuf(stdin,NULL);
    }else{
        if(ListarPerfis == false){
            printf("\n+------------------------------------------+\n");
            printf("| Desculpe, mas nao ha perfis cadastrados. |\n");
            printf("+------------------------------------------+\n\n");
        }
    }

    ColunaID = (GetColunaPerfil(NomeProcurado) - 1);
    if(ColunaID < 0 || ColunaID >= table->NumeroDeColunas)ColunaInvalida = true;
    if(table->DadosTabela[ColunaID] == NULL)ColunaInvalida = true;

    if(ColunaInvalida != true){
        DadosColuna = table->DadosTabela[ColunaID];
        while(DadosColuna != NULL){
            if(strcmp(NomeProcurado,DadosColuna->DadosItem->NomeUsuario) == 0){
                PerfilAlvo = DadosColuna->DadosItem;
                PerfilEncontrado = true;
                break;
            }
            DadosColuna = DadosColuna->Proximo;
        }
    }

    if(PerfilEncontrado == false && ReturnUser == Sucesso)PerfilNaoEncontrado();
    if(PerfilEncontrado == true){
        PerfilAtual = PerfilAlvo;
        printf("Perfil @%s ativado com sucesso.\n\n",PerfilAtual->NomeUsuario);
    }
    return PerfilAlvo;
}
DataType * GetInformacoesCriarPerfil(HashTable * table){
    /**
    * Função responsavel por alocar e coletar as informações de um novo perfil.
    * @return ponteiro para um novo perfil.
    */
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
        if(strcmp("",NovoPerfil->NomeUsuario) == 0)UsuarioValido = false;
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
    NovoPerfil->Seguidores = (Followed_list*)malloc(sizeof(Followed_list));
    Inicializar_lista(NovoPerfil->Seguidores);
    NovoPerfil->Postagens = (ListaPostagens*)malloc(sizeof(ListaPostagens));
    Inicializar_listaPost(NovoPerfil->Postagens);
    NovoPerfil->PostagensCurtidas = (ListaPostagens*)malloc(sizeof(ListaPostagens));
    Inicializar_listaPost(NovoPerfil->PostagensCurtidas);

    printf("\n");
    printf("+---------------------------+\n");
    printf("| Perfil criado com sucesso |\n");
    printf("+---------------------------+\n");
    printf("\n");

    return NovoPerfil;
}
DataType * GetPerfilAlvo(HashTable * table){
    /**
    * Função responsavel por localizar um perfil procurado.
    * @return ponteiro para um perfil.
    */
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
Post * GetPostAlvo(ListaPostagens * lista){
    /**
    * Função responsavel por localizar uma postagem existente.
    * @return ponteiro para uma postagem.
    */
    Item_Post * DadosLista = lista->Primeira;
    int IDPost;
    int i;

    printf("Digite o ID da postagem: ");
    scanf("%d", &IDPost);

    for(i=0;i<lista->NumeroDePostagens;i++){
        if(DadosLista->dadosItem->ID == IDPost){
            return DadosLista->dadosItem;
        }
        DadosLista = DadosLista->Proxima;
    }

    return NULL;;
}
Error AlterarInformacoesPerfil(HashTable * table,DataType * DadoAlvo){
    /**
    * Função responsavel por alterar as informações do pefil ativo atualmente.
    * @return Sucesso caso ocorra tudo certo.
    */
    int Escolha_do_usuario = Variavel_de_inicio;
    int i;
    int ColunaID;
    Boolean CamposAlterados[Iten_Alteraveis_Perfil];
    Boolean UsuarioValido = false;
    DataType * Aux = (DataType*)malloc(sizeof(DataType));
    Item_lista * DadosColuna = NULL;

    if(DadoAlvo == NULL){
        AtivacaoDefault();
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
        printf("[01] Imprimir os dados atuais.\n");
        printf("[02] Alterar o nome do perfil.\n");
        printf("[03] Alterar o nome de usuario.\n");
        printf("[04] Alterar a biografia.\n");
        printf("Escolha: ");
        scanf("%d", &Escolha_do_usuario);
        printf("\n");

        switch (Escolha_do_usuario){
            case 0:
                printf("| Encerrando alteracoes |\n");
            break;
            case 1:
                printf("\nNome: %s\n",DadoAlvo->NomeCompleto);
                printf("Usuario: %s\n",DadoAlvo->NomeUsuario);
                printf("Biografia: %s\n\n",DadoAlvo->Biografia);
            break;
            case 2:
                CamposAlterados[0] = true;
                setbuf(stdin,NULL);
                printf("\nDigite o novo nome do perfil(Max.:%.3d): ",Tamanho_MAX_NomeCompleto-1);
                scanf("%[^\n]s", Aux->NomeCompleto);
                setbuf(stdin,NULL);
            break;
            case 3:
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
            case 4:
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
    
    printf("\nDeseja manter ou retroceder: \n");
    printf("[00] Manter os novos dados.\n");
    printf("[01] Retroceder aos antigos.\n");
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
    /**
    * Função responsavel por identificar e seguir um novo perfil.
    * @return Sucesso caso ocorra tudo certo.
    */
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
            Insere_dado(perfil,NovoFollow->Seguidores);
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
    /**
    * Função responsavel por identificar e deixar de seguir um perfil.
    * @return Sucesso caso ocorra tudo certo.
    */
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
                Remove_dado(perfil,EncerrarFollow->Seguidores);
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
    /**
    * Função que permite o usuario alterar quem ele segue ou ver esses dados.
    * @return Sucesso caso ocorra tudo certo.
    */
    int i;
    int Escolha_do_usuario = Variavel_de_inicio;

    if(perfil == NULL){
        AtivacaoDefault();
        return Perfil_inexistente;
    }

    printf("\n+--------------------------------------------+\n");
    printf("| Siga outros perfis para ver suas postagens |\n");
    printf("+--------------------------------------------+\n\n");
    while(Escolha_do_usuario != Encerrar_loop){
        printf("Oque deseja fazer:\n");
        printf("[00] Encerrar buscas.\n");
        printf("[01] Seguir um novo perfil.\n");
        printf("[02] Deixar de serguir um perfil.\n");
        printf("[03] Ver os perfis que voce segue.\n");
        printf("[04] Ver os perfis que seguem voce.\n");
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
            case 3:
                Imprimir_lista(perfil->PerfilSeguindo);
            break;
            case 4:
                Imprimir_lista(perfil->Seguidores);
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
Error RealizarPostagem(HashTable * table, DataType * perfil){
    /**
    * Função resposavel por realizar uma nova postagem.
    * @return Sucesso caso ocorra tudo certo.
    */
    int i;
    int Escolha_do_usuario = Variavel_de_inicio;
    Post * NovaPostagem = (Post*)malloc(sizeof(Post));

    printf("+--------------------------------+\n");
    printf("|   No que voce esta pensando?   |\n");
    printf("|  Compartilhe com a comunidade! |\n");
    printf("+--------------------------------+\n\n");

    NovaPostagem->ID = GetIdPost();
    printf("Digite a mensagem da postagem: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]s",NovaPostagem->Postagem);
    setbuf(stdin,NULL);

    Insere_dadoPost(NovaPostagem,perfil->Postagens);
    NovaPostagem->Curtidas = (HashTable*)malloc(sizeof(HashTable));;
    InicializarHashTable(NovaPostagem->Curtidas);

    printf("\n+--------------------------------+\n");
    printf("| Postagem realizada com sucesso |\n");
    printf("+--------------------------------+\n\n");

    return Sucesso;
}
Error DeletarPostagem(HashTable * table, DataType * perfil){
    /**
    * Função resposavel por apagar uma postagem existente.
    * @return Sucesso caso ocorra tudo certo.
    */
    Boolean VerListaFollows = false;
    Post * Deletarpost;
    Error RemoveReturn;

    int Escolha_do_usuario = Variavel_de_inicio;

    printf("Deseja ver uma lista com suas postagens:\n");
    printf("[00] Sim.\n");
    printf("[01] Nao.\n");
    printf("Escolha: ");
    scanf("%d",&VerListaFollows);
    printf("\n");

    if(VerListaFollows == true) Imprimir_listaPost(perfil->Postagens,NULL);

    while(Escolha_do_usuario != Encerrar_loop){

        Deletarpost = GetPostAlvo(perfil->Postagens);
        if(Deletarpost == NULL){
            PostNaoEncontrado();
        }else{
            RemoveReturn = Remove_dadoPost(Deletarpost,perfil->Postagens);
            if(RemoveReturn == Perfil_inexistente){
                PostNaoEncontrado();
            }else if(RemoveReturn == Sucesso){
                printf("\n+-------------------------------+\n");
                printf("| Postagem removida com sucesso |\n");
                printf("+-------------------------------+\n\n");
            }
        }

        printf("Deseja realizar mais alteracoes: \n");
        printf("[00] Nao.\n");
        printf("[01] Sim.\n");
        printf("Escolha: ");
        scanf("%d",&Escolha_do_usuario);
    }
    printf("\n");

    return Sucesso;
}
Error Alterar_listaPosts(HashTable * table, DataType * perfil){
    /**
    * Função que permite o usuario alterar suas postagens ou ver os dados das mesmas.
    * @return Sucesso caso ocorra tudo certo.
    */
    int i;
    int Escolha_do_usuario = Variavel_de_inicio;

    if(perfil == NULL){
        AtivacaoDefault();
        return Perfil_inexistente;
    }

    printf("\n+---------------------------------+\n");
    printf("| Manipule suas postagens aqui!!! |\n");
    printf("+---------------------------------+\n\n");

    while(Escolha_do_usuario != Encerrar_loop){
        printf("Oque deseja fazer:\n");
        printf("[00] Encerrar alteracoes.\n");
        printf("[01] Realizar nova postagem.\n");
        printf("[02] Deletar uma postagem existente.\n");
        printf("[03] Imprimir suas postagens.\n");
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
                RealizarPostagem(table,perfil);
            break;
            case 2:
                DeletarPostagem(table,perfil);
            break;
            case 3:
                Imprimir_listaPost(perfil->Postagens,perfil);
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
Error NavegarEmUmPerfil(HashTable * table,DataType * perfil, DataType * PerfilInicial){
    /**
    * Função que permite o usuario navegar entre os perfis que ele segue e seus conhecidos.
    * @return Sucesso caso ocorra tudo certo.
    */
    int Escolha_do_usuario = Variavel_de_inicio;
    char UserProcurado[Tamanho_MAX_usuario];
    int i;
    int IDPost;
    Post * Postagem;
    Item_lista * DadosFollows;
    Boolean PerfilEncontrado = false;

    if(PerfilInicial == NULL) {
        AtivacaoDefault();
        return Perfil_inexistente;
    }
    if(perfil == NULL)perfil = PerfilInicial;

    printf("\nPerfil atual: %s\n",perfil->NomeCompleto);
    printf("Nome de Usuario: %s\n",perfil->NomeUsuario);
    printf("Biografia: %s\n\n",perfil->Biografia);

    while (Escolha_do_usuario != Encerrar_loop){
        printf("Oque deseja fazer @%s:\n",PerfilInicial->NomeUsuario);
        printf("[00] Encerrar.\n");
        printf("[01] Listar quem o perfil segue.\n");
        printf("[02] Visitar um perfil seguido.\n");
        printf("[03] Ver as postagens.\n");
        printf("[04] Curtir uma postagem.\n");
        printf("[05] Descurtir uma postagem.\n");
        printf("[06] Detalhar uma postagem.\n");
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
                Imprimir_lista(perfil->PerfilSeguindo);
            break;
            case 2:
                printf("Digite o nome de usuario do perfil para visitar:");
                setbuf(stdin,NULL);
                scanf("%[^\n]s", UserProcurado);
                setbuf(stdin,NULL);

                DadosFollows = perfil->PerfilSeguindo->primeira;
                if(DadosFollows != NULL){    
                    for(i=0;i<perfil->PerfilSeguindo->CountFollows;i++){
                        if(strcmp(UserProcurado,DadosFollows->DadosItem->NomeUsuario) == 0){
                            PerfilEncontrado = true;
                            NavegarEmUmPerfil(table,DadosFollows->DadosItem,PerfilInicial);
                            if(perfil->PerfilID != PerfilInicial->PerfilID) Escolha_do_usuario = Encerrar_loop;
                        }
                        DadosFollows = DadosFollows->Proximo;
                    }
                }
                if(PerfilEncontrado == false) PerfilNaoEncontrado();
                PerfilEncontrado = false;
            break;
            case 3:
                Imprimir_listaPost(perfil->Postagens,PerfilInicial);
            break;
            case 4:
                Postagem = GetPostAlvo(perfil->Postagens);
                if(Postagem == NULL) {
                    PostNaoEncontrado();
                }else if(DadoExistenteHashTable(Postagem->Curtidas,PerfilInicial) == true){
                    printf("\n+--------------------------+\n");
                    printf("| Voce ja curtiu este post |\n");
                    printf("+--------------------------+\n\n");
                }else{
                    Insere_dadoPost(Postagem,PerfilInicial->PostagensCurtidas);
                    InserirHashTable(Postagem->Curtidas,PerfilInicial);
                }
            break;
            case 5:
                Postagem = GetPostAlvo(perfil->Postagens);
                if(Postagem == NULL) {
                    PostNaoEncontrado();
                }else if(DadoExistenteHashTable(Postagem->Curtidas,PerfilInicial) == false){
                    printf("\n+----------------------------+\n");
                    printf("| Voce nao curtiu este post! |\n");
                    printf("+----------------------------+\n\n");
                }else{
                    Remove_dadoPost(Postagem,PerfilInicial->PostagensCurtidas);
                    RemoverDadoHashTable(Postagem->Curtidas,PerfilInicial->NomeUsuario);
                }
            break;
            case 6:
                Postagem = GetPostAlvo(perfil->Postagens);
                if(Postagem == NULL) {
                    PostNaoEncontrado();
                }else{
                    printf("Identificador: %.3d\n",Postagem->ID);
                    printf("Postagem: %s",Postagem->Postagem);
                    ImprimirTODOSCurtidas_HashTable(Postagem);
                }
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