#include "Rendimento.h"

double calcularRendimento(double distanciaInicial, double distanciaFinal, double combustivel) {
    return (distanciaFinal - distanciaInicial) / combustivel;
}