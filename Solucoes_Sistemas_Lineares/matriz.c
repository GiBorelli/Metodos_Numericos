#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

double **preenchimentoMatrizArquivo(int *n, char nome_arq[150], FILE *arq){
    printf("Pegando a dimensao da matriz da primeira linha do arquivo.\n");
    if(fgets(nome_arq, 256, arq) != NULL){
        printf("%s", nome_arq);
        if(sscanf(nome_arq, "%d", n) == 1){
           printf("Matriz %dx%d \n", *n, *n);
        }
        else{
            printf("Primeira linha com valor nao valido para processamento.\n");
            return NULL;
        }
    }  
    
    double **A = alocacaoMatrizQuadrada(A, *n);

    char *linha = (char *) malloc(256 * sizeof(char));
    int i = 0, j, res;
    printf("Valores lidos: \n");
    while (i < *n && fgets(linha, 256, arq) != NULL){
        j = 0;
        char *token = strtok(linha, "\t");
        while(token != NULL && j < *n){
            char *fim_ptr;
            A[i][j] = strtod(token, &fim_ptr);

            if (*fim_ptr == '\0' || *fim_ptr == '\n') {         //verificando se a conversao foi bem sucedida
                printf("Valor lido: %.6lf\n", A[i][j]);
            }
            j++;
            token = strtok(NULL, "\t");
        }
        i++;
    }
    free(linha);
    return A;
}

void preenchimentoVetorSolucao(double *b, int n){
    printf("Digite os valores do vetor solucao b: \n");
    for(int i = 0; i < n; i++){
        printf("b[%d] = ", i+1);
        scanf(" %lf", &b[i]);
    }
}

double *preenchimentoVetorArquivo(int n, char nome_arq[150], FILE *arq){
    double *b = (double *) malloc(n * sizeof(double));
    char *linha = (char *) malloc(256 * sizeof(char));

    int i = 0, res;
    printf("b = [");
    while(i < n && fgets(linha, 256, arq) != NULL){
        if(sscanf(linha, "%lf", b[i]) == 1){
           printf(" %.6lf ", b[i]);
        }
        else{
            printf("Primeira linha com valor nao valido para processamento.\n");
            return NULL;
        }
        b++;
    }
    printf("]");
    free(linha);
    return b;
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
            printf("%.2lf  ", M[i][j]);
        }
        if(i != n-1) printf("%.2lf\n    ", M[i][n-1]);
        else printf("%.2lf\n", M[i][n-1]);
    }
}

void impressaoVetor(double *v, int n){
    for(int i = 0; i < n-1; i++){
        printf("%.2lf  ", v[i]);
    }
    printf("%.2lf]\n", v[n-1]);
}

void impressaoTriangularSuperior(double **U, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(j < i) printf("0.00  ");
            else printf("%.2lf  ", U[i][j]);
        }
        if(i != n-1) printf("%.2lf\n    ", U[i][n-1]);
        else printf("%.2lf\n", U[i][n-1]);
    }
}

void impressaoTriangularInferior(double **L, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i) printf("0.00  ");
            else if(j == i) printf("1.00  ");
            else printf("%.2lf  ", L[i][j]);
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