#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char comandos[MAX][50];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char *comando) {
    if (!pilhaCheia(p)) {
        p->topo++;
        strcpy(p->comandos[p->topo], comando);
    } else {
        printf("Histórico cheio!\n");
    }
}

void desfazer(Pilha *p) {
    if (!pilhaVazia(p)) {
        printf("Desfazendo comando: %s\n", p->comandos[p->topo]);
        p->topo--;
    } else {
        printf("Nada a desfazer.\n");
    }
}

void mostrarHistorico(Pilha *p) {
    printf("\nHistórico de comandos:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d. %s\n", i + 1, p->comandos[i]);
    }
}

int main() {
    Pilha historico;
    inicializar(&historico);

    empilhar(&historico, "Inserir texto");
    empilhar(&historico, "Apagar palavra");
    empilhar(&historico, "Colar parágrafo");


    return 0;
}
