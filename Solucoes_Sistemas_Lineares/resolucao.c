#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"

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

void controleRetroSubstituicao(double **A, int n, int escolha, char nome_arq[150], FILE *arq){
    double *b = (double *) malloc(n * sizeof(double));
    if(escolha == 1){
        preenchimentoVetorSolucao(b, n);
    }
    else{
        b = preenchimentoVetorArquivo(n, nome_arq, arq);
    }

    double *x = retroSubstituicao(n, A, b);

    printf("O vetor solucao X e: \nX = [");
    impressaoVetor(x, n);
    free(b);
}