#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "forma_newton.h"

double **construcaoDiferencasDivididas(double **pontos, int n){
    double **dif = alocacaoMatriz(dif, n, n);
    int i, j;
    for(i = 0; i < n; i++){
        dif[i][0] = pontos[i][1];
    }
    for(j = 1; j < n; j++){
        for(i = 0; i < n-j; i++){
            dif[i][j] = (dif[i+1][j-1]-dif[i][j-1])/(pontos[i+j][0]-pontos[i][0]);
            /*printf("dif[%d][%d] = %.4lf\n", i, j, dif[i][j]);
            printf("%.4lf - %.4lf / %.4lf - %.4lf = ", dif[i+1][j-1], dif[i][j-1], pontos[i+1][0], pontos[i][0]);
            printf("%.4lf / %.4lf\n", dif[i+1][j-1]-dif[i][j-1], pontos[i+j][0]-pontos[i][0]);*/
        }
    }

    return dif;
}

void controleNewton(double **pontos, int n){
    double **difDiv = construcaoDiferencasDivididas(pontos, n);
    
    printf("O polinomio de Newton e: \n");
    printf("p%d (x) = ", n-1);
    for(int i = 0; i < n; i++){
        if(i != 0) printf(" + ");
        for(int j = 1; j <= i; j++){
            if(pontos[j-1][0] < 0.0)
                printf("(x +%.4lf) * ", modulo(pontos[j-1][0]));
            else
                printf("(x -%.4lf) * ", pontos[j-1][0]);
        }
        if( difDiv[0][i] < 0)
            printf("(%.4lf)", difDiv[0][i]);
        else 
            printf("%.4lf", difDiv[0][i]);
    }
    printf("\n");
}


