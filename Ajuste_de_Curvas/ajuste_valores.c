#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "ajuste_valores.h"

int verificaValidadePonto(double **pontos, double x, int n){
    int valido = 1;
    for(int i = 0; i < n && valido == 1; i++){
        if(pontos[i][0] == x){
            valido = 0;
        }
    }
    return valido;
}

void leituraPontosVerificada(double **pontos, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor x do ponto %d: ", i+1);
        scanf(" %lf", &pontos[i][0]);
        if(verificaValidadePonto(pontos, pontos[i][0], i)){
            printf("Digite o valor y para x = %.2lf: ", pontos[i][0]);
            scanf(" %lf", &pontos[i][1]);
        }
        else{
            printf("x = %.2lf ja informado. Tente novamente.\n ", pontos[i][0]);
            i--;
        }
    }
}

void leituraPontos(double **pontos, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor x do ponto %d: ", i+1);
        scanf(" %lf", &pontos[i][0]);
        printf("Digite o valor y para x = %.2lf: ", pontos[i][0]);
        scanf(" %lf", &pontos[i][1]);
    }
}

void procuraIntervalo(double **pontos, int pos, int n, double *intervalo){
    double maior = DBL_MAX, menor = DBL_MIN;
    for(int i = 0; i < n; i++){
        if(pontos[i][0] < pontos[pos][0] && pontos[i][0] > menor){      //pontos[pos][0] = valor x repetido
            menor = pontos[i][0];
            intervalo[0] = pontos[i][1];
        }
        else if(pontos[i][0] > pontos[pos][0] && pontos[i][0] < maior){
            maior = pontos[i][0];
            intervalo[1] = pontos[i][1];
        }
    }

    if(menor == DBL_MIN)
        intervalo[0] = pontos[pos][1];
    if(maior == DBL_MAX)
        intervalo[1] = pontos[pos][1];
}

int apagaLinha(double **pontos, int linha, int n){
    for(int i = linha; i < n-1; i++){
        pontos[i][0] = pontos[i+1][0];
        pontos[i][1] = pontos[i+1][1];
    }
    return n-1;
}

int limpezaValoresRepetidos(double **pontos, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && pontos[i][0] == pontos[j][0]){     //Se ponto repetido
                double *intervalo = (double *) malloc(2 * sizeof(double));
                procuraIntervalo(pontos, i, n, intervalo);
                if(pontos[i][1] >= intervalo[0] && pontos[i][1] <= intervalo[1])    //ou se ambos dentro intervalor apaga segunda linha repetida
                    n = apagaLinha(pontos, j, n);
                else    //if(pontos[j][1] >= intervalo[0] && pontos[j][1] <= intervalo[1])
                    n = apagaLinha(pontos, i, n);
                j--;
            }
        }
    }
    return n;
}

