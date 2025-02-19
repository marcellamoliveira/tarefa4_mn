#pragma once

#ifndef Q1_H
#define Q1_H


double linear(double temperaturas[], double caloresEspecificos[], int n, double T);

double lagrange(double temperaturas[], double caloresEspecificos[], int n, double T);

double newton(double temperaturas[], double caloresEspecificos[], int n, double T);
#endif
