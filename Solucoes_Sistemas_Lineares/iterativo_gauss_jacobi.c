#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "iterativo_gauss_jacobi.h"

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

double maximo(double *v, int n){
    double maior = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

void testeConvergencia(double **C, int n){
    double *alpha = inicializacaoVetorZerado(alpha, n), *ghama = inicializacaoVetorZerado(ghama, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            alpha[i] += modulo(C[i][j]);
            ghama[i] += modulo(C[j][i]);
        }
    }

    double normaLinha = maximo(alpha, n);
    double normaColuna = maximo(ghama, n);

    if(normaLinha < 1 | normaColuna < 1)
        printf("Existe condicao suficiente para o Metodo Iterativo de Gauss-Jacobi convergir.\n");
    else
        printf("Nao se pode informar se existe ou nao convergencia para o Metodo Iterativo de Gauss-Jacobi.\n");
}

void metodoGaussJacobi(double **A, double **C, double *g, int n, double epsilon, int nMax){

}

void controleGaussJacobi(double **A, int n){
    double *b = (double *) malloc(n * sizeof(double));
    preenchimentoVetorSolucao(b, n);
    double **C = alocacaoMatrizQuadrada(C, n);
    double *g = (double *) malloc(n * sizeof(double));

    construcaoCg(A, b, n, C, g);
    impressaoMatriz(C, n);
    impressaoVetor(g, n);
    free(b);

    int escolha;
    printf("Caso queira descobrir a convergencia do Metodo, digite 1. Se nao quiser, digite 0: ");
    scanf(" %d", &escolha);
    if(escolha) testeConvergencia(C, n);

    double epsilon;
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    int nMax;
    printf("Digite a quantidade maxima de iteracoes do metodo: ");
    scanf(" %d", &nMax);

    metodoGaussJacobi(A, C, g, n, epsilon, nMax);

}





