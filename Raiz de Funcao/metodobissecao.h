/*
O teorema de Bolzano nos fornece condições suficientes para a existência do zero 
de uma função. Este é uma aplicação direta do teorema do valor intermediário.

Teorema de Bolzano: Se f:[a,b] --> R, y = f(x), é uma função contínua tal que
f(a) * f(b) < 0, entã existe x* E (a, b) tal que f(x*) = 0.
*/

#ifndef METODOBISSECAO_H
#define METODOBISSECAO_H

int quantMetodoBissecao(double a, double b, double epsilon);
void MetodoBissecao(double (*func)(double), double a, double b, double epsilon, int n);
void controleBissecao();

#endif