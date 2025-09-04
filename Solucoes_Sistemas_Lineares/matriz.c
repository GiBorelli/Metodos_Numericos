#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double **alocacaoMatrizQuadrada(double **A, int n){
    A = (double **) malloc(n * sizeof(double *));
    if(A != NULL){
        for(int i = 0; i < n; i++){
            A[i] = (double *) malloc(n * sizeof(double));
            if(A[i] == NULL){
                printf("Alocacao Invalida");
                exit(1);
            }
        }    
    } else {
        printf("Alocacao Invalida");
        exit(1);
    }
    return A;
}

void preenchimentoMatriz(double **A, int n){
    printf("Digite os valores da matriz A: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf(" %lf", &A[i][j]);
        }
    }
}

void preenchimentoVetorSolucao(double *b, int n){
    printf("Digite os valores do vetor solucao b: \n");
    for(int i = 0; i < n; i++){
        printf("b[%d] = ", i+1);
        scanf(" %lf", &b[i]);
    }
}

void impressaoMatriz(double **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            printf("%.2lf  ", M[i][j]);
        }
        if(i != n-1) printf("%.2lf\n    ", M[i][n-1]);
        else printf("%.2lf\n", M[i][n-1]);
    }
}

void impressaoVetorSolucao(double *b, int n){
    for(int i = 0; i < n-1; i++){
        printf("%.2lf  ", b[i]);
    }
    printf("%.2lf]\n", b[n-1]);
}