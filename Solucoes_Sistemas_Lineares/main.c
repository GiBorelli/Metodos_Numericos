/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c resolucao.c eliminacao_gauss.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"
#include "eliminacao_gauss.h"
#include "fatoracao_LU.h"

int main(){
    int escolha, n;
    printf("Escolha a Solucao a ser aplicada: \n");
    printf(" 1- Resolucao Matrizes Triangulares \n 2- Metodo da Eliminacao de Gauss\n");
    scanf(" %d", &escolha);

    printf("Digite a dimensao n da matriz quadrada: ");
    scanf(" %d", &n);
    double **A = alocacaoMatrizQuadrada(A, n);
    preenchimentoMatriz(A, n);

    switch (escolha) {
        case 1: controleResolucao(A, n);
            break;
        case 2: controleEliminacaoGauss(A, n);
            break;
        case 3: controleFatoracaoLU(A, n);
            break;
        default: printf("Opcao invalida.\n");
            break;
    }
    printf("Encerrando Programa.\n");
    return 0;
}