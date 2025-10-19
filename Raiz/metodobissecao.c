#include <stdio.h>
#include <math.h>
#include "funcoes.h"
#include "teoremabolzano.h"
#include "metodobissecao.h"

int quantMetodoBissecao(double a, double b, double epsilon){
    return (log10(b-a)-log10(epsilon))/log10(2) +1; 
}

void MetodoBissecao(double (*func)(double), double a, double b, double epsilon, int n){
    double funcA = func(a), funcB = func(b);
    double pm, funcPM;
    int i = 0;
    while(modulo(funcPM = func(pm = (a+b)/2)) > epsilon && i < n){      //i < n == (b-a) < epsilon
        //printf("f(a) = %.3lf e f(b) = %.3f; f(%.3lf) = %.3lf; e = %.3lf\n", funcA, funcB, pm, funcPM, epsilon);
        if(funcA * funcPM < 0){
            b = pm;
            funcB = funcPM;
        } else{
            a = pm;
            funcA = funcPM;
        }
        i++;
    }
    printf("Ponto medio na %d interacao que e solucao: f(pm) = f(%.10lf) = %.10lf\n", i, pm, funcPM);
}

void controleBissecao(){
    double a, b, epsilon;
    printf("Digite o valor inferior e o superior do intervalo: ");
    scanf(" %lf %lf", &a, &b);
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    double (*funcao) (double x) = raizCubica;
    int n;

    if(teoremaDeBolzano(funcao, a, b) == 1){
        printf("Existe zero no intervalo [%.6lf, %.6lf] da funcao.\n", a, b);
        n = quantMetodoBissecao(a, b, epsilon);
        printf("Sao necessarias %d interacoes para aproximar-se do zero (raiz) da funcao.\n", n);
    }
    else{
        printf("Nao se pode informar se existe ou nao zero no intervalo [%.4lf, %.4lf] da funcao.\n", a, b);
        printf("Digite um numero maximo de interacoes: ");
        scanf(" %d", &n);
    }
    MetodoBissecao(funcao, a, b, epsilon, n);
}
