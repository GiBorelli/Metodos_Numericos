#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "auxiliares.h"
#include "leitura_valores.h"

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

void leituraPontosArq(double **pontos, int n, FILE *arq){
    char *linha = (char *) malloc(256 * sizeof(char));
    int i = 0, res;
    while (fgets(linha, 256, arq) != NULL){
        size_t len = strlen(linha);
        while (len > 0 && (linha[len-1] == '\n' || linha[len-1] == '\r')) {
            linha[--len] = '\0';
        }
        if ((res = sscanf(linha, "%lf %lf", &pontos[i][0], &pontos[i][1])) == 2) {
            printf("Linha %d: %.2f, %.2f\n", i, pontos[i][0], pontos[i][1]);
        }
        i++;
    }
    free(linha);
}

double **controleLeituraTerminal(int *quantPontos){
    printf("Digite a quantidade de pontos do conjunto: ");
    scanf(" %d", quantPontos);
    if(quantPontos <= 0){
        printf("Quantidade de pontos invalida.\n");
        return NULL;
    }

    double **pontos = alocacaoMatriz(pontos, *quantPontos, 2);

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

double **controleLeituraArquivo(int *quantPontos){
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
        printf("%s", nome_arq);
        if(sscanf(nome_arq, "%d", quantPontos) == 1){
            printf("Quantidade de pontos inicial: %d \n", *quantPontos);
        }
    }

    double **pontos = alocacaoMatriz(pontos, *quantPontos, 2);
    leituraPontosArq(pontos, *quantPontos, arq);
    printf("Fazendo a limpeza de valores x repetidos. \n");
    *quantPontos = limpezaValoresRepetidos(pontos, *quantPontos);
    printf("Quantidade de pontos total: %d \n", *quantPontos);

    fclose(arq);
    return pontos;
}