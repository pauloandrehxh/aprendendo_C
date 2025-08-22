#include <stdio.h>

int main() {
    int idade = 20;
    int* ponteiro_para_idade = &idade;
    
    printf("Valor de idade: %d\n", idade);
    printf("Endereço de idade: %p\n", ponteiro_para_idade);

    // Usando o * para MODIFICAR o valor através do ponteiro
    *ponteiro_para_idade = 30; // "Vá até o endereço e mude o valor para 30"
    
    // Usando o * para LER o valor através do ponteiro
    printf("O valor no endereço apontado é: %d\n", *ponteiro_para_idade); // Vai imprimir 30




    return 0;
}