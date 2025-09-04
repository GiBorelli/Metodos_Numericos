#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"

double *retroSubstituicao(int n, double **A, double *b, double xn){
    double *x = (double*) malloc(n * sizeof(double));
    x[n-1] = xn;
    for(int i = n-1; i >= 0; i--){
        double soma = 0;
        for(int j = i+1; j < n; j++){
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma)/A[i][i];
    }
    return x;
}

void controleRetroSubstituicao(double **A, int n){
    double *b = (double *) malloc(n * sizeof(double));
    preenchimentoVetorSolucao(b, n);

    double *x = algoritmo(n, A, b, b[n-1]/A[n-1][n-1]);

    printf("O vetor solucao X e: \nX = [");
    impressaoVetorSolucao(b, n);

}