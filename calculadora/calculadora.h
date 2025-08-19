#ifndef CALCULADORA_H  // Início da "Guarda de Inclusão" (Header Guard)
#define CALCULADORA_H

/*
 * Guarda de Inclusão (Header Guard):
 * Essas linhas (#ifndef, #define, #endif) são cruciais. Elas evitam que o conteúdo
 * deste arquivo seja incluído mais de uma vez durante a compilação, o que causaria
 * erros de "redefinição". O nome CALCULADORA_H é uma convenção (NOME_DO_ARQUIVO_H).
 */

// --- Protótipos das Funções ---
// Aqui apenas declaramos as funções, sem o corpo (código).
// É a promessa de que essas funções existem em algum lugar.

/**
 * @brief Soma dois números inteiros.
 * @param a O primeiro número.
 * @param b O segundo número.
 * @return A soma de a e b.
 */
int somar(int a, int b);

/**
 * @brief Subtrai dois números inteiros.
 * @param a O primeiro número.
 * @param b O segundo número.
 * @return A subtração de a e b.
 */
int subtrair(int a, int b);

#endif // Fim da "Guarda de Inclusão"