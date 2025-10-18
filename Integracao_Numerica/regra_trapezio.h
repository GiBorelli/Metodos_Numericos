#ifndef REGRA_TRAPEZIO_H
#define REGRA_TRAPEZIO_H

void RegraTrapezio(double **pontos, int n);
double controleTrapezioRepetido(double **pontos, int n, double (*f)(double));
double controleRegraTrapezio(double **pontos, int n, double (*f)(double));

#endif