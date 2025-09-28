#ifndef AJUSTE_VALORES_H
#define AJUSTE_VALORES_H

int verificaValidadePonto(double **pontos, double x, int n);
void leituraPontosVerificada(double **pontos, int n);
void leituraPontos(double **pontos, int n);
void procuraIntervalo(double **pontos, int pos, int n, double *intervalo);
int apagaLinha(double **pontos, int linha, int n);
int limpezaValoresRepetidos(double **pontos, int n);

#endif