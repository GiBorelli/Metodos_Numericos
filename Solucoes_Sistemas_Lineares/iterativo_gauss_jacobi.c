#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j)
                alpha[i] += modulo(C[i][j]);
        }
    }

    if(maximo(alpha, n) < 1){       //Norma linha
        printf("Existe condicao suficiente para o Metodo Iterativo de Gauss-Jacobi convergir.\n");
        free(alpha);
        return;
    }

    for(j = 0; j < n; j++){
        for(i = 0; i < n; i++){
            if(i != j)
                ghama[j] += modulo(C[i][j]);
        }
    }
    
    if(maximo(ghama, n) < 1)        //Norma coluna
        printf("Existe condicao suficiente para o Metodo Iterativo de Gauss-Jacobi convergir.\n");
    else
        printf("Nao se pode informar se existe ou nao convergencia para o Metodo Iterativo de Gauss-Jacobi.\n");
    free(ghama);
}

void metodoGaussJacobi(double **A, double **C, double *g, double *X, int n, double epsilon, int nMax){
    int i, k = 0;
    double *dif = (double *) malloc(n * sizeof(double)), modInfX;
    do{
        double *mult = multiplicacaoMatrizVetor(C, X, n);       // X(k) C
        for(i = 0; i < n; i++){
            dif[i] = X[i];
            X[i] = mult[i] + g[i];      // X(k+1) = C X(k) + g
            dif[i] = X[i] - dif[i];
        }
        k++;

        printf("X = [");
        for(int i = 0; i < n-1; i++){
            printf("%.5lf  ", X[i]);
        }
        printf("%.5lf] \n", X[n-1]);

    } while((modInfX = modulo(maximo(dif, n))/modulo(maximo(X, n))) > epsilon && modInfX > epsilon && k < nMax);

    free(dif);
}

void controleGaussJacobi(double **A, int n){
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
    if(escolha) testeConvergencia(C, n);

    double *X0 = (double *) malloc(n * sizeof(double));
    printf("Se quiser informar os valores para X0, digite 1. Se quiser valores aleatorios, digite 0: ");
    scanf(" %d", &escolha);
    if(escolha){
        printf("Digite os valores do vetor X(0): \n");
        for(int i = 0; i < n; i++){
            printf("X(0)[%d] = ", i+1);
            scanf(" %lf", &X0[i]);
        }
    } 
    else{
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            X0[i] = (double) rand() /(double) RAND_MAX;
            //printf("X(0)[%d] = %.5lf\n", i+1, X0[i]);
        }
    }

    double epsilon;
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    int nMax;
    printf("Digite a quantidade maxima de iteracoes do metodo: ");
    scanf(" %d", &nMax);

    metodoGaussJacobi(A, C, g, X0, n, epsilon, nMax);

    free(b);
    free(g);
    free(X0);
    liberaMatrizQuadrada(C, n);
}
