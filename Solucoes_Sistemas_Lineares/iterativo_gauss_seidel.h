#ifndef ITERATIVO_GAUSS_SEIDEL_H
#define ITERATIVO_GAUSS_SEIDEL_H

void criterioDeSassenfeld(double **C, int n);
void metodoGaussSeidel(double **C, double *g, double *X, int n, double epsilon, int nMax);
void controleGaussSeidel(double **A, int n);

#endif