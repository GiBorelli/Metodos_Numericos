#include <stdio.h>
#include "funcoes.h"
#include "metodosecante.h"

double MetodoSecante(double (*func)(double), double x0, double x1, double epsilon){
    int n = 1;
    double xAnt = x0, fxAnt = func(xAnt), xAtual = x1, fxAtual = func(xAtual);
    double xProx = xProx = xAtual - (fxAtual*(xAtual-xAnt)/(fxAtual-fxAnt)), fxProx;
    while(modulo(fxProx = func(xProx)) > epsilon && modulo(xProx - xAtual) > epsilon){
        xAnt = xAtual;
        fxAnt = fxAtual;
        xAtual = xProx;
        fxAtual = fxProx;
        xProx = xAtual - (fxAtual*(xAtual-xAnt)/(fxAtual-fxAnt));
        n++;
    }
    printf("Apos %d interacoes, a solucao encontrada e f(%.8lf) = %.16lf \n", n, xProx, fxProx);
    return xProx;
}

void controleSecante(){
    double x0, x1, epsilon;
    printf("Digite os primeiros dois valores (x0 e x1): ");
    scanf(" %lf %lf", &x0, &x1);
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    double (*funcao) (double x) = XquadradoMenosDois;
    
    double r = MetodoSecante(funcao, x0, x1, epsilon);

}
