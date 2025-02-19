#include <iostream>
#include "q1.h"
#include "q2.h"

#include "rendimento.h"

int main() {
    std::cout << "Questao 1" << std::endl;

    double temperaturas[] = {20, 30, 45, 55};
    double caloresEspecificos[] = { 0.99807, 0.99826, 0.99849, 0.99919 };
    int n = 4;
    double T = 25;

    double resultadoSL = linear(temperaturas, caloresEspecificos, n, T);
    double resultadoLagrange = lagrange(temperaturas, caloresEspecificos, n, T);
    double resultadoNewton = newton(temperaturas, caloresEspecificos, n, T);

    std::cout << "Valor Real: 0.99852" << std::endl;
    std::cout << "a) Sistema Linear: " << resultadoSL << std::endl;
    std::cout << "b) Lagrange: " << resultadoLagrange << std::endl;
    std::cout << "c) Newton: " << resultadoNewton << std::endl;
    


    std::cout << "\nQuestao 2" << std::endl;

    double temperaturas_escolhidas[] = { 20, 30, 45 };
    double caloresEspecificos_escolhidos[] = { 0.99807, 0.99826, 0.99849 };
    int grau = 3;
    double C = 0.99835;

    double resultadoLagrangeInverso = lagrangeInversa(temperaturas_escolhidas, caloresEspecificos_escolhidos, grau, C);
    double resultadoNewtonInverso = newtonInversa(temperaturas_escolhidas, caloresEspecificos_escolhidos, grau, C);
    double erroAbs = erroAbsoluto(resultadoLagrangeInverso, resultadoNewtonInverso);
    double erroRelL = erroRelativo(resultadoLagrangeInverso, resultadoNewtonInverso);
    double erroRelN = erroRelativo(resultadoNewtonInverso, resultadoLagrangeInverso);

    std::cout << "a) Temperatura por Lagrange: " << resultadoLagrangeInverso << std::endl;
    std::cout << "b) Temperatura por Newton: " << resultadoNewtonInverso << std::endl;
    std::cout << "c) Erro Absoluto: " << erroAbs << std::endl;
    std::cout << "d) Erro Relativo(Lagrange): " << erroRelL << " e Erro Relativo(Newton): " << erroRelN << std::endl;
   


    std::cout << "\nQuestao 3" << std::endl;

    // item a
    double tempo[] = {0, 10, 30, 60, 90, 120, 140};
    double distancia[] = {0, 8, 27, 58, 100, 140, 160};

    double tempo_escolhidos[] = { 30, 60, 90 };
    double distancia_escolhidos[] = { 27, 58, 100 };

    double tempoMeio = 70;
    double resultadoLagrange2 = lagrange(tempo_escolhidos, distancia_escolhidos, 3, tempoMeio);

    std::cout << "a) Distancia percorrida em " << tempoMeio << " min (Lagrange): " << resultadoLagrange2 << " km" << std::endl;



    // item b
    double distanciaInicial = lagrange(tempo_escolhidos, distancia_escolhidos, 3, 80);
    double distanciaFinal = 160;   
    double combustivel = 8.0;      

    double rendimento = calcularRendimento(distanciaInicial, distanciaFinal, combustivel);
    std::cout << "b) Rendimento do carro no trecho final: " << rendimento << " km/l" << std::endl;

    std::cout << "Distancia percorrida em 80 min: " << distanciaInicial << " km" << std::endl;


    return 0;
}
