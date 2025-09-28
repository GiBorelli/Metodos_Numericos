#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "minimos_quadrados.h"

double **metodoMinimosQuadrados(double **pontos, int quantPontos, int n, double *b){    //n = expoente
    double **A = alocacaoMatrizQuadrada(A, n+1);
    int i, j, q;
    for(i = 0; i < n+1; i++){
        for(j = 0; j < n+1; j++){
            if(i != n || j != n){
                A[i][j] = somatorioXExponencial(pontos, quantPontos, 2*n -i -j);
            }
            else{
                A[n][n] = quantPontos;
            }   
        }
        for(q = 0; q < quantPontos; q++){
            b[i] += (pontos[q][1] * exponencial(pontos[q][0], n-i));
        }
    }
    return A;
}

void ajusteCurva(double **pontos, int quantPontos, int n){
    double *b = inicializacaoVetorZerado(b, n+1);

    double **A = metodoMinimosQuadrados(pontos, quantPontos, n, b);

    eliminacaoGauss(A, b, n+1);
    double *x = retroSubstituicao(A, b, n+1);

    printf("A funcao encontrada para o ajuste e: \n");
    for(int i = 0; i < n+1; i++){
        if(i < n-1){
            if(x[i] != 0)
                printf("%.2lf * x^%d + ", x[i], n-i);
        }
        else if(i == n-1){
            if(x[i] != 0 && x[i+1] != 0)
                printf("%.2lf * x + ", x[i]);
            else if(x[i] != 0)
                printf("%.2lf * x", x[i]);
        }
        else 
            printf("%.2lf\n", x[i]);
    }

    liberaMatriz(A, n+1);
    free(b);
    free(x);
}

