#include <stdio.h>

int isDuplicate(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // O número já existe no vetor
        }
    }
    return 0; // O número é único no vetor
}

int main() {
    int size;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int vetor[size];
    printf("Digite %d números diferentes:\n", size);

    for (int i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);

        // Verifica se o número já foi digitado anteriormente
        while (isDuplicate(vetor, i, num)) {
            printf("Número já digitado. Digite outro número: ");
            scanf("%d", &num);
        }

        vetor[i] = num;
    }

    printf("Vetor preenchido:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
