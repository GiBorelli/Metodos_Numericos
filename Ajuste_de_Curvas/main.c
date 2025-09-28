/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c minimos_quadrados.c auxiliares.c ajuste_valores.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "ajuste_valores.h"
#include "auxiliares.h"
#include "minimos_quadrados.h"

int main(){
    int quantPontos, escolha = 0;
    printf("Digite a quantidade de pontos do conjunto: ");
    scanf(" %d", &quantPontos);

    double **pontos = alocacaoMatrizPontos(pontos, quantPontos);
    printf("Caso deseje verificacao de valores x repetidos na leitura, digite 1. \nSe nao desejar, somente um dos valores repetidos sera considerado (digite qualquer numero).\n");
    scanf(" %d", &escolha);
    if(escolha == 1)
        leituraPontosVerificada(pontos, quantPontos);
    else{
        leituraPontos(pontos, quantPontos);
        quantPontos = limpezaValoresRepetidos(pontos, quantPontos);
        printf("Quantidade de pontos: %d\n", quantPontos);
        for(int i = 0; i < quantPontos; i++){
            printf("%.2lf  ", pontos[i][0]);
            if(i != quantPontos-1) printf("%.2lf\n", pontos[i][1]);
            else printf("%.2lf\n", pontos[i][1]);
        }
    } 

    do{      
        int n;
        printf("Escolha o expoente da curva desejada: ");
        scanf(" %d", &n);

        ajusteCurva(pontos, quantPontos, n);

        printf("Caso deseja fazer mais um ajuste de curva para essa tabela de valores, digite 1.\n");
        scanf(" %d", &escolha);
    } while(escolha == 1);
    
    liberaMatriz(pontos, quantPontos);
    printf("Encerrando Programa.\n");
    return 0;
}