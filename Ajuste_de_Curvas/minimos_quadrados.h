#ifndef MINIMOS_QUADRADOS_H
#define MINIMOS_QUADRADOS_H

double **metodoMinimosQuadrados(double **pontos, int quantPontos, int n, double *b);
void ajusteCurva(double **pontos, int quantPontos, int n);

#endif