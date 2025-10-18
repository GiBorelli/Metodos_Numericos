#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

double **alocacaoMatriz(double **A, int n, int m){
    A = (double **) malloc(n * sizeof(double *));
    if(A != NULL){
        for(int i = 0; i < n; i++){
            A[i] = (double *) malloc(m * sizeof(double));
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

void liberaMatriz(double **A, int n){
    for(int i = 0; i < n; i++){
        free(A[i]);
    }
    free(A);
}

double *inicializacaoVetorZerado(double *v, int n){
    v = (double *) malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
        v[i] = 0;
    return v;
}

void impressaoMatriz(double **M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            printf("%.2lf  ", M[i][j]);
        }
        printf("%.2lf\n", M[i][m-1]);
    }
}

double *copiaColunaParaVetor(double **M, double *b, int c, int n){
    b = (double *) malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        b[i] = M[i][c];
    }
    return b;
}

double exponencial(double v, int n){
    double res = 1;
    for(int i = 1; i <= n; i++)
        res *= v;
    return res;
}

double modulo(double x){
    return x < 0.0? -x : x;
}