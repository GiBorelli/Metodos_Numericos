#ifndef MATRIZ_H
#define MATRIZ_H

double **alocacaoMatrizQuadrada(double **A, int n);
void preenchimentoMatriz(double **A, int n);
void preenchimentoVetorSolucao(double *b, int n);
void impressaoMatriz(double **M, int n);
void impressaoVetorSolucao(double *b, int n);

#endif