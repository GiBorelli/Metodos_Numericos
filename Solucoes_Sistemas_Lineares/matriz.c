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

void liberaMatrizQuadrada(double **A, int n){
    for(int i = 0; i < n; i++){
        free(A[i]);
    }
    free(A);
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

double *inicializacaoVetorZerado(double *v, int n){
    v = (double *) malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
        v[i] = 0;
    return v;
}

/*int verificaTriangularSuperior(double **U, int n){
    int triangular = 1;
    for(int i = 0; i < n; i++){
        if(sizeof(U[i]) / sizeof(double) != n){
            triangular = 0;
            break;
        }
        for(int j = 0; j < n; j++){
            if((j < i && U[i][j] != 0.0) || (j == i && U[i][j] == 0.0)){
                triangular = 0;
                break;
            }
        }
    }
    return triangular;
}*/

void impressaoMatriz(double **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            printf("%.8lf  ", M[i][j]);
        }
        if(i != n-1) printf("%.8lf\n    ", M[i][n-1]);
        else printf("%.8lf\n", M[i][n-1]);
    }
}

void impressaoVetor(double *v, int n){
    for(int i = 0; i < n-1; i++){
        printf("%.8lf  ", v[i]);
    }
    printf("%.8lf]\n", v[n-1]);
}

void impressaoTriangularSuperior(double **U, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(j < i) printf("%.8lf ", 0);
            else printf("%.8lf  ", U[i][j]);
        }
        if(i != n-1) printf("%.8lf\n    ", U[i][n-1]);
        else printf("%.8lf\n", U[i][n-1]);
    }
}

void impressaoTriangularInferior(double **L, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i) printf("%.8lf ", 0);
            else if(j == i) printf("%.8lf ", 1);
            else printf("%.8lf  ", L[i][j]);
        }
        if(i != n-1) printf("\n    ");
        else printf("\n");
    }
}

double *multiplicacaoMatrizVetor(double **M, double *v, int n){
    double *res = inicializacaoVetorZerado(res, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i] += M[i][j] * v[j];
        }
    }
    return res;
}

double *multiplicacaoMatrizTriInferiorVetor(double **L, double *v, int n){
    double *res = inicializacaoVetorZerado(res, n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            res[i] += L[i][j] * v[j];
        }
    }
    return res;
}

double *multiplicacaoMatrizTriSuperiorVetor(double **U, double *v, int n){
    double *res = inicializacaoVetorZerado(res, n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            res[i] += U[i][j] * v[j];
        }
    }
    return res;
}