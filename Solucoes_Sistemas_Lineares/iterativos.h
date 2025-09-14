#ifndef ITERATIVOS_H
#define ITERATIVOS_H

void construcaoCg(double **A, double *b, int n, double **C, double *g);
double modulo(double x);
double maximoEmModulo(double *v, int n);
double *criacaoX0(double *X0, int n);

#endif