# Aula 01
Variáveis - Especificadores de formato - Pegando dados do usuário
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

## Problema do buffer no scanf
>Sempre que for ler um caractere (`%c`) após ter lido qualquer outra coisa com scanf (especialmente números), coloque um espaço antes do `%c` na string de formato para "limpar" qualquer Enter (\n) que tenha sobrado no buffer. 
### Código defeituoso
```c
#include <stdio.h>

int main() {
    int numero;
    char caractere;

    printf("Digite um número: ");
    scanf("%d", &numero); // O problema começa aqui

    printf("Digite um caractere: ");
    scanf("%c", &caractere); // Este scanf parece ser "pulado"

    printf("Número digitado: %d\n", numero);
    printf("Caractere digitado: '%c'\n", caractere);

    return 0;
}
```
### Como o problema acontece ?

- O programa executa `scanf("%d", &numero);` e para, esperando você digitar.

- Você digita o número 42 e, para confirmar, pressiona a tecla Enter.

>**_O que vai para a fila (o buffer)?_** Não vai apenas o 42. Vão os caracteres '4', '2' e, crucialmente, o caractere que representa a tecla Enter, que é chamado de "nova linha" ou \n.

- **Fila (Buffer):** `['4', '2', '\n']`

- O `scanf("%d", ...)` (o operador de caixa para números) entra em ação. Ele é instruído a pegar apenas números.

- Ele pega o '4'. É um número. Ótimo.

- Ele pega o '2'. É um número. Ótimo.

- Ele encontra o `\n`. **Isso não é um número!** O scanf para de ler aqui, processa '4' e '2' para formar o inteiro 42 e o armazena na variável numero.

> O que SOBROU na fila? O scanf foi embora, mas ele deixou para trás o cliente que ele não quis atender: o \n.

- **Fila (Buffer):** `['\n']`

- O programa continua e executa `scanf("%c", &caractere);`.

- O `scanf("%c", ...)` (o operador de caixa para UM caractere) entra em ação. Ele é super simples: sua única instrução é **"pegue o primeiro cliente que estiver na fila, seja ele quem for"**.

- Ele vai até a fila e quem ele encontra? O `\n` que foi deixado para trás! Ele pega o `\n`, armazena na variável caractere e considera seu trabalho concluído.

>Resultado: O programa nunca para para você digitar o caractere. **_Ele simplesmente pega o Enter que sobrou da leitura anterior_**. Por isso, quando ele imprime o caractere, muitas vezes aparece apenas uma linha em branco.

### A Solução: O Espaço Mágico antes do %c
Agora, vamos entender por que `scanf(" %c", &caractere);` conserta tudo.

Um espaço na string de formato do scanf é uma instrução especial. Ele não significa "leia um espaço". Ele significa:

>"Leia e descarte todos os caracteres de espaço em branco (whitespaces) que encontrar no início da fila. Continue descartando até encontrar o primeiro caractere que NÃO seja um espaço em branco."

**_Caracteres de "espaço em branco" incluem o espaço comum, a tecla Tab (\t) e, mais importante, a nova linha `(\n)`._**

---

### 💡 Dicas importantes:

- Sempre use `&` no scanf para variáveis simples (endereço de memória).

- Para float, no scanf use `%f`; para double, `%lf`.

- Para formatar casas decimais, use `%.nf` (ex.: `%.2f` → 2 casas).

- `%s` lê até o primeiro espaço; para ler frases, é necessário outra abordagem (`fgets`, por exemplo).