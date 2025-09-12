#ifndef ITERATIVO_GAUSS_JACOBI_H
#define ITERATIVO_GAUSS_JACOBI_H

void construcaoCg(double **A, double *b, int n, double **C, double *g);
void testeConvergencia(double **C, int n);
void metodoGaussJacobi(double **A, double **C, double *g, double *X, int n, double epsilon, int nMax);
void controleGaussJacobi(double **A, int n);

#endif