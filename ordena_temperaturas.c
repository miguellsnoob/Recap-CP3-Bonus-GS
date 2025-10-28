#include <stdio.h>

#define MAX 7

void ordenar(float v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                float temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    float temp[MAX] = {30.2, 25.5, 28.1, 33.7, 29.4, 31.0, 27.3};

    printf("Temperaturas registradas (antes da ordenação):\n");
    for (int i = 0; i < MAX; i++)
        printf("%.1f ", temp[i]);

    return 0;
}
