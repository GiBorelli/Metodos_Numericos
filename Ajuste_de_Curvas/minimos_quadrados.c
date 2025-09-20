#include <stdio.h>
#include <stdlib.h>
#include "minimos_quadrados.h"

double *retroSubstituicao(int n, double **A, double *b){
    double *x = (double*) malloc(n * sizeof(double));
    x[n-1] = b[n-1]/A[n-1][n-1];
    for(int i = n-1; i >= 0; i--){
        double soma = 0;
        for(int j = i+1; j < n; j++){
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma)/A[i][i];
    }
    return x;
}

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

void ajusteCurva(double **pontos, int quantPontos, int n){
    double *v = (double *) malloc(n * sizeof(double));

    eliminacaoGauss(pontos, v, n);

    double *x = retroSubstituicao(n, pontos, v);
    printf("O vetor v e: \nv = [");
    impressaoVetor(x, n);
}

