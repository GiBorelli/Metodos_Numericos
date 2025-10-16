#ifndef RESOLUCAO_DEFINICAO_H
#define RESOLUCAO_DEFINICAO_H

double *retroSubstituicao(double **A, double *b, int n);
void eliminacaoGauss(double **A, double *b, int n);
void impressaoPolinomio(double *p, int n);
double **construcaoSistema(double **pontos, int n);
void controleResolucaoDefinicao(double **pontos, int n);

#endif