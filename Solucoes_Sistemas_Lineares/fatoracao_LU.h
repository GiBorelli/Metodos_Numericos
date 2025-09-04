#ifndef FATORACAO_LU_H
#define FATORACAO_LU_H

void fatoracaoLU(double **A, double *b, int n, double **L, double **U);
void controleFatoracaoLU(double **A, int n);

#endif