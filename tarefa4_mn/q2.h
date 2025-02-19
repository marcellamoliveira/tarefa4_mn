#pragma once
#ifndef Q2_H
#define Q2_H


double lagrangeInversa(double temperaturas[], double caloresEspecificos[], int n, double C);

double newtonInversa(double temperaturas[], double caloresEspecificos[], int n, double C);


double erroAbsoluto(double valor1, double valor2);
double erroRelativo(double valorAproximado, double valorExato);

#endif