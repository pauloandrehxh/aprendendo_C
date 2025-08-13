#include <stdio.h>
#include <stdbool.h> // Para usar o tipo booleano

int main() {
  // Principais tipos de dados
  // int = números inteiros       (4 bytes)
  // float = número decimal       (4 bytes)
  // double = número decimal      (8 bytes)
  // chat = caractere único       (1 byte)
  // char[] = array de caracteres (tamanho variado)
  // bool = verdadeiro ou falso   (1 byte, necessita do <stdbool.h>)

  int idade = 25;
  float dinheiro = 25.50;
  char nota = 'A';
  char nome[] = "Paulo Andre";
  bool disponivel = true;

  printf("Ola %s\n", nome);
  printf("Voce tem %i anos de idade\n", idade);
  printf("Voce tem na conta: R$ %.2f reais\n", dinheiro);
  printf("Sua nota: %c\n", nota);

  if(disponivel){
    printf("Disponivel: Sim");
  } 
  else {
    printf("Disponive: Nao");
  }
  
  return 0;
}