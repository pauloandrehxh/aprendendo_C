#include <stdio.h>
#include <string.h>

// struct Aluno {
//     char nome[50];
//     int matricula;
//     float media;
// };

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

int main() {
    // struct Aluno aluno1;
    Aluno aluno1;

    // Atribuindo valores ao aluno 1
    strcpy(aluno1.nome, "Paulo André");
    aluno1.matricula = 212312321;
    aluno1.media = 9.5;

    // Exibindo os dados armazenados
    printf("Nome: %s\n", aluno1.nome);
    printf("Matrícula: %d\n", aluno1.matricula);
    printf("Média: %.2f\n", aluno1.media);

    return 0;
}