# Projeto Calculadora Modular em C

## 1. Visão Geral

Este projeto é um exemplo simples, mas fundamental, de como aplicar a **modularização** em linguagem C. O objetivo é demonstrar como organizar um programa separando a lógica de negócio (as operações da calculadora) da aplicação principal (`main`).

Essa abordagem resulta em um código mais limpo, reutilizável e de fácil manutenção, sendo uma prática essencial para o desenvolvimento de software de qualquer tamanho.

## 2. Conceitos Essenciais de Modularização

A modularização em C se baseia na separação de responsabilidades entre dois tipos de arquivos:

* **Arquivos de Cabeçalho (`.h`) - O Contrato:** Atuam como uma "interface pública" para um módulo. Eles declaram **o que** o módulo oferece (protótipos de funções, tipos de dados, etc.), mas não **como** ele o faz.
* **Arquivos de Código-Fonte (`.c`) - A Implementação:** Contêm a lógica real e o código-fonte (a definição) das funções que foram declaradas no arquivo de cabeçalho.

O processo de compilação em C lida com esses arquivos em duas etapas principais:
1.  **Compilação:** Cada arquivo `.c` é compilado individualmente em um "arquivo objeto" (`.o`), que contém o código de máquina para aquele módulo específico.
2.  **Linkedição (Linking):** O "linker" junta todos os arquivos objeto para resolver as referências entre eles (como a chamada de `somar` em `main.c` que é implementada em `calculadora.c`) e criar o programa executável final.

## 3. Estrutura de Arquivos

A estrutura do projeto está organizada da seguinte forma:

```
/projeto_calculadora/
|
|-- calculadora.h      # O arquivo de cabeçalho (interface) do módulo.
|-- calculadora.c      # O arquivo de código-fonte (implementação) do módulo.
|-- main.c             # O arquivo principal que utiliza o módulo da calculadora.
```

## 4. Descrição dos Arquivos

### 4.1. `calculadora.h`

Este é o **arquivo de cabeçalho** do nosso módulo. Ele funciona como um contrato, prometendo que as seguintes funções existem em algum lugar do projeto.

* **Guarda de Inclusão (Header Guard):** As diretivas `#ifndef CALCULADORA_H`, `#define CALCULADORA_H` e `#endif` são essenciais. Elas impedem que o conteúdo deste arquivo seja incluído mais de uma vez durante a compilação, evitando erros de "redefinição".
* **Protótipos de Funções:** Contém apenas as assinaturas das funções, especificando o nome, os tipos dos parâmetros e o tipo de retorno.

```c
#ifndef CALCULADORA_H
#define CALCULADORA_H

// Protótipo da função que soma dois inteiros.
int somar(int a, int b);

// Protótipo da função que subtrai dois inteiros.
int subtrair(int a, int b);

#endif // CALCULADORA_H
```

### 4.2. `calculadora.c`

Este é o **arquivo de implementação** do módulo. Ele fornece o código real para as funções declaradas em `calculadora.h`.

* **Inclusão do Cabeçalho:** A primeira linha, `#include "calculadora.h"`, é crucial. Ela permite que o compilador verifique se a implementação neste arquivo corresponde exatamente ao que foi prometido no cabeçalho.
* **Definição das Funções:** Aqui, o corpo de cada função é escrito, contendo a lógica para realizar a operação.

```c
#include "calculadora.h"

int somar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}
```

### 4.3. `main.c`

Este é o **ponto de entrada** do programa. Ele atua como um "cliente" ou "consumidor" do módulo `calculadora`.

* **Inclusão de Bibliotecas:** Inclui a biblioteca padrão `stdio.h` para funções de entrada/saída (como `printf`).
* **Inclusão do Módulo:** A linha `#include "calculadora.h"` informa ao compilador sobre as funções `somar` e `subtrair`, permitindo que `main` as utilize. Note que **nunca incluímos o arquivo `.c`**, apenas o `.h`.

```c
#include <stdio.h>
#include "calculadora.h"

int main() {
    int x = 10;
    int y = 5;

    int resultado_soma = somar(x, y);
    int resultado_subtracao = subtrair(x, y);

    printf("Soma: %d + %d = %d\n", x, y, resultado_soma);
    printf("Subtração: %d - %d = %d\n", x, y, resultado_subtracao);

    return 0;
}
```

## 5. Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C como o GCC. Abra um terminal na pasta do projeto e use os seguintes comandos.

### Método 1: Compilação Direta

Este é o método mais simples para projetos pequenos. Ele compila e linka todos os arquivos `.c` de uma só vez.

```sh
gcc main.c calculadora.c -o programa_calculadora
```

### Método 2: Compilação e Linkedição Separadas

Este método ilustra melhor o que acontece nos bastidores e é mais eficiente em projetos grandes, pois permite recompilar apenas os arquivos que foram modificados.

1.  **Compilar `main.c` em um arquivo objeto (`main.o`):**
    ```sh
    gcc -c main.c -o main.o
    ```

2.  **Compilar `calculadora.c` em um arquivo objeto (`calculadora.o`):**
    ```sh
    gcc -c calculadora.c -o calculadora.o
    ```

3.  **Linkar os arquivos objeto para criar o executável final:**
    ```sh
    gcc main.o calculadora.o -o programa_calculadora
    ```

### Executando o Programa

Após a compilação bem-sucedida por qualquer um dos métodos, um arquivo executável chamado `programa_calculadora` será criado. Para executá-lo:

```sh
./programa_calculadora
```

**Saída Esperada:**
```
Soma: 10 + 5 = 15
Subtração: 10 - 5 = 10
```

## 6. Conclusão

A modularização é uma técnica poderosa que promove a organização e a escalabilidade de projetos em C. Ao separar interface (`.h`) de implementação (`.c`), criamos blocos de construção de software que são independentes, testáveis e fáceis de reutilizar em diferentes partes de um sistema ou até mesmo em outros projetos.