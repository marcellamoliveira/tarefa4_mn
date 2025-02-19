#include "q2.h"
#include <cmath>
#include <vector>

double lagrangeInversa(double temperaturas[], double caloresEspecificos[], int n, double C) {
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {

        double termo = temperaturas[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                termo *= (C - caloresEspecificos[j]) / (caloresEspecificos[i] - caloresEspecificos[j]);
            }
        }
        resultado += termo;
    }

    return resultado;
}

double newtonInversa(double temperaturas[], double caloresEspecificos[], int n, double C) {
    std::vector<std::vector<double>> tabela(n, std::vector<double>(n));

    for (int i = 0; i < n; i++) {
        tabela[i][0] = temperaturas[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            tabela[i][j] = (tabela[i + 1][j - 1] - tabela[i][j - 1]) / (caloresEspecificos[i + j] - caloresEspecificos[i]);
        }
    }

    double resultado = tabela[0][0];
    double termo = 1.0;
    for (int i = 1; i < n; i++) {
        termo *= (C - caloresEspecificos[i - 1]);
        resultado += tabela[0][i] * termo;
    }

    return resultado;
}


double erroAbsoluto(double valor1, double valor2) {
    return fabs(valor1 - valor2);
}

double erroRelativo(double valorAproximado, double valorExato) {
    return fabs(valorAproximado - valorExato) / fabs(valorExato);
}
