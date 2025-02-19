#include "q1.h"
#include <vector>
#include <cmath>

double linear(double temperaturas[], double caloresEspecificos[], int n, double T) {
    std::vector<std::vector<double>> A(n, std::vector<double>(n + 1));

    for (int i = 0; i < n; i++) {
        double x = 1.0;
        for (int j = 0; j < n; j++) {
            A[i][j] = x;
            x *= temperaturas[i];
        }
        A[i][n] = caloresEspecificos[i];
    }

    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        std::swap(A[i], A[maxRow]);

        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    std::vector<double> coef(n);
    for (int i = n - 1; i >= 0; i--) {
        coef[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            coef[i] -= A[i][j] * coef[j];
        }
        coef[i] /= A[i][i];
    }

    double resultado = 0.0;
    double x = 1.0;
    for (int i = 0; i < n; i++) {
        resultado += coef[i] * x;
        x *= T;
    }

    return resultado;
}



double lagrange(double temperaturas[], double caloresEspecificos[], int n, double T) {
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {
        double termo = caloresEspecificos[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                termo *= (T - temperaturas[j]) / (temperaturas[i] - temperaturas[j]);
            }
        }
        resultado += termo;
    }

    return resultado;
}





double newton(double temperaturas[], double caloresEspecificos[], int n, double T) {
    std::vector<std::vector<double>> tabela(n, std::vector<double>(n));

    for (int i = 0; i < n; i++) {
        tabela[i][0] = caloresEspecificos[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            tabela[i][j] = (tabela[i + 1][j - 1] - tabela[i][j - 1]) / (temperaturas[i + j] - temperaturas[i]);
        }
    }

    double resultado = tabela[0][0];
    double termo = 1.0;
    for (int i = 1; i < n; i++) {
        termo *= (T - temperaturas[i - 1]);
        resultado += tabela[0][i] * termo;
    }

    return resultado;
}