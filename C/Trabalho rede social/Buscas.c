/**
* @file   Buscas.c
* @brief  Arquivo com implementação das funções para buscar dados no software.
* @author <Erik Neves>
* @date   2020-11-18
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "Manipulacao_ListaEncadeada.h"
#include "hash.h"
// INCLUSÃO DE BIBLIOTECAS - FIM

Error LoadVerticesNaLista(Lista * FilaDeVertices,Lista * Dados,DataType * Inicial, int * EstadoAcessos,int count){
    /**
    * Função que carrega os perfis seguidos em uma lista.
    * @return Sucesso caso ocorra tudo certo.
    */
    int i,j;
    Boolean BuscaEncerrada = false;
    Item_lista * ArestraAux;
    DataType * VerticeAtual = Inicial;
    int ContagemDistancia = count;

    for(i=0;i<Inicial->PerfilSeguindo->CountFollows;i++){   
        ArestraAux = VerticeAtual->PerfilSeguindo->primeira;
        for(j=0;j<VerticeAtual->PerfilSeguindo->CountFollows;j++){
            if(EstadoAcessos[VerticeAtual->PerfilID] == preto) break;
            //printf("%s %d\n",ArestraAux->DadosItem->NomeUsuario,EstadoAcessos[ArestraAux->DadosItem->PerfilID]);
            if(EstadoAcessos[ArestraAux->DadosItem->PerfilID] == branco && ContagemDistancia < DistanciaListagemConhecidos){
                EstadoAcessos[ArestraAux->DadosItem->PerfilID] = cinza;
                //printf("Joined %s %d\n",ArestraAux->DadosItem->NomeUsuario,EstadoAcessos[VerticeAtual->PerfilID]);
                Insere_dado_MODOFILA(ArestraAux->DadosItem,FilaDeVertices);
                Insere_dado_MODOFILA(ArestraAux->DadosItem,Dados);
            }
            ArestraAux = ArestraAux->Proximo;
        }
        ContagemDistancia++;

        //printf("Perfil atual: %s\n",VerticeAtual->NomeUsuario);
        //Imprimir_lista(FilaDeVertices);
        EstadoAcessos[VerticeAtual->PerfilID] = preto;
        if(Lista_vazia(FilaDeVertices) == true){
            printf("Lista vazia.\n");
            BuscaEncerrada = true;
            break;
        }
        VerticeAtual = Remove_dado_MODOFILA(FilaDeVertices);
        //printf("Perfil aAAtual: %s\n",VerticeAtual->NomeUsuario);
        printf("");
        if(ContagemDistancia < DistanciaListagemConhecidos){
            LoadVerticesNaLista(FilaDeVertices,Dados,VerticeAtual,EstadoAcessos,ContagemDistancia);
        }
    }
    return Sucesso;
}

Error * BuscarDeSeguidores_Largura(DataType * Inicial,HashTable * table){
    /**
    * Função que busca os perfis conhecidos a uma distancia N(Const: DistanciaListagemConhecidos).
    * @return Sucesso caso ocorra tudo certo.
    */
    Followed_list * FilaDeVertices = (Followed_list*)malloc(sizeof(Followed_list));
    Followed_list * DadosAcessiveis = (Followed_list*)malloc(sizeof(Followed_list));
    int * EstadoAcessos = (int*)calloc((GetMaiorIDAtual(table)+1),sizeof(int));
    int ContagemDistancia = 0;

    Inicializar_lista(FilaDeVertices);
    Inicializar_lista(DadosAcessiveis);
    
    printf("CHAMADA : %s\n",Inicial->NomeUsuario);

    LoadVerticesNaLista(FilaDeVertices,DadosAcessiveis,Inicial,EstadoAcessos,ContagemDistancia);
    
    Imprimir_lista(DadosAcessiveis);

    free(EstadoAcessos);
    Limpar_lista(DadosAcessiveis);
    Limpar_lista(FilaDeVertices);
    return Sucesso;
}