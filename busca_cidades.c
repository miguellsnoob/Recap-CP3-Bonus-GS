#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int buscaLinear(char cidades[][50], int n, char *alvo) {
    char alvoLower[50];
    strcpy(alvoLower, alvo);
    toLowerCase(alvoLower);

    for (int i = 0; i < n; i++) {
        char cidadeLower[50];
        strcpy(cidadeLower, cidades[i]);
        toLowerCase(cidadeLower);

        if (strcmp(cidadeLower, alvoLower) == 0)
            return i;
    }
    return -1;
}

void ordenar(char cidades[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(cidades[j], cidades[j + 1]) > 0) {
                strcpy(temp, cidades[j]);
                strcpy(cidades[j], cidades[j + 1]);
                strcpy(cidades[j + 1], temp);
            }
        }
    }
}

int buscaBinaria(char cidades[][50], int n, char *alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(cidades[meio], alvo);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    char cidades[MAX][50] = {"Curitiba", "Fortaleza", "Manaus", "Salvador", "Campinas",
                             "Recife", "Natal", "Uberlandia", "Bauru", "Londrina"};
    char busca[50];
    int n = 10;

    printf("Digite o nome da cidade: ");
    scanf("%49s", busca);

    int idx = buscaLinear(cidades, n, busca);
    if (idx != -1)
        printf("Busca linear: %s encontrada na posição %d.\n", cidades[idx], idx);
    else
        printf("Busca linear: cidade não encontrada.\n");

    ordenar(cidades, n);

    printf("\nCidades ordenadas:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", cidades[i]);

    idx = buscaBinaria(cidades, n, busca);
    if (idx != -1)
        printf("\nBusca binária: %s encontrada na posição %d.\n", cidades[idx], idx);
    else
        printf("\nBusca binária: cidade não encontrada.\n");

    return 0;
}
