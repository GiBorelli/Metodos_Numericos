#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "iterativos.h"

void construcaoCg(double **A, double *b, int n, double **C, double *g){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if(i == j)
                C[i][j] = 0;
            else
                C[i][j] = (-A[i][j])/A[i][i];
        }
        g[i] = b[i]/A[i][i];
    }
}

double modulo(double x){
    return x < 0? (-1)*x : x;
}

double maximoEmModulo(double *v, int n){
    double maior = modulo(v[0]);
    for(int i = 1; i < n; i++){
        if(modulo(v[i]) > maior)
            maior = modulo(v[i]);
    }
    return maior;
}

double *criacaoX0(double *X0, int n){
    X0 = (double *) malloc(n * sizeof(double));
    int escolha, i;
    printf("Se quiser informar os valores para X0, digite 1. Se quiser valores aleatorios, digite 0: ");
    scanf(" %d", &escolha);
    if(escolha){
        printf("Digite os valores do vetor X(0): \n");
        for(i = 0; i < n; i++){
            printf("X(0)[%d] = ", i+1);
            scanf(" %lf", &X0[i]);
        }
    } 
    else{
        srand(time(NULL));
        printf("X(0) = [");
        for(i = 0; i < n-1; i++){
            X0[i] = (double) rand() /(double) RAND_MAX;
            printf("%.5lf  ", X0[i]);
        }
         printf("%.5lf]\n", X0[i]);
    }
    return X0;
}
