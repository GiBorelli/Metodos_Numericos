#include <stdio.h>
#include "matriz.h"
#include "resolucao.h"
#include "eliminacao_gauss.h"

void eliminacaoGauss(double **A, double *b, int n){
    int i, j;
    for(j = 0; j < n-1; j++){
        for(i = j+1; i < n; i++){
            double mij = A[i][j]/A[j][j];
            for(int k = 0; k < n; k++){     // Li <-> Li -mij * Lj
                A[i][k] = A[i][k] - mij * A[j][k];
            }
            b[i] = b[i] - mij * b[j];
        }
    }
}

void controleEliminacaoGauss(double **A, int n){
    double *b = (double *) malloc(n * sizeof(double));
    preenchimentoVetorSolucao(b, n);
    
    eliminacaoGauss(A, b, n);

    printf("A matriz triangular escalonada e: \nA = ");
    impressaoMatriz(A, n);

    printf("O vetor resposta b escalonado e: \nb = [");
    impressaoVetorSolucao(b, n);

    int resolve;
    printf("Caso queira a solucao da matriz, digite 1. Se nao quiser, digite 0: ");
    scanf(" %d", &resolve);
    if(resolve) controleResolucao(A, b, n);
}
