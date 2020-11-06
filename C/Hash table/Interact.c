/*
 * @file   Interact.c
 * @brief  Implementaçao das funçoes de interação com o usuario.
 * @author <Erik Neves>
 * @date   2020-11-05
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

    /*printf("oo\n");
    NovoDado->Endereco = (DadosEndereco*)malloc(sizeof(DadosEndereco));
    printf("ii\n");
    setbuf(stdin,NULL);
    strcpy(NovoDado->Endereco->Rua,"Jacaranda");
    strcpy(NovoDado->Endereco->Bairro,"Jardim montanhes");
    strcpy(NovoDado->Endereco->Cidade,"Ibirite");
    NovoDado->Endereco->Numero = 240;*/
    /*
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
    scanf("%[^\n]s", &NovoDado->Endereco->Numero);
    setbuf(stdin,NULL);
    */
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
int GetColunaAlvo(HashTable * table){
    int ColunaID;

    printf("Digite o numero da coluna desejada(Max. ID: %.4d): ",table->NumeroDeColunas);
    scanf("%d", &ColunaID);

    return ColunaID - 1;
}