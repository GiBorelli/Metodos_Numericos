#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "iterativos.h"
#include "iterativo_gauss_seidel.h"

void criterioDeSassenfeld(double **C, int n){       //Convergencia do Método Gauss-Seidel
    double *lBetas = inicializacaoVetorZerado(lBetas, n);
    double beta = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            lBetas[i] += modulo(C[i][j]) * lBetas[j];
        }
        for(int j = i+1; j < n; j++){       //Calculo beta_1 vem direto para segundo laço
            lBetas[i] += modulo(C[i][j]);
        }
        if(lBetas[i] > beta)
            beta = lBetas[i];
        //printf("Beta%d: %.4lf \n", i+1, lBetas[i]);
    }

    if(beta < 1) printf("O Metodo Iterativo de Gauss-Seidel converge para a solucao de Ax = b. \n");
    else printf("Nao se pode informar se existe ou nao convergencia para o Metodo Iterativo de Gauss-Seidel.\n");

    free(lBetas);
}


void controleGaussSeidel(double **A, int n){
    double *b = (double *) malloc(n * sizeof(double));
    preenchimentoVetorSolucao(b, n);
    double **C = alocacaoMatrizQuadrada(C, n);
    double *g = (double *) malloc(n * sizeof(double));

    construcaoCg(A, b, n, C, g);
    
    printf("A matriz C criada e: \nC = ");
    impressaoMatriz(C, n);
    printf("O vetor g criado e: \ng = [");
    impressaoVetor(g, n);

    int escolha;
    printf("Caso queira descobrir a convergencia do Metodo, digite 1. Se nao quiser, digite 0: ");
    scanf(" %d", &escolha);
    if(escolha) criterioDeSassenfeld(C, n);

    double *X0 = criacaoX0(X0, n);

    double epsilon;
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    int nMax;
    printf("Digite a quantidade maxima de iteracoes do metodo: ");
    scanf(" %d", &nMax);

    metodoGaussSeidel(C, g, X0, n, epsilon, nMax);

    free(b);
    free(g);
    free(X0);
    liberaMatrizQuadrada(C, n);
}

