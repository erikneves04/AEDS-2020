/**
* @file   funcoes.h
* @brief  Arquivo com as assinaturas das funções de manipulação de lista encadeada.
* @author <Erik Neves>
* @date   2020-11-07
*/
#pragma once

#ifndef __funcoes_h__
#define __funcoes_h__

Error Inicializar_lista(Lista * lista,DataTypeCompare compare,PrintDataType print);
Error Insere_dado(DataType Valor,Lista * lista);
Error Remove_dado(DataType Valor,Lista * lista);
Boolean Lista_vazia(Lista * lista);
Error Imprimir_lista(Lista * lista);
Error Limpar_lista(Lista * lista);

#endif /* __funcoes_h__ */