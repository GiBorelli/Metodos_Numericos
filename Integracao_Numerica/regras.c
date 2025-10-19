#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "leitura_valores.h"

double regraTrapezio(double *x, int n, double (*f)(double)){
    double h = x[1]-x[0];
    //printf("f(x0) = %.8lf, f(x%d) = %.8lf\n", f(x[0]), n-1, f(x[n-1]));
    return ((f(x[0]) + f(x[n-1])) * (h/2));
}

double controleTrapezioRepetido(double *pontos, int n, double (*f)(double)){
    double integral = 0;
    int escolha, ult = n-1;
    printf("Caso deseje que os pontos sejam calculados por divisao, digite 1. \nSe nao desejar, somente os valores lidos serao considerados (digite um numero diferente de 1).\n");
    scanf(" %d", &escolha);
    
    if(escolha == 1){
        printf("Digite a quantidade de intervalos desejada: ");
        scanf("%d", &n);
        double dois_pontos[2], h = (pontos[ult]-pontos[0])/(n-1);
        for(int i = 0; i < n; i++){
            dois_pontos[0] = pontos[0] + h*i;
            dois_pontos[1] = pontos[0] + h*(i+1);
            integral += regraTrapezio(dois_pontos, 2, f);
        }
    }
    else{
        for(int i = 0; i < n-1; i++){
            double *dois_pontos = copiaAlgumasLinhas(pontos, n, dois_pontos, i, 2);
            integral += regraTrapezio(dois_pontos, 2, f);
        }
    }
    return integral;
}

double primeiraSimpson(double *x, double (*f)(double), double h){
    //printf("Is = %.8lf + 4 * %.8lf + %.8lf\n", f(x[0]), f(x[1]), f(x[2]));
    return h/3 * (f(x[0]) + 4*f(x[1]) + f(x[2]));
}

double controlePrimeiraSimpson(double *pontos, int n, double (*f)(double)){
    int pm = (n-1)/2;
    printf("Usando x0 = %.8lf, x%d = %.8lf e x%d = %.8lf. \n", pontos[0], pm, pontos[pm], n-1, pontos[n-1]);
    double *tres_pontos = (double *) malloc(3 * sizeof(double));
    tres_pontos[0] = pontos[0];
    tres_pontos[1] = pontos[pm];
    tres_pontos[2] = pontos[n-1];
    return (primeiraSimpson(tres_pontos, f, pontos[pm]-pontos[0]));
}

double controlePrimeiraSimpsonRepetida(double *pontos, int n, double (*f)(double)){
    double integral = 0;
    int escolha, ult = n-1;
    printf("Caso deseje que os pontos sejam calculados por divisao, digite 1. \nSe nao desejar, somente os valores lidos serao considerados (digite um numero diferente de 1).\n");
    scanf(" %d", &escolha);
    
    if(escolha == 1){
        printf("Digite um numero par de divisoes: ");
        scanf("%d", &n);
        double tres_pontos[2], h = (pontos[ult]-pontos[0])/n;
        //printf("n = %d, h = %.6lf \n", n, h);
        for(int i = 0; i <= n-2; i+=2){
            tres_pontos[0] = pontos[0] + h*i;
            tres_pontos[1] = pontos[0] + h*(i+1);
            tres_pontos[2] = pontos[0] + h*(i+2);
            integral += primeiraSimpson(tres_pontos, f, h);
        }
    }
    else{
        double h = (pontos[n-1]-pontos[0])/(n-1);
        for(int i = 0; i < n-2; i+=2){
            double *tres_pontos = copiaAlgumasLinhas(pontos, n, tres_pontos, i, 3);
            integral += primeiraSimpson(tres_pontos, f, h);
        }
    }
    return integral;
}

