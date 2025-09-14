#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "iterativos.h"
#include "iterativo_gauss_jacobi.h"

void testeConvergenciaGaussJacobi(double **C, int n){
    double *alpha = inicializacaoVetorZerado(alpha, n), *ghama = inicializacaoVetorZerado(ghama, n);
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j)
                alpha[i] += modulo(C[i][j]);
        }
    }

    if(maximoEmModulo(alpha, n) < 1){       //Norma linha
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
    
    if(maximoEmModulo(ghama, n) < 1)        //Norma coluna
        printf("Existe condicao suficiente para o Metodo Iterativo de Gauss-Jacobi convergir.\n");
    else
        printf("Nao se pode informar se existe ou nao convergencia para o Metodo Iterativo de Gauss-Jacobi.\n");
    free(ghama);
}

void metodoGaussJacobi(double **C, double *g, double *X, int n, double epsilon, int nMax){
    int i, k = 0;
    double *dif = (double *) malloc(n * sizeof(double)), modInfXk1;     //diferenca e modulo infinito de X(k+1)
    do{
        double *mult = multiplicacaoMatrizVetor(C, X, n);       // C X(k)
        for(i = 0; i < n; i++){
            dif[i] = X[i];
            X[i] = mult[i] + g[i];      // X(k+1) = C X(k) + g
            dif[i] = X[i] - dif[i];
        }
        k++;

        printf("X = [");
        for(i = 0; i < n-1; i++){
            printf("%.5lf  ", X[i]);
        }
        printf("%.5lf] \n", X[n-1]);

    } while(maximoEmModulo(dif, n)/maximoEmModulo(X, n) > epsilon && k < nMax);     //Erro = ||X(k+1)-X(k)||_inf / ||X(k+1)||_inf > epsilon && ...
    if(k == nMax) printf("Numero de tentativas estourado, aproximacao sem conformidade com o erro.\n");
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
    if(escolha) testeConvergenciaGaussJacobi(C, n);

    double *X0 = criacaoX0(X0, n);

    double epsilon;
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    int nMax;
    printf("Digite a quantidade maxima de iteracoes do metodo: ");
    scanf(" %d", &nMax);

    metodoGaussJacobi(C, g, X0, n, epsilon, nMax);

    free(b);
    free(g);
    free(X0);
    liberaMatrizQuadrada(C, n);
}
