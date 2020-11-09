/*
 * @file   Interact.c
 * @brief  Implementaçao das funçoes de interação com o usuario.
 * @author <Erik Neves>
 * @date   2020-11-07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

DataType * GetInfosDataType(){
    DataType * NovoDado = (DataType*)malloc(sizeof(DataType));

    setbuf(stdin,NULL);
    printf("Digite o nome da pessoa(Max.:%.3d):",Tamanho_MAX_string);
    scanf("%[^\n]s", NovoDado->Nome);
    setbuf(stdin,NULL);
    printf("Digite o numero da pessoa(9 digitos): ");
    scanf("%d", &NovoDado->Telefone);

    NovoDado->Endereco = (DadosEndereco*)malloc(sizeof(DadosEndereco));

    setbuf(stdin,NULL);
    printf("Digite a rua da pessoa(Max.:%.3d):",Tamanho_MAX_string);
    scanf("%[^\n]s", NovoDado->Endereco->Rua);
    setbuf(stdin,NULL);
    printf("Digite o bairro da pessoa(Max.:%.3d):",Tamanho_MAX_string);
    scanf("%[^\n]s", NovoDado->Endereco->Bairro);
    setbuf(stdin,NULL);
    printf("Digite a cidade da pessoa(Max.:%.3d):",Tamanho_MAX_string);
    scanf("%[^\n]s", NovoDado->Endereco->Cidade);
    setbuf(stdin,NULL);
    printf("Digite o numero da casa da pessoa:");
    scanf("%d", &NovoDado->Endereco->Numero);
    setbuf(stdin,NULL);

    return NovoDado;
}
char * GetStringAlvo(){
    char * NomeAlvo = (char*)malloc(sizeof(char) * Tamanho_MAX_string);

    setbuf(stdin,NULL);
    printf("Digite o nome da pessoa(Max.:%.3d): ",Tamanho_MAX_string);
    scanf("%[^\n]s", NomeAlvo);
    setbuf(stdin,NULL);

    return NomeAlvo;
}
Error AvisoPessoaInexistente(){

    printf("Pessoa nao encontrada, tente novamente e/ou\nreveja a lista com as informacoes.\n");

    return Sucesso;
}
DataType * GetDataTypeAlvo(Lista * lista, char Nome[Tamanho_MAX_string]){
    DataType * DataAlvo;
    Boolean DataEncontrada = false;
    Item_lista * Dados_lista = lista->Primeiro;
    int i;

    for(i=0;i<lista->NumeroDeDados;i++){
        if(strcmp(Nome,Dados_lista->DadosItem->Nome) == 0){
            DataAlvo = Dados_lista->DadosItem;
            DataEncontrada = true;
            break;
        }
    }
    
    return (DataEncontrada == true ) ? DataAlvo : NULL;
}