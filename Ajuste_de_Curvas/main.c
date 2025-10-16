/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c minimos_quadrados.c auxiliares.c leitura_valores.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "leitura_valores.h"
#include "auxiliares.h"
#include "minimos_quadrados.h"

int main(){
    int quantPontos, escolha;
    double **pontos;

    do{
        printf("Escolha o metodo de leitura dos pontos: \n 1- Leitura do teclado (terminal)\n 2- Leitura de Arquivo\n");
        scanf(" %d", &escolha);
        if(escolha != 1 && escolha != 2) printf("Valor invalido. \n");
    } while(escolha != 1 && escolha != 2);

    if(escolha == 1){
        pontos = controleLeituraTerminal(&quantPontos);
    }
    else{
        pontos = controleLeituraArquivo(&quantPontos);
    }

    if(pontos != NULL){
        do{      
            int n;
            printf("Escolha o expoente da curva desejada: ");
            scanf(" %d", &n);

            ajusteCurva(pontos, quantPontos, n);

            printf("Caso deseja fazer mais um ajuste de curva para essa tabela de valores, digite 1.\n");
            scanf(" %d", &escolha);
        } while(escolha == 1);
    }
    else
        printf("Nao foi possivel fazer a leitura dos valores, compile novamente o programa.\n"); 
    
    liberaMatriz(pontos, quantPontos);
    printf("Encerrando Programa.\n");
    return 0;
}