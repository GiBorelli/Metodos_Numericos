#include <stdio.h>
#include "funcoes.h"
#include "metodonewton_raphson.h"

//Funcao que utiliza a definicao de derivada de uma funcao para calculo, por padrao h = 0.001
double MetodoNewtonRaphsonAproximado(double (*func)(double), double (*df) (double (*func)(double), double), double x0, double epsilon){
    int n = 1;
    double xAtual = x0, fxAtual = func(xAtual), fxProx;
    double xProx = xAtual - (fxAtual/df(func, xAtual));
    while(modulo(fxProx = func(xProx)) > epsilon && modulo(xProx - xAtual) > epsilon){
        xAtual = xProx;
        fxAtual = fxProx;
        if(df(func, xAtual) != 0){
            xProx = xAtual - (fxAtual/df(func, xAtual));
        }
        else{
            printf("Tentativa de divisao por 0 em xk = %.8lf \n", xAtual);
            break;
        }
        n++;
    }
    printf("Apos %d interacoes, a solucao aproximada e f(%.8lf) = %.16lf \n", n, xProx, fxProx);
    return xProx;
}

//Funcao que recebe a derivada da funcao para o calculo
double MetodoNewtonRaphson(double (*func)(double), double (*df) (double), double x0, double epsilon){
    int n = 1;
    double xAtual = x0, fxAtual = func(xAtual), fxProx;
    double xProx = xAtual - (fxAtual/df(xAtual));
    while(modulo(fxProx = func(xProx)) > epsilon && modulo(xProx - xAtual) > epsilon){
        xAtual = xProx;
        fxAtual = fxProx;
        if(df(xAtual) != 0){
            xProx = xAtual - (fxAtual/df(xAtual));
        }
        else{
            printf("Tentativa de divisao por 0 em xk = %.8lf \n", xAtual);
            break;
        }
        n++;
    }
    printf("Apos %d interacoes, a solucao encontrada e f(%.8lf) = %.16lf \n", n, xProx, fxProx);
    return xProx;
}

void controleNewtonRaphson(){
    double x0, epsilon;
    printf("Digite o valor inicial (x0): ");
    scanf(" %lf", &x0);
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    double (*funcao) (double x) = XquadradoMenosDois;
    double (*derivada) (double x) = doisX;
    
    double r = MetodoNewtonRaphson(funcao, derivada, x0, epsilon);
    double r2 = MetodoNewtonRaphsonAproximado(funcao, derivadaDefinicao, x0, epsilon);

}
