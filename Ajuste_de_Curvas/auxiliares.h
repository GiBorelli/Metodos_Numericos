#ifndef AUXILIARES_H
#define AUXILIARES_H

double **alocacaoMatrizQuadrada(double **A, int n);
double **alocacaoMatrizPontos(double **A, int n);
void liberaMatriz(double **A, int n);
double *inicializacaoVetorZerado(double *v, int n);
double *retroSubstituicao(double **A, double *b, int n);
void eliminacaoGauss(double **A, double *b, int n);
double exponencial(double v, int n);
double somatorioXExponencial(double **pontos, int n, int exp);

#endif