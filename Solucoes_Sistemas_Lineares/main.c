/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c matriz.c resolucao.c eliminacao_gauss.c fatoracao_LU.c iterativos.c iterativo_gauss_jacobi.c iterativo_gauss_seidel.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"
#include "eliminacao_gauss.h"
#include "fatoracao_LU.h"
#include "iterativos.h"
#include "iterativo_gauss_jacobi.h"
#include "iterativo_gauss_seidel.h"

int main(){
    int escolha, n;
    do{
        printf("\nEscolha a Solucao a ser aplicada: \n");
        printf(" 1- Resolucao Matrizes Triangulares \n 2- Metodo da Eliminacao de Gauss\n 3- Fatoracao LU\n");  //Métodos Diretos
        printf(" 4- Metodo Iterativo Gauss-Jacobi \n 5- Metodo Iterativo Gauss-Seidel\n");   //Métodos Iterativos
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
            case 5: controleGaussSeidel(A, n);
                break;
            default: printf("Opcao invalida.\n");
                break;
        }
        printf("\nCaso deseje fazer a aplicacao de mais um metodos, digite 1. Se nao desejar, digite qualquer outro numero.\n");
        scanf("%d", &escolha);

        liberaMatrizQuadrada(A, n);
    } while(escolha == 1);

    printf("Encerrando Programa.\n");
    return 0;
}