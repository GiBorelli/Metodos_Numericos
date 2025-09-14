#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "iterativos.h"
#include "iterativo_gauss_seidel.h"

void criterioDeSassenfeld(double **C, int n){       //Convergencia do Método Gauss-Seidel
    double *lBetas = inicializacaoVetorZerado(lBetas, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            lBetas[i] += modulo(C[i][j]) * lBetas[j];
        }
        for(int j = i+1; j < n; j++){       //Calculo beta_1 vem direto para segundo laço
            lBetas[i] += modulo(C[i][j]);
        }
        //printf("Beta%d: %.4lf \n", i+1, lBetas[i]);
    }

    double beta = maximoEmModulo(lBetas, n);
    if(beta < 1) printf("O Metodo Iterativo de Gauss-Seidel converge para a solucao de Ax = b. \n");
    else printf("Nao se pode informar se existe ou nao convergencia para o Metodo Iterativo de Gauss-Seidel.\n");

    free(lBetas);
}


void metodoGaussSeidel(double **C, double *g, double *Xk, int n, double epsilon, int nMax){
    int i, k = 0;
    double *dif = (double *) malloc(n * sizeof(double));
    do{
        double *multMXk = multiplicacaoMatrizTriSuperiorVetor(C, Xk, n);       // C_tringular_superior X(k) = N X(k)
        //printf("%lf %lf %lf\n", multMXk[0], Xk[0], g[0]);
        //X(k+1)[0]
        dif[0] = Xk[0];
        Xk[0] = multMXk[0] + g[0];
        dif[0] = Xk[0] - dif[0];        // X(k+1) - X(k)
        double *multMXk1;       
        for(i = 1; i < n; i++){
            dif[i] = Xk[i];
            multMXk1 = multiplicacaoMatrizTriInferiorVetor(C, Xk, n);       // C_triangular_inferior X(k+1) = M X(k+1)
            Xk[i] = multMXk1[i] + multMXk[i] + g[i];       //X(k+1) = M X(k+1) + N X(k) + g
            dif[i] = Xk[i] - dif[i];        // X(k+1) - X(k)
        }
        k++;
        
        printf("X = [");
        for(i = 0; i < n-1; i++){
            printf("%.6lf  ", Xk[i]);
        }
        printf("%.6lf] \n", Xk[i]);

    } while(maximoEmModulo(dif, n)/maximoEmModulo(Xk, n) > epsilon && k < nMax);          //Erro = ||X(k+1)-X(k)||_inf / ||X(k+1)||_inf > epsilon && ...
    if(k == nMax) printf("Numero de tentativas estourado, aproximacao sem conformacao com erro.\n");
    free(dif);
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

