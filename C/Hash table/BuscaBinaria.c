/*
 * @file   BuscaBinaria.c
 * @brief  Implementaçao das funçoes de manipulaçao de 
 *          listas ordenadas e buscas binarias.
 * @author <Erik Neves>
 * @date   2020-10-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "funcoesLE.h"

static int SomaCaracteresString(char * string){
    int count = 0;
    int i;
    
    for(i=0;i<strlen(string);i++){
        count += (int)string[i];
    }
    //printf("%s: %d\n",string,count);
    //printf("%s: %d\n",string,((int)(count / 10)));
    return count;
}
static DataType ** CarregaDadosNoVetor(Lista * lista){
    DataType ** VetorDados = (DataType**)malloc(sizeof(DataType*) * lista->NumeroDeDados);
    Item_lista * DadosLista = lista->Primeiro;
    int i;

    for(i=0;i<lista->NumeroDeDados;i++){
        VetorDados[i] = DadosLista->DadosItem;
        DadosLista = DadosLista->Proximo;
    }

    return VetorDados;
}

Error InsereOrdenado(Lista * lista, DataType * dadosItem){
    // Baseado na soma dos caracteres do nome (ascii)
    int i;
    Item_lista * DadosLista = lista->Primeiro;
    Item_lista * NovoItem = (Item_lista*)malloc(sizeof(Item_lista));
    Boolean ItemInserido = false;
    int SomaCaracteres = SomaCaracteresString(dadosItem->Nome);
    NovoItem->DadosItem = dadosItem;

    for(i=0;i<lista->NumeroDeDados;i++){
        if(DadosLista != NULL){
            if (SomaCaracteres <= SomaCaracteresString(DadosLista->DadosItem->Nome)){
                if(DadosLista->Proximo != NULL){
                    if(DadosLista->Anterior != NULL){
                        DadosLista->Anterior->Proximo = NovoItem;
                        NovoItem->Anterior = DadosLista->Anterior;
                    }else{
                        NovoItem->Proximo = DadosLista;
                        DadosLista->Anterior = NovoItem;
                        lista->Primeiro = NovoItem;
                        NovoItem->Anterior = NULL;
                    }
                    DadosLista->Anterior = NovoItem;
                }else{
                    DadosLista->Proximo = NovoItem;
                    NovoItem->Anterior = DadosLista;
                    NovoItem->Proximo = NULL;
                }
                ItemInserido = true;
            }
            break;
        }
        DadosLista = DadosLista->Proximo;
    }
    
    if(ItemInserido == false && lista->NumeroDeDados == 0){
        NovoItem->Anterior = NULL;
        NovoItem->Proximo = NULL;
        lista->Primeiro = NovoItem;
        lista->Ultimo = NovoItem;
    }else if(ItemInserido == false){
        lista->Ultimo->Proximo = NovoItem;
        NovoItem->Anterior = lista->Ultimo;
        NovoItem->Proximo = NULL;
        lista->Ultimo = NovoItem;
    }
    lista->NumeroDeDados++;

    return Sucesso;
}
Error ImprimirDadosLista(Lista * lista){
    int i;

    if(EstadoLista(lista) == true){
        printf("Lista vazia!!\n\n");
        return Erro_lista_vazia;
    }else{
        printf("+---------------------------+\n");
        printf("| Imprimindo dados da lista |\n");
        printf("+---------------------------+\n\n");
        printf("%-25s %s\n","Nome:","Telefone:");
        for(i=0;i<lista->NumeroDeDados;i++){
            printf("%-25s %d\n",GetItemLista(lista,i)->Nome,GetItemLista(lista,i)->Telefone);
        }
        printf("\n");
    }

    return Sucesso;
}
Error ImprimirDadosPessoa(DataType * dados){

    if(dados == NULL) return Dado_nao_encontrado;

    printf("\nNome: %-25s   Telefone: %d\n",dados->Nome,dados->Telefone);
    //printf("Rua: %-25s    Numero: %.4d\n",dados->Endereco->Rua,dados->Endereco->Numero);
    //printf("Bairro: %-25s Cidade: %-25s\n\n",dados->Endereco->Bairro,dados->Endereco->Cidade);

    return Sucesso;
}

DataType * BuscaDadoItem(Lista * lista,char search[Tamanho_MAX_string]){
    DataType ** VetorDados = CarregaDadosNoVetor(lista);
    int i;
    int Intervalo_inicio,Intervalo_termino,Intermediario;
    int SomaCharAux_01,SomaCharAux_02;
    int SomaCharProcurado = SomaCaracteresString(search);

    Intervalo_inicio = 0;
    Intervalo_termino = lista->NumeroDeDados - 1;
    
    while(Intervalo_inicio <= Intervalo_termino){
        Intermediario = (Intervalo_inicio + Intervalo_termino)/2;
        if(SomaCharProcurado < SomaCaracteresString(VetorDados[Intermediario]->Nome)){
            Intervalo_termino =  Intermediario - 1;
        }else if(SomaCharProcurado > SomaCaracteresString(VetorDados[Intermediario]->Nome)){
            Intervalo_inicio = Intermediario + 1;
        }else if(SomaCharProcurado == SomaCaracteresString(VetorDados[Intermediario]->Nome)){
            return VetorDados[Intermediario];
        }
    }

    return NULL;
}