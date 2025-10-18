#ifndef ITERATIVO_GAUSS_JACOBI_H
#define ITERATIVO_GAUSS_JACOBI_H

void testeConvergenciaGaussJacobi(double **C, int n);
void metodoGaussJacobi(double **C, double *g, double *X, int n, double epsilon, int nMax);
void controleGaussJacobi(double **A, int n, int escolha, char nome_arq[150], FILE *arq);

#endif