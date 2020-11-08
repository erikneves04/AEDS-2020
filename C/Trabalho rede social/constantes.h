/**
* @file   constantes.h
* @brief  Arquivo com a definição de constantes do software.
* @author <Erik Neves>
* @date   2020-11-08
*/
#pragma once

#ifndef __const_h__
#define __const_h__

// DEFINIÇÃO DE BOOLEANOS
typedef unsigned int Boolean;
#define true                         (00)
#define false                        (!true)

//DEFINIÇÃO DE CONSTANTES
#define Variavel_de_inicio           (-1)
#define Encerrar_loop                (00)
#define Sucesso                      (00)
#define Tamanho_MAX_NomeCompleto     (51)
#define Tamanho_MAX_usuario          (16)
#define Tamanho_MAX_bio             (101)

// DEFINIÇÃO DE ERROS        
typedef unsigned int Error;  
#define Perfil_inexistente           (01)
#define Erro_lista_vazia             (02)


#endif /* __const_h__ */