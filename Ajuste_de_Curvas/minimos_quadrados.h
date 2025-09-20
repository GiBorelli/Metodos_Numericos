#ifndef MINIMOS_QUADRADOS_H
#define MINIMOS_QUADRADOS_H

double *retroSubstituicao(int n, double **A, double *b);
void eliminacaoGauss(double **A, double *b, int n);
void ajusteCurva(double **pontos, int quantPontos, int n);

#endif