#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"
#include "fatoracao_LU.h"

/*int quantMultiplicadores(int n){
    if (n <= 2)
        return 1;
    return n + quantMultiplicadores(n-1);
}

void fatoracaoLU(double **A, int n, double **L, double **U){
    int i, j, k;
    //double *l = (double *) malloc(quantMultiplicadores(n) * sizeof(double));
    for(j = 0; j < n-1; j++){
        for(i = j+1; i < n; i++){
            double l = A[i][j]/A[j][j];
            //printf("[%d] [%d] = %.2lf, %.2lf * A[%d][k] = %.2lf \n", i, k, A[i][k], l, j, A[j][k]);
            for(k = 0; k < n; k++){     // Li <-> Li -mij * Lj
                U[i][k] = A[i][k] - l * A[j][k];
            }
            L[i][j] = l; 
        }
    }
    for(i = 0; i < n; i++){
        L[i][i] = 1;
        for(j = i+1; j < n; j++) L[i][j] = 0;
    }
}*/

void fatoracaoLU(double **A, int n){
    int i, j, k;
    for(j = 0; j < n-1; j++){
        for(i = j+1; i < n; i++){
            double l = A[i][j]/A[j][j];
            for(k = j+1; k < n; k++){     // Li <-> Li -mij * Lj
                A[i][k] = A[i][k] - l * A[j][k];
            }
            A[i][j] = l; 
        }
    }
}

double *resolucaoFatoracaoLU(double **A, double *b, int n){
    double *y = (double*) malloc(n * sizeof(double));
    double soma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            soma += A[i][j] * y[j];
        }
        y[i] = b[i] - soma;     // (b[i] - soma)/A[i][i]; -> b[i] - soma)/1
    }
    double *x = retroSubstituicao(n, A, y);
    free(y);
    return x;
}

void controleFatoracaoLU(double **A, int n){
    /*double **L = alocacaoMatrizQuadrada(L, n);
    double **U = alocacaoMatrizQuadrada(U, n);
    fatoracaoLU(A, n, L, U);*/

    fatoracaoLU(A, n);
    printf("A matriz triangular inferior L e: \nL = ");
    impressaoTriangularInferior(A, n);
    printf("A matriz triangular superior U e: \nU = ");
    impressaoTriangularSuperior(A, n);

    int novoB;
    do{
        printf("Caso queira inserir um vetor solucao b, digite 1. Se nao quiser, digite 0: ");
        scanf(" %d", &novoB);
        if(novoB != 1 && novoB != 0) printf("Valor invalido. \n");
        else if(novoB == 1){
            double *b = (double *) malloc(n * sizeof(double));
            preenchimentoVetorSolucao(b, n);
            printf("Calculando o vetor X \n");
            double *X = resolucaoFatoracaoLU(A, b, n);
            printf("X = [");
            impressaoVetor(X, n);
            free(b);
            free(X);
        }
    } while(novoB != 0);
}