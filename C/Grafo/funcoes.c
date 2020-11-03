/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de grafos.
 * @author <Erik Neves>
 * @date   2020-10-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoesLE.h"

DataType UserIteract(void){
    DataType Interact_aux;
    char Identifier[] = "%";

    strcat(Identifier,PrintfType);

    printf("\nDigite o dado(%s): ",PrintfType_descripition);
    scanf(Identifier,&Interact_aux);

    printf("\n");
    return Interact_aux;
}
Lista_arestras * IndexArestras(Grafo * grafo){
    Lista_arestras * ListaComArestras = (Lista_arestras*)malloc(sizeof(Lista_arestras));
    Vertice * VerticeDestino = NULL;
    Vertice * vertices = grafo->primeiro;
    int NumArestras = 0;
    int i,j;
    int IDAux;
    static int ident = 0;
    Inicializar_listaArestras(ListaComArestras);

    printf("Digite o numero de arestras: ");
    //scanf("%d", &NumArestras);
    if(ident > 6) scanf("%d", &NumArestras); //test version
    
    for(i=0;i<NumArestras;i++){
        printf("(%.3d)Digite o id do vertice:",i);
        scanf("%d", &IDAux);

        vertices = grafo->primeiro;
        for(j=0;j<grafo->NumeroDeVertices;j++){
            VerticeDestino = NULL;
            if(vertices->ID == IDAux){
                VerticeDestino = vertices;
                break;
            }
            vertices = vertices->proximo;
        }

        if(VerticeDestino == NULL){
            printf("Escolha invalida!\n");
            i--;
        }else{
            Insere_dado_listaArestras(VerticeDestino,ListaComArestras);
        }
    }
    ident++;
    return ListaComArestras;
}
Vertice * GetVerticeAlvo(Grafo * grafo){
    Vertice * vertices = grafo->primeiro;
    Boolean VerticeEncontrado = false;
    int i;
    int VerticeID;

    printf("Digite o ID do vertice: ");
    scanf("%d", &VerticeID);

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(vertices->ID == VerticeID){
            VerticeEncontrado = true;
            break;    
        }
        vertices = vertices->proximo;
    }
    if(VerticeEncontrado == false){
        printf("Escolha invalida!\n");
    }
    printf("\n");
    
    return vertices;
}

int CalculaGrauVertice(Vertice * vertice){
    return vertice->arestras->NumeroDeArestras;
}
Error InicializarGrafo(Grafo * grafo){

    grafo->NumeroDeVertices = 0;
    grafo->primeiro = NULL;

    return Sucesso;
}
Error InserirItem(Grafo * grafo,Lista_arestras * listaA,DataType valor){

    Vertice * NovoVertice = (Vertice*)malloc(sizeof(Vertice));

    NovoVertice->VerticeValor = valor;
    NovoVertice->arestras = listaA;
    NovoVertice->ID = grafo->NumeroDeVertices + 1;

    NovoVertice->proximo = grafo->primeiro;
    grafo->primeiro = NovoVertice;
    grafo->NumeroDeVertices++;

    return Sucesso;
}
Error RedefinirListaArestras(Grafo * grafo){
    Vertice * vertices = grafo->primeiro;
    Boolean VerticeEncontrado = false;
    int i;
    int VerticeID;

    printf("Digite o ID do vertice que voce deseja\n");
    printf("redefinir as arestras: ");
    scanf("%d", &VerticeID);

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(vertices->ID == VerticeID){
            VerticeEncontrado = true;
            Limpar_lista_Arestras(vertices->arestras);
            vertices->arestras = IndexArestras(grafo);
            break;    
        }
        vertices = vertices->proximo;
    }
    if(VerticeEncontrado == false){
        printf("Escolha invalida!\n");
    }
    printf("\n");
    
    return Sucesso;
}
Error ImprimirDadosGrafo(Grafo * grafo){
    Vertice * DadosGrafo = grafo->primeiro;
    int i;

    printf("+------------------------------+\n");
    printf("| Imprimindo os dados do grafo |\n");
    printf("+------------------------------+\n");

    printf("ID   Dado:\n");
    for(i=0;i<grafo->NumeroDeVertices;i++){
        printf("%.2d   %.4d\n",DadosGrafo->ID,DadosGrafo->VerticeValor);
        DadosGrafo = DadosGrafo->proximo;
    }
    printf("\n");

    return Sucesso;
}
Error ImprimirArestrasVertice(Grafo * grafo){
    Vertice * DadosGrafo = grafo->primeiro;
    Boolean VerticeEncontrado = false;
    int IDAlvo;
    int i,j;

    printf("Digite o ID do vertice desejado: ");
    scanf("%d", & IDAlvo);

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(DadosGrafo->ID == IDAlvo){
            VerticeEncontrado = true;
            Arestra * DadosArestras = DadosGrafo->arestras->primeira;
            printf("Imprimindo possiveis vertices de destino: \n");
            for(j=0;j<DadosGrafo->arestras->NumeroDeArestras;j++){
                printf(" | %.3d\n",DadosArestras->vertice->ID);
                DadosArestras = DadosArestras->proximo;
            }
            printf("\n");
            break;
        }
        DadosGrafo = DadosGrafo->proximo;
    }
    
    if(VerticeEncontrado == false){
        printf("+------------------+\n");
        printf("| Escolha invalida |\n");
        printf("+------------------+\n\n");
    }
    
    return Sucesso;
}
Error RemoverItem(Grafo * grafo){
    Vertice * DadosGrafo = grafo->primeiro;
    Vertice * VerticeAlvo = NULL;
    int IDVerticeAlvo;
    int i;

    printf("Remover um vertice ira implicar tambem na remocao de todas as\n");
    printf("arestras relacionadas a ele.\n");
    printf("Digite o ID do vertice: ");
    scanf("%d", &IDVerticeAlvo);

    for(i=0;i<grafo->NumeroDeVertices;i++){
        if(DadosGrafo->ID == IDVerticeAlvo){
            VerticeAlvo = DadosGrafo;
            break;
        }
        DadosGrafo = DadosGrafo->proximo;
    }
 
    if(VerticeAlvo != NULL){
        DadosGrafo = grafo->primeiro;
        for(i=0;i<grafo->NumeroDeVertices;i++){
            Remover_dado_listaArestras(DadosGrafo->arestras,VerticeAlvo);
            DadosGrafo = DadosGrafo->proximo;
        }
        Remove_dado_listaVertices(VerticeAlvo,grafo);
    }else{
        printf(" Escolha invalida.\n");
    }
    
    return Sucesso;
}