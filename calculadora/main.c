#include <stdio.h>       // Biblioteca padrão para entrada/saída
#include "calculadora.h" // Incluímos nosso módulo para usar suas funções

int main() {
    int x = 10;
    int y = 5;

    // Chamamos as funções que foram declaradas em "calculadora.h"
    // e implementadas em "calculadora.c".
    int resultado_soma = somar(x, y);
    int resultado_subtracao = subtrair(x, y);

    printf("O programa principal está usando o módulo de calculadora!\n");
    printf("A soma de %d e %d é: %d\n", x, y, resultado_soma);
    printf("A subtração de %d por %d é: %d\n", x, y, resultado_subtracao);

    return 0;
}