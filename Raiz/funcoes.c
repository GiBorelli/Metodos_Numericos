#include <stdio.h>
#include <math.h>

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

double XcuboMenosSenX(double x){
    return x*x*x - sin(x);
}

double tresXMenosCosXMaisUm(double x){
    return 3*x - cos(x) +1;
}

double limnatXMenosSenX(double x){
    return log(x) - sin(x);
}

double doisXMenoseElevadoaMenosX(double x){
    return 2*x - exp(-x);
}

double XCosXMenos2XQuadradoMaisTresXMenos1(double x){
    return x*cos(x) -2*x*x +3*x -1;
}

double raizCubica(double x){
    return cbrt(x);
}

