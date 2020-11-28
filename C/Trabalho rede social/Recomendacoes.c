/**
* @file   Recomendacoes.c
* @brief  Arquivo com a implementação das funções de 
*            manipulação dos dados recomendados.
* @author <Erik Neves>
* @date   2020-11-17
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"
#include "structs.h"
#include "Manipulacao_ListaEncadeada.h"
// INCLUSÃO DE BIBLIOTECAS - FIM

Error InicializarRecomendados(Recomendacoes * lista){
    /**
    * Função responsavel por inicializar a lista com as recomendacoes.
    * @return Sucesso caso ocorra tudo certo. 
    */
    lista->perfis = (Lista*)malloc(sizeof(Lista));
    lista->posts = (ListaPostagens*)malloc(sizeof(ListaPostagens));
    Inicializar_lista(lista->perfis);
    Inicializar_listaPost(lista->posts);
    return Sucesso;
}
Error InserirNovoPerfilRecomendado(DataType * New, Recomendacoes * lista){
    /**
    * Função responsavel por inserir um novo perfil recomendado.
    * @return Sucesso caso ocorra tudo certo. 
    */

    if(lista->perfis->CountFollows == Numero_de_recomendacoes){
        Remove_dado_MODOFILA(lista->perfis);
        Insere_dado_MODOFILA(New,lista->perfis);
    }else{
        Insere_dado_MODOFILA(New,lista->perfis);
    }

    return Sucesso;
}
Error RemoveIndexPerfilRecomedado(DataType * Alvo, Recomendacoes * lista){
    /**
    * Função responsavel por remover uma recomendação caso ela não seja mais valida. 
    * @return Sucesso caso ocorra tudo certo. 
    */
    Boolean DadoExistente = DadoContido_lista(lista->perfis,Alvo);
    if(DadoExistente == true) Remove_dado(Alvo,lista->perfis);

    return Sucesso;
}
Error ImprimirPerfisRecomendados(Recomendacoes * lista){
    /**
    * Função responsavel por imprimir os perfis recomendados. 
    * @return Sucesso caso ocorra tudo certo. 
    */
    int i;
    Item_lista * DadosPerfis;

    if(Lista_vazia(lista->perfis) != true){
        DadosPerfis = lista->perfis->primeira;
        printf("+----------------------+\n");
        printf("| Perfis recomendados: |\n");
        printf("+----------------------+\n");
        printf("| User name:\n");
        for(i=0;i<lista->perfis->CountFollows;i++){
            printf("| %s\n",DadosPerfis->DadosItem->NomeUsuario);
            DadosPerfis = DadosPerfis->Proximo;
        }
    }else{
        printf("+----------------------------------------+\n");
        printf("| Nao ha perfis recomendados no momento. |\n");
        printf("+----------------------------------------+\n");
    }
    printf("\n");

    return Sucesso;
}
Error InserirNovoPostRecomendado(Post * New, Recomendacoes * lista){
    /**
    * Função responsavel por por inserir um post perfil recomendado.
    * @return Sucesso caso ocorra tudo certo. 
    */

    if(lista->posts->NumeroDePostagens == Numero_de_recomendacoes){
        Remove_dadoPost_MODOFILA(lista->posts);
        Insere_dadoPost_MODOFILA(New,lista->posts);
    }else{
        Insere_dadoPost_MODOFILA(New,lista->posts);
    }

    return Sucesso;
}
Error RemoveIndexPostRecomedado(Post * Alvo, Recomendacoes * lista){
    /**
    * Função responsavel por remover uma recomendação caso ela não seja mais valida. 
    * @return Sucesso caso ocorra tudo certo. 
    */
    Boolean DadoExistente = DadoContido_listaPost(lista->posts,Alvo->ID);
    if(DadoExistente == true) Remove_dadoPost(Alvo,lista->posts);

    return Sucesso;
}
Error ImprimirPostsRecomendados(Recomendacoes * lista){
    /**
    * Função responsavel por imprimir os perfis recomendados. 
    * @return Sucesso caso ocorra tudo certo. 
    */
    int i;
    Item_Post * DadosPosts;

    if(Lista_vaziaPost(lista->posts) != true){
        DadosPosts = lista->posts->Primeira;
        printf("+-------------------------+\n");
        printf("| Postagens recomendadas: |\n");
        printf("+-------------------------+\n\n");
        for(i=0;i<lista->posts->NumeroDePostagens;i++){
            printf("| User: %-15s | Id: %.2d |\n| Post: %s\n\n",DadosPosts->dadosItem->Owner,DadosPosts->dadosItem->ID,DadosPosts->dadosItem->Postagem);
            DadosPosts = DadosPosts->Proxima;
        }
    }else{
        printf("+-------------------------------------------+\n");
        printf("| Nao ha postagens recomendadas no momento. |\n");
        printf("+-------------------------------------------+\n\n");
    }

    return Sucesso;
}
Error LimparRecomendacoes(Recomendacoes * recomendacoes){
    /**
    * Função responsavel por limpar a memoria das recomendações do software. 
    * @return Sucesso caso ocorra tudo certo. 
    */
    int i;
    Item_lista * DadosPerfis = recomendacoes->perfis->primeira;
    Item_lista * ProximoPerfilAux = NULL;
    Item_Post * DadosPosts = recomendacoes->posts->Primeira;
    Item_Post * ProximoPostAux = NULL;

    for(i=0;i<recomendacoes->perfis->CountFollows;i++){
        ProximoPerfilAux = DadosPerfis->Proximo;
        free(DadosPerfis);
        DadosPerfis = ProximoPerfilAux;
    }

    for(i=0;i<recomendacoes->posts->NumeroDePostagens;i++){
        ProximoPostAux = DadosPosts->Proxima;
        free(DadosPosts);
        DadosPosts = ProximoPostAux;
    }

    free(recomendacoes->perfis);
    free(recomendacoes->posts);
    free(recomendacoes);

    return Sucesso;
}