#ifndef MATRIZ_H
#define MATRIZ_H

double **alocacaoMatrizQuadrada(double **A, int n);
void liberaMatrizQuadrada(double **A, int n);
void preenchimentoMatriz(double **A, int n);
double **preenchimentoMatrizArquivo(int *n, char nome_arq[150], FILE *arq);
void preenchimentoVetorSolucao(double *b, int n);
double *preenchimentoVetorArquivo(int n, char nome_arq[150], FILE *arq);
double *inicializacaoVetorZerado(double *v, int n);
//int verificaTriangularSuperior(double **U, int n);
void impressaoMatriz(double **M, int n);
void impressaoVetor(double *v, int n);
void impressaoTriangularSuperior(double **U, int n);
void impressaoTriangularInferior(double **L, int n);
double *multiplicacaoMatrizVetor(double **M, double *v, int n);
double *multiplicacaoMatrizTriInferiorVetor(double **L, double *v, int n);
double *multiplicacaoMatrizTriSuperiorVetor(double **U, double *v, int n);

#endif