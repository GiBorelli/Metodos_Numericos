#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "auxiliares.h"
#include "leitura_valores.h"

int verificaValidadePonto(double *pontos, double x, int n){
    int valido = 1;
    for(int i = 0; i < n && valido == 1; i++){
        if(pontos[i] == x){
            valido = 0;
        }
    }
    return valido;
}

void leituraPontosVerificada(double *pontos, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor x do ponto %d: ", i+1);
        scanf(" %lf", &pontos[i]);
        if(!verificaValidadePonto(pontos, pontos[i], i)){
            printf("x = %.4lf ja informado. Tente novamente.\n ", pontos[i]);
            i--;
        }
    }
}

void leituraPontos(double *pontos, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor x do ponto %d: ", i+1);
        scanf(" %lf", &pontos[i]);
    }
}

int apagaLinha(double *pontos, int linha, int n){
    for(int i = linha; i < n-1; i++){
        pontos[i] = pontos[i+1];
    }
    return n-1;
}

int limpezaValoresRepetidos(double *pontos, int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(i != j && pontos[i] == pontos[j]){     //Se ponto repetido
                n = apagaLinha(pontos, j, n);
                j--;
            }
        }
    }
    return n;
}

void leituraPontosArq(double *pontos, int n, FILE *arq){
    char *linha = (char *) malloc(256 * sizeof(char));
    int i = 0, res;
    printf("Valores lidos: \n");
    while (i < n && fgets(linha, 256, arq) != NULL){
        size_t len = strlen(linha);
        while (len > 0 && (linha[len-1] == '\n' || linha[len-1] == '\r')) {
            linha[--len] = '\0';
        }
        if ((res = sscanf(linha, "%lf", &pontos[i])) == 1) {
            //printf("x%d = %.4f\n", i, pontos[i]);
        }else{
            printf("Valor invalido para uso.\n");
            exit(1);
        }
        i++;
    }
    free(linha);
}

double *controleLeituraTerminal(int *quantPontos, double (*f)(double)){
    printf("Digite a quantidade de pontos do conjunto: ");
    scanf(" %d", quantPontos);
    if(*quantPontos <= 1){
        printf("Quantidade de pontos invalida.\n");
        return NULL;
    }

    double *pontos = (double *) malloc(*quantPontos * sizeof(double));
    int escolha;
    printf("Caso deseje verificacao de valores x repetidos na leitura, digite 1. \nSe nao desejar, somente um dos valores repetidos sera considerado (digite um numero diferente de 1).\n");
    scanf(" %d", &escolha);

    if(escolha == 1){
        leituraPontosVerificada(pontos, *quantPontos);
    }
    else{
        leituraPontos(pontos, *quantPontos);
        *quantPontos = limpezaValoresRepetidos(pontos, *quantPontos);
    } 
    return pontos;
}

double *controleLeituraArquivo(int *quantPontos, double (*f)(double)){
    char nome_arq[150];
    printf("Digite o nome do arquivo a ser lido (incluindo a extensao do arquivo, ex: .txt ou .dat): \n");
    scanf("%s", &nome_arq);

    FILE *arq;
    arq = fopen(nome_arq, "r");     //somente leitura
    if(arq == NULL){
        printf("Erro na abertura do arquivo. \n");
        return NULL;
    }
    printf("Pegando a quantidade de valores para leitura da primeira linha do arquivo.\n");
    if(fgets(nome_arq, 256, arq) != NULL){
        if(sscanf(nome_arq, "%d", quantPontos) == 1){
           printf("Quantidade de pontos inicial: %d \n", *quantPontos);
        }
        else{
            printf("Primeira linha com valor nao valido para processamento.\n");
            return NULL;
        }
    }

    double *pontos = (double *) malloc(*quantPontos * sizeof(double));
    leituraPontosArq(pontos, *quantPontos, arq);
    printf("Fazendo a limpeza de valores x repetidos. \n");
    *quantPontos = limpezaValoresRepetidos(pontos, *quantPontos);
    if(*quantPontos <= 1){
        printf("Quantidade de pontos invalida.\n");
        return NULL;
    }
    printf("Quantidade de pontos total: %d \n", *quantPontos);

    fclose(arq);
    return pontos;
}