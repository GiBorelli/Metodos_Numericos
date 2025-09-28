/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c minimos_quadrados.c  auxiliares.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "minimos_quadrados.h"

int main(){
    int quantPontos;
    printf("Digite a quantidade de pontos do conjunto: ");
    scanf(" %d", &quantPontos);

    double **pontos = alocacaoMatrizPontos(pontos, quantPontos);
    for(int i = 0; i < quantPontos; i++){
        printf("Digite o valor x do ponto %d: ", i+1);
        scanf(" %lf", &pontos[i][0]);
        printf("Digite o valor y para x = %.4lf: ", pontos[i][0]);
        scanf(" %lf", &pontos[i][1]);
    }

    int escolha;
    do{      
        int n;
        printf("Escolha o expoente da curva desejada: ");
        scanf(" %d", &n);

        ajusteCurva(pontos, quantPontos, n);

        printf("Caso deseje fazer mais um ajuste de curva para essa tabela de valores, digite 1.\n");
        scanf(" %d", &escolha);
    } while(escolha == 1);
    
    liberaMatriz(pontos, quantPontos);
    printf("Encerrando Programa.\n");
    return 0;
}