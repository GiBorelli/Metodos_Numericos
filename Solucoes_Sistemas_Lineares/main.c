/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c matriz.c resolucao.c eliminacao_gauss.c fatoracao_LU.c iterativo_gauss_jacobi.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"
#include "eliminacao_gauss.h"
#include "fatoracao_LU.h"
#include "iterativo_gauss_jacobi.h"

int main(){
    int escolha, n;
    printf("Escolha a Solucao a ser aplicada: \n");
    printf(" 1- Resolucao Matrizes Triangulares \n 2- Metodo da Eliminacao de Gauss\n 3- Fatoracao LU\n");  //Métodos Diretos
    printf(" 4- Metodo Gauss-Jacobi \n");   //Métodos Iterativos
    scanf(" %d", &escolha);

    printf("Digite a dimensao n da matriz quadrada: ");
    scanf(" %d", &n);
    double **A = alocacaoMatrizQuadrada(A, n);
    preenchimentoMatriz(A, n);

    switch (escolha) {
        case 1: controleRetroSubstituicao(A, n);
            break;
        case 2: controleEliminacaoGauss(A, n);
            break;
        case 3: controleFatoracaoLU(A, n);
            break;
        case 4: controleGaussJacobi(A, n);
            break;
        default: printf("Opcao invalida.\n");
            break;
    }

    liberaMatrizQuadrada(A, n);
    printf("Encerrando Programa.\n");
    return 0;
}