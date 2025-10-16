#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "resolucao_definicao.h"

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

void impressaoPolinomio(double *p, int n){
    for(int i = 0; i < n+1; i++){
        if(p[i] >= -0.00001 && p[i] <= 0.00001)     //Arredondamento para valores muito próximos de 0, 5 casas de aproximação
            p[i] = 0.0;
        else if(p[i] < 0){
            if(i < n-1)
                printf("%.5lf * x^%d ", p[i], n-i);
            else if(i == n-1){
                printf("%.5lf * x ", p[i]);
            }
            else 
                printf("%.5lf\n", p[i]);
        }
        else{
            if(i == 0){
                if(i != n-1 && i != n)
                    printf("%.5lf * x^%d ", p[i], n-i);
                else if(i == n-1)
                    printf("%.5lf * x ", p[i]);
                else 
                    printf("%.5lf\n", p[i]);
            }
            else if(i < n-1)
                printf("+ %.5lf * x^%d ", p[i], n-i);
            else if(i == n-1)
                printf("+ %.5lf * x ", p[i]);
            else 
                printf("+ %.5lf\n", p[i]);
        }
    }
}

double **construcaoSistema(double **pontos, int n){      //n = expoente, (n+1) pontos distintos -> [0,n]
    double **A = alocacaoMatriz(A, n+1, n+1);
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            A[i][j] = exponencial(pontos[i][0], n-j);       //x[i]^(n-i)
        }
    }
    return A;
}

void controleResolucaoDefinicao(double **pontos, int n){        //n = expoente, (n+1) pontos distintos -> [0,n]
    double **A = construcaoSistema(pontos, n);
    double *b = copiaColunaParaVetor(pontos, b, 1, n+1);       //b = f(x[i])
    
    eliminacaoGauss(A, b, n+1);
    double *x = retroSubstituicao(A, b, n+1);

    impressaoPolinomio(x, n);

    liberaMatriz(A, n+1);
    free(b);
    free(x);
}


