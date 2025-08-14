# Aprendendo C
Repositório para aprender C e suas sintaxes: variáveis, especificadores de formato 
## Especificadores de Formato
Especificadores de formato dizem ao C como ler ou mostrar os dados de uma variável — usados principalmente em:

- `printf` → para exibir valores

- `scanf` → para ler valores

| Tipo           | Especificador                       | Exemplo de uso (`printf`) |
| -------------- | ----------------------------------- | ------------------------- |
| *int*          | `%d` ou `%i`                        | `printf("%d", idade);`   |
| *float*        | `%f`                                | `printf("%f", altura);`   |
| *double*       | `%lf`                               | `printf("%lf", valor);`   |
| *char*         | `%c`                                | `printf("%c", letra);`    |
| *string*       | `%s`                                | `printf("%s", nome);`     |
| *(ponteiro)*   | `%p`                                | `printf("%p", &nome);`    |
| *unsigned int* | `%u`                                | `printf("%u", numero);`   |
> Ponteiro é utilizado para guardar o endereço de memória de uma variável.

## Pegando dados do usuário
Para pegar dados do usuário, utiliza o `scanf()`, que lê valores do teclado e armazena nas variáveis.
Porém o scanf não armazena textos com espaços, ele vai pegar só a parte antes do espaço, para pegar textos completos, utiliza-se o `fgets()`.

### Exemplo:
```c
#include <stdio.h>

int main() {
    int idade;
    float altura;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f m\n", altura);
    return 0;
}
```
> O `&` é necessário porque o scanf precisa do endereço da variável.

### Exemplo lendo string sem espaço:

```c
char nome[20];

printf("Digite seu nome: ");
scanf("%s", nome); // para char arrays NÃO usa &
```

### Exemplo lendo string com espaço:
Pegando frases inteiras (com espaços), utlizando `fgets()`

```c
char frase[50];

printf("Digite uma frase: ");
fgets(frase, sizeof(frase), stdin); // lê até 49 caracteres ou até ENTER
```
> **_Observação_**: por que a função fgets só conseguiria armazenar até 49 caracteres na variável frase, sendo que foi alocado um espaço de 50 quando foi declarado a variável?

> **_Resposta_**: Em C, uma string não é só os caracteres visíveis — ela é um array de char finalizado com um caractere especial `\0` (NULL), que indica onde a string termina.
O `\0` não aparece quando é imprimido, mas é essencial para que funções como printf("%s", ...) saibam onde parar.


---


### 💡 Dicas importantes:

- Sempre use `&` no scanf para variáveis simples (endereço de memória).

- Para float, no scanf use `%f`; para double, `%lf`.

- Para formatar casas decimais, use `%.nf` (ex.: `%.2f` → 2 casas).

- `%s` lê até o primeiro espaço; para ler frases, é necessário outra abordagem (`fgets`, por exemplo).