#include <stdio.h>
#include "heap.h"

int main() {    
    Heap* heap = criarHeap(10);
    if (heap == NULL) {
        printf("Falha ao criar o heap!\n");
        return 1;
    }

    printf("Heap esta vazio? %s\n", estaVazio(heap) ? "Sim" : "Nao");
    printf("Tamanho inicial do heap: %d\n", obterTamanho(heap));

    printf("Inserindo elementos: 10, 20, 15, 30, 25\n");
    inserirHeap(heap, 10);
    inserirHeap(heap, 20);
    inserirHeap(heap, 15);
    inserirHeap(heap, 30);
    inserirHeap(heap, 25);
    printf("Tamanho apos insercoes: %d\n", obterTamanho(heap));
    
    int max = obterMax(heap);
    printf("Elemento maximo: %d\n", max);

    printf("Extraindo elementos maximos:\n");
    while (!estaVazio(heap)) {
        int elemento = extrairMax(heap);
        if (elemento != -1) {
            printf("Elemento extraido: %d\n", elemento);
        }
    }

    printf("Tamanho apos extracoes: %d\n", obterTamanho(heap));
    printf("Heap esta vazio? %s\n", estaVazio(heap) ? "Sim" : "Nao");

    printf("Inserindo elemento 50 apos extracoes\n");
    inserirHeap(heap, 50);
    printf("Elemento maximo apos nova insercao: %d\n", obterMax(heap));
    printf("Tamanho do heap: %d\n", obterTamanho(heap));

    liberarHeap(heap);
    printf("Heap liberado.\n");

    return 0;
}