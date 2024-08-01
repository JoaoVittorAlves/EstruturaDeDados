#include <stdio.h>

// Função para realizar o insertion sort
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        // Move os elementos do array[0..i-1] que são maiores que a chave
        // uma posição à frente de sua posição atual
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6};
    /*retirar o sizeof*/
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array original: \n");
    printArray(array, size);

    insertionSort(array, size);

    printf("Array ordenado: \n");
    printArray(array, size);

    return 0;
}
