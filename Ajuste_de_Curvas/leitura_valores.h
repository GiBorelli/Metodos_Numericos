#ifndef LEITURA_VALORES_H
#define LEITURA_VALORES_H

int verificaValidadePonto(double **pontos, double x, int n);
void leituraPontosVerificada(double **pontos, int n);
void leituraPontos(double **pontos, int n);
void leituraPontosArq(double **pontos, int n, FILE *arq);
void procuraIntervalo(double **pontos, int pos, int n, double *intervalo);
int apagaLinha(double **pontos, int linha, int n);
int limpezaValoresRepetidos(double **pontos, int n);
double **controleLeituraValores(int *quantPontos);

#endif