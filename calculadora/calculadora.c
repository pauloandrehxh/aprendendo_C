#include "calculadora.h" // Incluímos o cabeçalho para garantir consistência

/*
 * A diretiva #include "calculadora.h" é importante. Ela faz com que o compilador
 * verifique se as funções que estamos implementando aqui correspondem exatamente
 * às declarações feitas no arquivo .h (mesmo nome, mesmos tipos de parâmetros e retorno).
 *
 * Note que usamos aspas duplas (" ") para incluir arquivos locais do nosso projeto,
 * e não os sinais de menor/maior que (< >), que são usados para bibliotecas do sistema.
 */

// --- Definição das Funções ---
// Agora implementamos o corpo das funções.

int somar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}