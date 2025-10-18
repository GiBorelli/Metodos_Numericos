#ifndef RESOLUCAO_H
#define RESOLUCAO_H

double *retroSubstituicao(int n, double **A, double *b);
void controleRetroSubstituicao(double **A, int n, int escolha, char nome_arq[150], FILE *arq);

#endif