/*
    Para começar o código no terminal, digite os seguintes comandos: 
        gcc main.c matriz.c resolucao.c eliminacao_gauss.c fatoracao_LU.c iterativos.c iterativo_gauss_jacobi.c iterativo_gauss_seidel.c -o main
        .\main
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "resolucao.h"
#include "eliminacao_gauss.h"
#include "fatoracao_LU.h"
#include "iterativos.h"
#include "iterativo_gauss_jacobi.h"
#include "iterativo_gauss_seidel.h"

int main(){
    int escolha, escolha2, n;
    printf("Escolha a Solucao a ser aplicada: \n");
    printf(" 1- Resolucao Matrizes Triangulares \n 2- Metodo da Eliminacao de Gauss\n 3- Fatoracao LU\n");  //Métodos Diretos
    printf(" 4- Metodo Iterativo Gauss-Jacobi \n 5- Metodo Iterativo Gauss-Seidel\n");   //Métodos Iterativos
    scanf(" %d", &escolha);

    double **A;
    do{
        printf("Escolha o metodo de leitura da matriz: \n 1- Leitura do teclado (terminal) \n 2- Leitura de Arquivo\n");
        scanf(" %d", &escolha2);
        if(escolha2 != 1 && escolha2 != 2) printf("Valor invalido. \n");
    } while(escolha2 != 1 && escolha2 != 2);

    char nome_arq[150];
    FILE *arq;
    if(escolha2 == 1){
        printf("Digite a dimensao n da matriz quadrada: ");
        scanf(" %d", &n);
        A = alocacaoMatrizQuadrada(A, n);
        preenchimentoMatriz(A, n);
    }
    else{
        printf("Digite o nome do arquivo a ser lido (incluindo a extensao do arquivo, ex: .txt ou .dat): \n");
        scanf("%s", &nome_arq);
        arq = fopen(nome_arq, "r");     //somente leitura
        if(arq == NULL){
            printf("Erro na abertura do arquivo. \n");
            exit(1);
        }
        A = preenchimentoMatrizArquivo(&n, nome_arq, arq);
        impressaoMatriz(A, n);
    }

    switch (escolha) {
        case 1: controleRetroSubstituicao(A, n, escolha2, nome_arq, arq);
            break;
        case 2: controleEliminacaoGauss(A, n, escolha2, nome_arq, arq);
            break;
        case 3: controleFatoracaoLU(A, n);
            break;
        case 4: controleGaussJacobi(A, n, escolha2, nome_arq, arq);
            break;
        case 5: controleGaussSeidel(A, n, escolha2, nome_arq, arq);
            break;
        default: printf("Opcao invalida.\n");
            break;
    }

    liberaMatrizQuadrada(A, n);
    printf("Encerrando Programa.\n");
    return 0;
}