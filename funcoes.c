#include <stdio.h>

double modulo(double x){
    return x < 0? (-1)*x : x;
}

double Xquadrado(double x){
    return x*x;
}

double XquadradoMenosDois(double x){
    return x*x -2;
}

double doisX(double x){
    return 2*x;
}

double derivadaDefinicao(double (*func)(double), double x){
    double h = 0.0001;
    double num = func(x+h) - func(x);
    return num/h;
}