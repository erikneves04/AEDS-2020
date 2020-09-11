/**
* @file   funcoes.h
* @brief  Arquivo assinaturas das funções de manipulação de árvores binaria (RAIZ - ESQUERDA - DIREITA).
* @author <Erik Neves>
* @date   2020-09-10
*/
#pragma once

#ifndef __Tree_h__
#define __Tree_h__

// ASSINATURA DAS FUNÇÕES DE MANIPULAÇÃO DE ÁRVORE - INICIO
Error Inicializar_ArvoeVazia(Arvore * arvore);
Error Criar_Arvore(Arvore * arvore,DataType Info,Arvore * ArvDireita,Arvore * ArvEsquerda);
Error AlterarDados_Arvore(Arvore * arvore, DataType Info,Arvore * ArvDireita,Arvore * ArvEsquerda);
Error Cria_ArvoreOrdenada(Arvore * Nova_Arvore,Arvore * Raiz);
Boolean Arvore_Vazia(Arvore * arvore);
Error Imprimir_Arvore(Arvore * arvore);
Error LimparMemoria_Arvore(Arvore * arvore);
Boolean DadoContido_Arvore(Arvore * arvore, DataType DadoProcurado);
int GetAltura_Arvore(Arvore * arvore);
int GetNosComDoisFilhos(Arvore * arvore);
int GetNosComUmFilhos(Arvore * arvore);
// ASSINATURA DAS FUNÇÕES DE MANIPULAÇÃO DE ÁRVORE - FIM

#endif /* __Tree_h__ */