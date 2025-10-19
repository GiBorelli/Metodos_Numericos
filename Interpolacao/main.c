/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c auxiliares.c leitura_valores.c resolucao_definicao.c forma_newton.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "leitura_valores.h"
#include "resolucao_definicao.h"
#include "forma_newton.h"

int main(){
    int quantPontos, escolha;
    double **pontos;
    do{
        do{
            printf("\nEscolha o metodo de leitura dos pontos: \n 1- Leitura do teclado (terminal)\n 2- Leitura de Arquivo\n");
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
                printf("Escolha o Metodo a ser aplicado: \n");
                printf(" 1- Definicao - Sistema Linear \n 2- Forma de Newton\n");
                scanf(" %d", &escolha);
                if(escolha == 1){
                    controleResolucaoDefinicao(pontos, quantPontos-1);      //quantidade de pontos - 1 = expoente máximo da função
                }
                else{
                    controleNewton(pontos, quantPontos);
                }
            } while(escolha != 1 && escolha != 2);
            printf("\nCaso deseje fazer a aplicacao de mais um metodos, digite 1. Se nao desejar, digite qualquer outro numero.\n");
            scanf("%d", &escolha);
        }
        else{
            printf("Nao foi possivel fazer a leitura dos valores, tente novamente.\n");
            escolha = 1;
        }
    } while (escolha == 1);
    
    printf("Encerrando Programa.\n");
    return 0;
}