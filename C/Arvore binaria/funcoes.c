/*
 * @file   funcoes.c
 * @brief  Implementaçao das funçoes de manipulaçao de árvore binaria (RAIZ - ESQUERDA - DIREITA).
 * @author <Erik Neves>
 * @date   2020-09-10
*/

// INCLUSÃO DE BIBLIOTECAS - INICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
// INCLUSÃO DE BIBLIOTECAS - FIM


// IMPLEMENTAÇÃO FUNÇOES DE MANIPULAÇÃO DE ÁRVORES - INICIO
Error Inicializar_ArvoeVazia(Arvore * arvore){
    /*
    * Função resposável por inicializar um arvore vazia.
    * @return Sucesso caso tudo ocorra certo.
    */
    arvore = NULL;
    return Sucesso;
}
Error Criar_Arvore(Arvore * arvore,DataType Info,Arvore * ArvDireita,Arvore * ArvEsquerda){
    /*
    * Função resposável por inicializar um arvore.
    * @return Sucesso caso tudo ocorra certo.
    */
    arvore = (Arvore*)malloc(sizeof(arvore));

    arvore->Dado = Info;
    arvore->Esquerda = ArvEsquerda;
    arvore->Direita = ArvDireita;

    return Sucesso;
}
Error AlterarDados_Arvore(Arvore * arvore, DataType Info,Arvore * ArvDireita,Arvore * ArvEsquerda){
    /*
    * Função resposável por alterar os dados de uma árvore.
    * @return Sucesso caso tudo ocorra certo.
    */
    arvore->Dado = Info;
    arvore->Direita = ArvDireita;
    arvore->Esquerda = ArvEsquerda;

    return Sucesso;
}
Error Cria_ArvoreOrdenada(Arvore * Nova_Arvore,Arvore * Raiz){
    /*
    * Função resposável por inserir uma arvore ja criada de forma ordenada.
    *   -> Elementos menores a esquerda & maiores a direita.
    *   -> Por padrão se o dado for igual e retornado um erro
    * @return Sucesso caso ocorra tudo certo.
    */
    if(Nova_Arvore->Dado == Raiz->Dado) return Erro_dado_repetido;
    if((Nova_Arvore->Dado > Raiz->Dado)){
        if(Raiz->Direita == NULL){
            Raiz->Direita = Nova_Arvore;
        }else if(Raiz->Direita->Dado > Nova_Arvore->Dado){
            Nova_Arvore->Direita = Raiz->Direita;
            Raiz->Direita = Nova_Arvore;
        }else{
            Cria_ArvoreOrdenada(Nova_Arvore,Raiz->Direita);
        }
    }else{
       if(Raiz->Esquerda == NULL){
            Raiz->Esquerda = Nova_Arvore;
        }else if(Raiz->Esquerda->Dado < Nova_Arvore->Dado){
            Nova_Arvore->Esquerda = Raiz->Esquerda;
            Raiz->Esquerda = Nova_Arvore;
        }else{
            Cria_ArvoreOrdenada(Nova_Arvore,Raiz->Esquerda);
        } 
    }
    return Sucesso;
}
Boolean Arvore_Vazia(Arvore * arvore){
    /*
    * Função resposável por verificar se uma árvore esta vazia.
    * @return Boolean(true or false) true caso a árvore esteja vazia.
    */
   return (arvore == NULL) ? true : false;
}
Error Imprimir_Arvore(Arvore * arvore){
    /*
    * Função resposável por imprimir os dados de uma arvore.
    * @return Sucesso caso tudo ocorra certo.
    */
    char * LinhaImpressao;
    if(Arvore_Vazia(arvore)){
        (void)sprintf(LinhaImpressao,"Dado: %%s\n",PrintfType);
        (void)printf(LinhaImpressao,arvore->Dado);

        Imprimir_Arvore(arvore->Esquerda);
        Imprimir_Arvore(arvore->Direita);
    }

    return Sucesso;
}
Error LimparMemoria_Arvore(Arvore * arvore){
    /*
    * Função resposável por limpar os dados de uma arvore.
    * @return Sucesso caso tudo ocorra certo.
    */
    if(Arvore_Vazia(arvore)){
        LimparMemoria_Arvore(arvore->Esquerda);
        LimparMemoria_Arvore(arvore->Direita);
        free(arvore);
    }

    return Sucesso;
}
Boolean DadoContido_Arvore(Arvore * arvore, DataType DadoProcurado){
    /*
    * Função resposável por identificar se um dado esta presente numa árvore.
    * @return Boolean(true or false) true caso o dado esteja contido na árvore.
    */
    if(Arvore_Vazia(arvore)) return Erro_arvore_vazia;
    return ((arvore->Dado == DadoProcurado) 
    || (DadoContido_Arvore(arvore->Esquerda,DadoProcurado) == true) 
    || (DadoContido_Arvore(arvore->Direita,DadoProcurado) == true)) ? true : false;
}
int GetAltura_Arvore(Arvore * arvore){
    /*
    * Função resposável por identificar a altura de uma árvore
    * @return (int) numero de nós da árvore.
    */
    if(Arvore_Vazia(arvore)) return 0;
    return (GetAltura_Arvore(arvore->Esquerda) + GetAltura_Arvore(arvore->Direita) + 1);
}
int GetNosComDoisFilhos(Arvore * arvore){
    /*
    * Função resposável por identificar o numero de nós com dois filhos.
    * @return (int) numero de nós da árvore.
    */
    int Aux = 0;
    if((arvore->Direita == NULL) && (arvore->Esquerda == NULL)) Aux = 0;
    if((arvore->Direita != NULL) && (arvore->Esquerda != NULL)) Aux = 1;

    if(arvore->Direita == NULL || arvore->Esquerda == NULL){
        return Aux;
    }else{
        return Aux + ((GetNosComDoisFilhos(arvore->Direita)) + (GetNosComDoisFilhos(arvore->Direita)));
    }
}
int GetNosComUmFilhos(Arvore * arvore){
    /*
    * Função resposável por identificar o numero de nós com dois filhos.
    * @return (int) numero de nós da árvore.
    */
    int Aux = 0;
    if((arvore->Direita == NULL) && (arvore->Esquerda == NULL)) Aux = 0;
    if((arvore->Direita != NULL) && (arvore->Esquerda != NULL)) Aux = 0;
    if((arvore->Direita != NULL) && (arvore->Esquerda == NULL)) Aux = 1;
    if((arvore->Direita == NULL) && (arvore->Esquerda != NULL)) Aux = 1;

    if((arvore->Direita == NULL) && (arvore->Esquerda == NULL)) return Aux;
    if(arvore->Direita != NULL) return Aux + (GetNosComUmFilhos(arvore->Direita));
    if(arvore->Esquerda != NULL) return Aux + (GetNosComUmFilhos(arvore->Esquerda));
}
// IMPLEMENTAÇÃO FUNÇOES DE MANIPULAÇÃO DE ÁRVORES - FIM