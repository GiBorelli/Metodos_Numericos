#ifndef REGRA_TRAPEZIO_H
#define REGRA_TRAPEZIO_H

double regraTrapezio(double *x, int n, double (*f)(double));
double controleTrapezioRepetido(double *pontos, int n, double (*f)(double));
double primeiraSimpson(double *pontos, double (*f)(double), double h);
double controlePrimeiraSimpson(double *pontos, int n, double (*f)(double));
double controlePrimeiraSimpsonRepetida(double *pontos, int n, double (*f)(double));

#endif