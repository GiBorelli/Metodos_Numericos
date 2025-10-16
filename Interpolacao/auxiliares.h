#ifndef AUXILIARES_H
#define AUXILIARES_H

double **alocacaoMatriz(double **A, int n, int m);
void liberaMatriz(double **A, int n);
double *inicializacaoVetorZerado(double *v, int n);
void impressaoMatriz(double **M, int n, int m);
double *copiaColunaParaVetor(double **M, double *b, int c, int n);
double exponencial(double v, int n);

#endif