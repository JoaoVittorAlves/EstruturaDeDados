#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];  // Vetor para armazenar os elementos da lista
    int size;            // Número atual de elementos na lista
} SequentialList;

// Função para criar uma lista vazia
void createList(SequentialList *list) {
    list->size = 0;
}

// Função para verificar se a lista está vazia
int isEmpty(SequentialList *list) {
    return list->size == 0;
}

// Função para verificar se a lista está cheia
int isFull(SequentialList *list) {
    return list->size == MAX_SIZE;
}

// Função para obter o tamanho da lista
int getSize(SequentialList *list) {
    return list->size;
}

// Função para obter o valor do elemento em uma determinada posição
int getElement(SequentialList *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Índice inválido\n");
        return -1; // Retorna um valor de erro
    }
    return list->data[position];
}

// Função para modificar o valor do elemento em uma determinada posição
void setElement(SequentialList *list, int position, int value) {
    if (position < 0 || position >= list->size) {
        printf("Índice inválido\n");
        return;
    }
    list->data[position] = value;
}

// Função para inserir um elemento em uma determinada posição
void insertElement(SequentialList *list, int position, int value) {
    if (isFull(list)) {
        printf("A lista está cheia\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Índice inválido\n");
        return;
    }
    for (int i = list->size; i > position; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position] = value;
    list->size++;
}

// Função para retirar um elemento de uma determinada posição
void removeElement(SequentialList *list, int position) {
    if (isEmpty(list)) {
        printf("A lista está vazia\n");
        return;
    }
    if (position < 0 || position >= list->size) {
        printf("Índice inválido\n");
        return;
    }
    for (int i = position; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

// Função para imprimir a lista
void printList(SequentialList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SequentialList list;
    createList(&list);

    insertElement(&list, 0, 10);
    insertElement(&list, 1, 20);
    insertElement(&list, 2, 30);
    insertElement(&list, 1, 15); // Inserir 15 na posição 1

    printf("Lista após inserções: ");
    printList(&list);

    printf("Elemento na posição 2: %d\n", getElement(&list, 2));

    setElement(&list, 2, 25);
    printf("Lista após modificar o elemento na posição 2: ");
    printList(&list);

    removeElement(&list, 1);
    printf("Lista após remover o elemento na posição 1: ");
    printList(&list);

    printf("Tamanho da lista: %d\n", getSize(&list));
    printf("A lista está vazia? %s\n", isEmpty(&list) ? "Sim" : "Não");
    printf("A lista está cheia? %s\n", isFull(&list) ? "Sim" : "Não");

    return 0;
}

