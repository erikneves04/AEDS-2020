/*
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
// INCLUSÃO DE BIBLIOTECAS - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - INICIO
int GetColunaPerfil(char * string){
    int count = 0;
    int i;
    
    for(i=0;i<strlen(string);i++){
        count += (int)string[i];
    }
    //printf("%s : %d\n",string,count);
    count =  (count/10);
    //printf("count : %d\n",count);
    return (int)count;
}
static int GetIdPerfil(){
    static int ID = 1;
    return ID++;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE RETORNAM VARIAVEIS DE CONTROLE - FIM


// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - INICIO
DataType * GetInformacoesCriarPerfil(HashTable * table){
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

    printf("\n");
    printf("+---------------------------+\n");
    printf("| Perfil criado com sucesso |\n");
    printf("+---------------------------+\n");
    printf("\n");

    return NovoPerfil;
}
// IMPLEMENTAÇÃO FUNÇÕES QUE INTERAGEM COM O USUARIO - FIM