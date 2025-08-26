#ifndef METODOSECANTE_H
#define METODOSECANTE_H

double MetodoSecante(double (*func)(double), double x0, double x1, double epsilon);
void controleSecante();

#endif