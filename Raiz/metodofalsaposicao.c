#include <stdio.h>
#include <math.h>
#include "funcoes.h"
#include "teoremabolzano.h"

void MetodoFalsaPosicao(double (*func)(double), double a, double b, double epsilon){
    double funcA = func(a), funcB = func(b);
    double x, funcX;
    int n = 0;
    while((b-a) > epsilon){
        n++;
        x = (a * funcB - b * funcA)/(funcB - funcA);
        funcX = func(x);
        printf("%2d - [%.8f; %.8lf] - f(%.8lf) = %.8lf\n", n, a, b, x, funcX);
        if((modulo(funcX)) < epsilon)
            break;
        if(funcA * funcX < 0){
            b = x;
            funcB = funcX;
        }
        else{      //if (funcB * funcX < 0)
            a = x;
            funcA = funcX;
        }
    }
    printf("Apos %d interacoes, a solucao encontrada e f(%.4lf) = %.4lf \n", n, x, funcX);
}

void controleFalsaPosicao(){
    double a, b, epsilon;
    printf("Digite o valor inferior e o superior do intervalo: ");
    scanf(" %lf %lf", &a, &b);
    printf("Digite o erro maximo do calculo: ");
    scanf(" %lf", &epsilon);
    double (*funcao) (double x) = XquadradoMenosDois;

    if(teoremaDeBolzano(funcao, a, b) == 1){
        printf("Existe zero no intervalo [%.4lf, %.4lf] da funcao.\n", a, b);
        MetodoFalsaPosicao(funcao, a, b, epsilon);
    }
    else
        printf("Nao se pode informar se existe ou nao zero no intervalo [%.4lf, %.4lf] da funcao.\n", a, b);

}