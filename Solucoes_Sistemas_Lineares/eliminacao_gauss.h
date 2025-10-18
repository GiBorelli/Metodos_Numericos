#ifndef ELIMINACAO_GAUSS_H
#define ELIMINACAO_GAUSS_H

void eliminacaoGauss(double **A, double *b, int n);
void controleEliminacaoGauss(double **A, int n, int escolha, char nome_arq[150], FILE *arq);

#endif