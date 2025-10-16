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

double *retroSubstituicao(double **A, double *b, int n){
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

double exponencial(double v, int n){
    double res = 1;
    for(int i = 1; i <= n; i++)
        res *= v;
    return res;
}

double somatorioXExponencial(double **pontos, int n, int exp){
    double soma = 0;
    for(int i = 0; i < n; i++){
        soma += exponencial(pontos[i][0], exp);
    }
    return soma;
}

void impressaoFuncao(double *x, int n){
    for(int i = 0; i < n+1; i++){
        if(x[i] >= -0.00001 && x[i] <= 0.00001)     //Arredondamento para valores muito próximos de 0, 5 casas de aproximação
            x[i] = 0.0;
        else if(x[i] < 0){
            if(i < n-1)
                printf("%.5lf * x^%d ", x[i], n-i);
            else if(i == n-1){
                printf("%.5lf * x ", x[i]);
            }
            else 
                printf("%.5lf\n", x[i]);
        }
        else{
            if(i == 0){
                if(i != n-1 && i != n)
                    printf("%.5lf * x^%d ", x[i], n-i);
                else if(i == n-1)
                    printf("%.5lf * x ", x[i]);
                else 
                    printf("%.5lf\n", x[i]);
            }
            else if(i < n-1)
                printf("+ %.5lf * x^%d ", x[i], n-i);
            else if(i == n-1)
                printf("+ %.5lf * x ", x[i]);
            else 
                printf("+ %.5lf\n", x[i]);
        }
    }
}
