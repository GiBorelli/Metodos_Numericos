#ifndef METODONEWTON_RAPHSON_H
#define METODONEWTON_RAPHSON_H

void MetodoNewtonRaphsonAproximado(double (*func)(double), double (*df) (double (*func)(double), double), double x0, double epsilon);
void MetodoNewtonRaphson(double (*func)(double), double (*df) (double), double x0, double epsilon);
void controleNewtonRaphson();

#endif