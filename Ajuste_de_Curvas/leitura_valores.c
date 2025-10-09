#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "leitura_valores.h"
#include "auxiliares.h"

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

void leituraPontosArq(double **pontos, int n, FILE *arq){
    char *linha = (char *) malloc(256 * sizeof(char)), *token;
    int i = 0, j = 0;
    while (fgets(linha, 256, arq) != NULL){
        j = 0;
        while(linha[j] != '\n') j++;
        linha[j] = '\0';
        token = strtok(linha, "\t");
        j = 0;
        while (token != NULL) {
            pontos[i][j] = atof(token);
            printf("%.4lf  ", pontos[i][j]);
            token = strtok(NULL, "\t");
            j++;
        }
        i++;
        printf("\n");
    }
    free(linha);
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

double **controleLeituraValores(int *quantPontos){
    double **pontos = alocacaoMatriz(pontos, *quantPontos, *quantPontos);
    int escolha;
    do{
        printf("Escolha o método de leitura dos pontos: \n 1- Leitura do teclado (terminal)\n 2- Leitura de Arquivo\n");
        scanf(" %d", &escolha);
    } while(escolha != 1 && escolha != 2);

    if(escolha == 1){
        printf("Caso deseje verificacao de valores x repetidos na leitura, digite 1. \nSe nao desejar, somente um dos valores repetidos sera considerado (digite um numero diferente de 1).\n");
        scanf(" %d", &escolha);
        if(escolha == 1)
            leituraPontosVerificada(pontos, *quantPontos);
        else{
            leituraPontos(pontos, *quantPontos);
            *quantPontos = limpezaValoresRepetidos(pontos, *quantPontos);
        } 
    }
    else{
        char nome_arq[150];
        printf("Digite o nome do arquivo a ser lido (incluindo a extensao do arquivo, ex: .txt ou .dat): \n");
        scanf("%s", &nome_arq);

        FILE *arq;
        arq = fopen(nome_arq, "r");     //somente leitura
        if(arq == NULL){
            printf("Erro na abertura do arquivo. \n");
            return NULL;
        }
        leituraPontosArq(pontos, *quantPontos, arq);
        fclose(arq);
    }

    return pontos;
}


