#include <stdio.h>

int main(){
  
  int numero;
  char caractere;

  // Código defeituoso

  // printf("Digite um número: ");
  // scanf("%d", &numero); // O problema começa aqui

  // printf("Digite um caractere: ");
  // scanf("%c", &caractere); // Este scanf parece ser "pulado"

  // printf("Número digitado: %d\n", numero);
  // printf("Caractere digitado: '%c'\n", caractere);

  // Código certo

  printf("Digite um número: ");
  scanf("%d", &numero); // O problema começa aqui

  printf("Digite um caractere: ");
  scanf(" %c", &caractere); // Este scanf parece ser "pulado"

  printf("Número digitado: %d\n", numero);
  printf("Caractere digitado: '%c'\n", caractere);

  return 0;
}