/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de lista duplamente encadeada.
 * @author <Erik Neves>
 * @date   2020-11-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"
#include "hash.h"
#include "Variaveis&interacoes.h"

// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (DATATYPE) - INICIO
Error Inicializar_lista(Lista * lista){

    lista->CountFollows = 0;
    lista->primeira = NULL;

    return Sucesso;
}
Error Insere_dado(DataType * Valor,Lista * lista){
    /* INSERE NO INICIO DA LISTA */
    Item_lista * Novo_dado = (Item_lista*)malloc(sizeof(Item_lista));

    Novo_dado->DadosItem = Valor;
    Novo_dado->Proximo = lista->primeira;
    Novo_dado->Anterior = NULL;
    if(lista->primeira != NULL){
        lista->primeira->Anterior = Novo_dado;
    }
    lista->CountFollows++;
    lista->primeira = Novo_dado;

    return Sucesso;
}
Error Remove_dado(DataType * Valor,Lista * lista){
    int i;
    Item_lista * Dado_anterior = NULL;
    Item_lista * Dado_proximo  = NULL;
    Item_lista * Dados_lista = lista->primeira;

    Boolean Valor_encontrado = false;

    for(i=0;i<lista->CountFollows;i++){
        if(strcmp(Dados_lista->DadosItem->NomeCompleto,Valor->NomeCompleto) == 0){
            Valor_encontrado = true;
            break;
        }
        Dado_anterior = Dados_lista;
        Dados_lista = Dados_lista->Proximo;
        Dado_proximo = Dados_lista->Proximo;
    }

    if(Valor_encontrado == true){
        lista->CountFollows--;
        if(Dados_lista->Anterior != NULL){
            Dados_lista->Anterior->Proximo = Dados_lista->Proximo;
            if(Dados_lista->Proximo != NULL){
                Dados_lista->Proximo->Anterior = Dados_lista->Anterior;
            }
        }else{
            if(Dados_lista->Proximo != NULL)Dados_lista->Proximo->Anterior = NULL;
            lista->primeira = Dados_lista->Proximo;
        }
        free(Dados_lista);
    }else if(Valor_encontrado == false){
        return Perfil_inexistente;
    }
    return Sucesso;
}
Boolean Lista_vazia(Lista * lista){
    return (lista->CountFollows == 0) ? true : false;
}
Error Imprimir_lista(Lista * lista){
    int i;
    Item_lista * Dados_lista = lista->primeira;
    DataType * Aux;

    if(Lista_vazia(lista) != true){
        printf("Perfis seguidos: \n");
        printf(" ID: | User:\n");
        for(i=0;i<lista->CountFollows;i++){
            Aux = Dados_lista->DadosItem;
            printf(" %.2d  | @%-25s\n",Aux->PerfilID,Aux->NomeUsuario);
            Dados_lista = Dados_lista->Proximo; 
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
Error Limpar_lista(Lista * lista){
    Item_lista * Dados_lista = lista->primeira;
    Item_lista * Proximo_aux = NULL;
    int i; 

    if(Lista_vazia(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->CountFollows;i++){
        Proximo_aux = Dados_lista->Proximo;
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    free(lista);
    return Sucesso;
}
Boolean DadoContido_lista(Lista * lista, DataType * DadoAlvo){
    Item_lista * Dados_lista = lista->primeira;
    Boolean DadoExistente = false; 
    int i;

    for(i=0;i<lista->CountFollows;i++){
        if(Dados_lista->DadosItem->PerfilID == DadoAlvo->PerfilID){
            DadoExistente = true;
            break;
        }
        Dados_lista = Dados_lista->Proximo;
    }

    return DadoExistente;
}
// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (DATATYPE) - FIM


// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (POST) - INICIO
Error Inicializar_listaPost(ListaPostagens * lista){

    lista->NumeroDePostagens = 0;
    lista->Primeira = NULL;

    return Sucesso;
}
Error Insere_dadoPost(Post * Valor,ListaPostagens * lista){
    /* INSERE NO INICIO DA LISTA */
    Item_Post * NovoPost = (Item_Post*)malloc(sizeof(Item_Post));

    NovoPost->dadosItem = Valor;
    NovoPost->Proxima = lista->Primeira;
    NovoPost->Anterior = NULL;
    if(lista->Primeira != NULL){
        lista->Primeira->Anterior = NovoPost;
    }
    lista->NumeroDePostagens++;
    lista->Primeira = NovoPost;

    return Sucesso;
}
Error Remove_dadoPost(Post * Valor,ListaPostagens * lista){
    int i;
    Item_Post * Dado_anterior = NULL;
    Item_Post * Dado_proximo  = NULL;
    Item_Post * Dados_lista = lista->Primeira;

    Boolean Valor_encontrado = false;

    for(i=0;i<lista->NumeroDePostagens;i++){
        if(Dados_lista->dadosItem->ID == Valor->ID){
            Valor_encontrado = true;
            break;
        }
        Dado_anterior = Dados_lista;
        Dados_lista = Dados_lista->Proxima;
        Dado_proximo = Dados_lista->Proxima;
    }

    if(Valor_encontrado == true){
        lista->NumeroDePostagens--;
        if(Dados_lista->Anterior != NULL){
            Dados_lista->Anterior->Proxima = Dados_lista->Proxima;
            if(Dados_lista->Proxima != NULL){
                Dados_lista->Proxima->Anterior = Dados_lista->Anterior;
            }
        }else{
            if(Dados_lista->Proxima != NULL)Dados_lista->Proxima->Anterior = NULL;
            lista->Primeira = Dados_lista->Proxima;
        }
        free(Dados_lista);
    }else if(Valor_encontrado == false){
        return Perfil_inexistente;
    }
    return Sucesso;
}
Boolean Lista_vaziaPost(ListaPostagens * lista){
    return (lista->NumeroDePostagens == 0) ? true : false;
}
Error RemoveCurtidas(ListaPostagens * lista, DataType * Removido){
    int i;
    Item_Post * DadosPostagens = lista->Primeira;

    for(i=0;i<lista->NumeroDePostagens;i++){
        RemoverDadoHashTable(DadosPostagens->dadosItem->Curtidas,Removido->NomeUsuario);
        DadosPostagens = DadosPostagens->Proxima;
    }

    return Sucesso;
}
Error Imprimir_listaPost(ListaPostagens * lista,DataType * Visual){
    int i;
    Item_Post * Dados_lista = lista->Primeira;
    Post * Aux;
    Boolean Curtiu = false;

    if(Lista_vaziaPost(lista) != true){
        printf("Postagens(%.2d ultimas): \n",ImpressaoDePosts);
        printf(" ID: | Post:\n");
        for(i=0;i<ImpressaoDePosts;i++){
            if(Dados_lista != NULL){
                Aux = Dados_lista->dadosItem;
                //CheckExistenciaPerfis_Curtidas(Aux);
                printf(" %.2d  | %s\n",Aux->ID,Aux->Postagem);
                Curtiu = DadoExistenteHashTable(Aux->Curtidas,Visual);
                if(Curtiu == true){
                    printf("(%.2d)-> Voce curtiu essa postagem.\n",Aux->ID);
                }
                Dados_lista = Dados_lista->Proxima;
            }
        }
        printf("\n");
    }else{
        return Erro_lista_vazia;
    }
    return Sucesso;
}
Error Limpar_listaPost(ListaPostagens * lista,Boolean bool){
    Item_Post * Dados_lista = lista->Primeira;
    Item_Post * Proximo_aux = NULL;
    int i; 

    if(Lista_vaziaPost(lista) == true){
        return Erro_lista_vazia;
    }
    for(i=0;i<lista->NumeroDePostagens;i++){
        Proximo_aux = Dados_lista->Proxima;
        if(bool == true)LimparPostHashTable(Dados_lista->dadosItem->Curtidas);
        free(Dados_lista);
        Dados_lista = Proximo_aux;
    }
    free(lista);
    return Sucesso;
}
Boolean DadoContido_listaPost(ListaPostagens * lista, unsigned int IDDadoAlvo){
    Item_Post * Dados_lista = lista->Primeira;
    Boolean DadoExistente = false; 
    int i;

    for(i=0;i<lista->NumeroDePostagens;i++){
        if(Dados_lista->dadosItem->ID == IDDadoAlvo){
            DadoExistente = true;
            break;
        }
    }

    return DadoExistente;
}
// IMPLEMENTAÇÃO MANIPULAÇÃO LISTA DP. ENCADEADA (POST) - FIM