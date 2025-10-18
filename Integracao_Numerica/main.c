/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c auxiliares.c leitura_valores.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "auxiliares.h"
#include "leitura_valores.h"
#include "regra_trapezio.h"

int main(){
    double (*funcao) (double x) = EulerElevadoX;
    
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

    double integral;
    if(pontos != NULL){
        do{
            printf("Escolha a Regra a ser aplicada: \n");
            printf(" 1- Regra do Trapezio \n 2- Regra do Trapezio Repetida \n");
            printf(" 3- Primeira Regra de Simpson (1/3) \n 4- Primeira Regra de Simpson (1/3) Repetida\n");
            scanf(" %d", &escolha);
            switch (escolha) {
                case 1: integral = controleRegraTrapezio(pontos, quantPontos, funcao);
                    break;
                case 2: integral = controleTrapezioRepetido(pontos, quantPontos, funcao);
                    break;
                case 3: 1;
                    break;
                case 4: 2;
                    break;
                default: printf("Opcao invalida.\n");
                    break;
            }
        } while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4);
    }
    else 
        printf("Nao foi possivel fazer a leitura dos valores, compile novamente o programa.\n");
    
    printf("Encerrando Programa.\n");
    return 0;
}
