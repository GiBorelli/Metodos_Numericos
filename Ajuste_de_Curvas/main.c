/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c minimos_quadrados.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "minimos_quadrados.h"

int main(){
    int escolha;
    do{
        int n;
        printf("Escolha o expoente da curva desejada: \n");
        scanf(" %d", &n);

        int quantPontos;
        printf("Digite a quantidade de pontos do conjunto: ");
        scanf(" %d", &quantPontos);
        double **pontos = (double **) malloc(quantPontos * sizeof(double *));
        for(int i = 0; i < quantPontos; i++){
            pontos[i] = (double *) malloc(2 * sizeof(double));
            printf("Digite o valor x e o y: ");
            scanf(" %lf %lf ", &pontos[0], &pontos[1]);
        }

        ajusteCurva(pontos, quantPontos, n);

        printf("Caso deseje fazer mais um ajuste de curvas, digite 1.\n");
        scanf("%d", &escolha);
    } while(escolha == 1);
    
    printf("Encerrando Programa.\n");
    return 0;
}