#include <stdio.h>
#include "funcoes.h"
#include "teoremabolzano.h"

int teoremaDeBolzano(double (*f)(double), double a, double b){
    double fA, fB;
    double mult = (fA = f(a)) * (fB = f(b));
    //printf("f(a) = f(%.3lf) * f(b) = f(%.3lf) = %.3f\n", fA, fB, mult);
    return mult < 0 ? 1:0;
}

void controleBolzano(){
    double a, b;
    printf("Digite o valor inferior e o superior do intervalo: ");
    scanf(" %lf %lf", &a, &b);

    printf("Resultado do Teorema de Bolzano se f(x) = x^2 -2: ");
    if(teoremaDeBolzano(XquadradoMenosDois, a, b) == 1)
        printf("Existe zero no intervalo [%.3lf, %.3lf] da funcao.\n", a, b);
    else
        printf("Nao se pode informar se existe ou nao zero no intervalo [%.3lf, %.3lf] da funcao.\n", a, b);       

}
