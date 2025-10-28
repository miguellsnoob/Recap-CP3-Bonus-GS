#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

typedef struct {
    Livro livros[MAX];
    int qtd;
} Biblioteca;

void inicializar(Biblioteca *b) {
    b->qtd = 0;
}

void adicionarLivro(Biblioteca *b, char *titulo, char *autor, int ano) {
    if (b->qtd < MAX) {
        strcpy(b->livros[b->qtd].titulo, titulo);
        strcpy(b->livros[b->qtd].autor, autor);
        b->livros[b->qtd].ano = ano;
        b->qtd++;
    } else {
        printf("Biblioteca cheia!\n");
    }
}

void listarLivros(Biblioteca *b) {
    printf("\nLivros cadastrados:\n");
    for (int i = 0; i < b->qtd; i++) {
        printf("%d. %s (%d) - %s\n", i + 1, b->livros[i].titulo, b->livros[i].ano, b->livros[i].autor);
    }
}

void buscarLivro(Biblioteca *b, char *titulo) {
    for (int i = 0; i < b->qtd; i++) {
        if (strcmp(b->livros[i].titulo, titulo) == 0) {
            printf("\nLivro encontrado: %s (%d) - %s\n",
                   b->livros[i].titulo, b->livros[i].ano, b->livros[i].autor);
            return;
        }
    }
    printf("\nLivro não encontrado.\n");
}

int main() {
    Biblioteca b;
    inicializar(&b);

    adicionarLivro(&b, "O Hobbit", "J.R.R. Tolkien", 1937);
    adicionarLivro(&b, "1984", "George Orwell", 1949);
    adicionarLivro(&b, "Dom Casmurro", "Machado de Assis", 1899);

    listarLivros(&b);

    char busca[100];
    printf("\nDigite o título do livro a buscar: ");
    scanf(" %[^\n]", busca);
    buscarLivro(&b, busca);

    return 0;
}
