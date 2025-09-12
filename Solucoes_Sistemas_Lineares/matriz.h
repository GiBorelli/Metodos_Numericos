#ifndef MATRIZ_H
#define MATRIZ_H

double **alocacaoMatrizQuadrada(double **A, int n);
void liberaMatrizQuadrada(double **A, int n);
void preenchimentoMatriz(double **A, int n);
void preenchimentoVetorSolucao(double *b, int n);
double *inicializacaoVetorZerado(double *v, int n);
void impressaoMatriz(double **M, int n);
void impressaoVetor(double *v, int n);
void impressaoTriangularSuperior(double **U, int n);
void impressaoTriangularInferior(double **L, int n);
double *multiplicacaoMatrizVetor(double **M, double *v, int n);

#endif