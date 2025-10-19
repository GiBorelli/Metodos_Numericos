#ifndef AUXILIARES_H
#define AUXILIARES_H

double **alocacaoMatriz(double **A, int n, int m);
void liberaMatriz(double **A, int n);
double *inicializacaoVetorZerado(double *v, int n);
void impressaoMatriz(double **M, int n, int m);
double *copiaAlgumasLinhas(double *v, int n, double *v2, int ini, int quant);

#endif