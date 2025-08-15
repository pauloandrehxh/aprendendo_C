#include <stdio.h>

int main(){
  int num = 100;           // Variavel para testar ponteiro
  int idade;              // Variável para guardar a idade (inteiro)
  char primeiroNome[30]; // Variável para guardar o primeiro nome (string)
  char frase[50];       // Variável para guardar frase inteira usando fgets()
  

  // Analisando o valor e endereço de uma variável
  printf("Valor do número: %i\n", num);
  printf("Endereco da variável num: %p\n", &num); 
  // É usado %p para imprimir endereços (ponteiros) 
  
  // Para pegar um input utiliza a função scanf()
  // Utilizando o scanf para guardar um inteiro (%i) no ENDEREÇO de 'idade'
  printf("Digite sua idade: ");
  scanf("%i", &idade);

  printf("Digite seu nome: "); // Só vai capturar até o espaço
  scanf(" %s", primeiroNome); // Para char arrays NÃO usa &

  getchar();
  printf("Digite uma frase: ");
  fgets(frase, sizeof(frase), stdin); // Lê até 49 caracteres ou até ENTER

  printf("Seu nome: %s\n", primeiroNome);
  printf("Sua idade: %i\n", idade);
  printf("Frase: %s", frase);

  return 0;
}