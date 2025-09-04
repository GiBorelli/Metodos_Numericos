#include <stdio.h>
#include "matriz.h"
#include "resolucao.h"
#include "fatoracao_LU.h"

void fatoracaoLU(double **A, int n, double **L, double **U){
    int i, j;
    for(j = 0; j < n-1; j++){
        for(i = j+1; i < n; i++){
            double mij = A[i][j]/A[j][j];
            for(int k = 0; k < n; k++){     // Li <-> Li -mij * Lj
                A[i][k] = A[i][k] - mij * A[j][k];
            }
        }
    }
}

void controleFatoracaoLU(double **A, int n){
    double **L = alocacaoMatrizQuadrada(L, n);
    double **U = alocacaoMatrizQuadrada(U, n);
    fatoracaoLU(A, n, L, U);
    printf("A matriz triangular inferior L e: \nL = ");
    impressaoMatriz(L, n);
    printf("A matriz triangular superior U e: \nU = ");
    impressaoMatriz(U, n);

    int novoB;
    printf("Caso queira inserir um vetor solucao b, digite 1. Se nao quiser, digite 0: ");
    scanf(" %d", &novoB);
    while(novoB != 0){
        double *b = (double *) malloc(n * sizeof(double));
        preenchimentoVetorSolucao(b, n);

        printf("Calculando o vetor X: ");

        /*int resolve;
        printf("Caso queira a solucao da matriz, digite 1. Se nao quiser, digite 0: ");
        scanf(" %d", &resolve);
        if(resolve) controleResolucao(A, b, n);*/
    }
    
}