/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c funcoes.c teoremabolzano.c metodobissecao.c metodofalsaposicao.c metodonewton_raphson.c metodosecante.c -o main
        .\main
*/

#include <stdio.h>
#include <math.h>
#include "funcoes.h"
#include "teoremabolzano.h"
#include "metodobissecao.h"
#include "metodofalsaposicao.h"
#include "metodonewton_raphson.h"
#include "metodosecante.h"

int main(){
    int escolha;
    do{
        printf("\nEscolha o Teorema ou Metodo a ser aplicado: \n");
        printf(" 1- Teorema de Bolzano \n 2- Metodo da Bissecao \n 3- Metodo da Falsa Posicao\n");
        printf(" 4- Metodo de Newton-Raphson (Tangentes) \n 5- Metodo da Secante\n");
        scanf(" %d", &escolha);
        switch (escolha) {
            case 1: controleBolzano();
                break;
            case 2: controleBissecao();
                break;
            case 3: controleFalsaPosicao();
                break;
            case 4: controleNewtonRaphson();
                break;
            case 5: controleSecante();
                break;
            default: printf("Opcao invalida.\n");
                break;
        }
        printf("\nCaso deseje fazer a aplicacao de mais um metodos, digite 1. Se nao desejar, digite qualquer outro numero.\n");
        scanf("%d", &escolha);
    } while(escolha == 1);
    printf("Encerrando Programa.\n");
    return 0;
}