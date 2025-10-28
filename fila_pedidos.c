#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int numero;
    char cliente[50];
} Pedido;

typedef struct {
    Pedido fila[MAX];
    int inicio, fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

int filaCheia(Fila *f) {
    return f->fim == MAX;
}

void enfileirar(Fila *f, int numero, char *cliente) {
    if (!filaCheia(f)) {
        f->fila[f->fim].numero = numero;
        strcpy(f->fila[f->fim].cliente, cliente);
        f->fim++;
    } else {
        printf("Fila cheia!\n");
    }
}

void desenfileirar(Fila *f) {
    if (!filaVazia(f)) {
        printf("Atendendo pedido #%d - %s\n", f->fila[f->inicio].numero, f->fila[f->inicio].cliente);
        f->inicio++;
    } else {
        printf("Fila vazia!\n");
    }
}

void mostrarFila(Fila *f) {
    printf("\nPedidos na fila:\n");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("#%d - %s\n", f->fila[i].numero, f->fila[i].cliente);
    }
}

int main() {
    Fila fila;
    inicializar(&fila);

    enfileirar(&fila, 1, "Lucas");
    enfileirar(&fila, 2, "Ana");
    enfileirar(&fila, 3, "Marcos");

    mostrarFila(&fila);
    printf("\n--- Atendendo ---\n");
    desenfileirar(&fila);
    mostrarFila(&fila);

    return 0;
}
