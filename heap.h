#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

// Estrutura para representar o Heap
typedef struct {
    int *vetor;      // Vetor para armazenar os elementos do heap
    int capacidade;  // Capacidade máxima do heap
    int tamanho;     // Número atual de elementos no heap
} Heap;

// Função para criar um novo heap com uma capacidade dada
Heap* criarHeap(int capacidade) {
    Heap* heap = (Heap*)malloc(sizeof(Heap)); // Alocar memória para o heap
    if (heap == NULL) {
        return NULL; // Falha na alocação
    }
    heap->capacidade = capacidade; // Definir a capacidade do heap
    heap->tamanho = 0; // Inicializar o tamanho do heap
    heap->vetor = (int*)malloc(capacidade * sizeof(int)); // Alocar memória para o vetor do heap
    if (heap->vetor == NULL) {
        free(heap);
        return NULL; // Falha na alocação
    }
    return heap; // Retorna o novo heap
}

// Função para trocar dois elementos no vetor do heap
void trocar(int* a, int* b) {
    int temp = *a; // Armazenar temporariamente o valor de 'a'
    *a = *b; // Atribuir o valor de 'b' para 'a'
    *b = temp; // Atribuir o valor temporário para 'b'
}

// Função auxiliar para manter a propriedade do heap (heapify para cima)
void heapifyCima(Heap* heap, int index) {
    int pai = (index - 1) / 2; // Índice do pai do nó atual
    while (index > 0 && heap->vetor[pai] < heap->vetor[index]) { // Enquanto o nó atual for maior que o pai
        trocar(&heap->vetor[index], &heap->vetor[pai]); // Trocar os valores
        index = pai; // Atualizar o índice para o pai
        pai = (index - 1) / 2; 
    }
}

// Função auxiliar para manter a propriedade do heap (heapify para baixo)
void heapifyBaixo(Heap* heap, int index) {
    int indiceMaximo = index; // Inicializa o índice máximo como o índice atual
    int filhoEsquerdo = 2 * index + 1; // Índice do filho esquerdo
    int filhoDireito = 2 * index + 2; // Índice do filho direito

    if (filhoEsquerdo < heap->tamanho && heap->vetor[filhoEsquerdo] > heap->vetor[indiceMaximo]) {
        indiceMaximo = filhoEsquerdo; // Atualiza o índice máximo se o filho esquerdo for maior
    }
    if (filhoDireito < heap->tamanho && heap->vetor[filhoDireito] > heap->vetor[indiceMaximo]) {
        indiceMaximo = filhoDireito; // Atualiza o índice máximo se o filho direito for maior
    }
    if (index != indiceMaximo) {
        trocar(&heap->vetor[index], &heap->vetor[indiceMaximo]); // Troca os valores
        heapifyBaixo(heap, indiceMaximo); // Chama recursivamente para o índice máximo
    }
}

// Função para inserir um novo elemento no heap
void inserirHeap(Heap* heap, int valor) {
    if (heap == NULL || heap->tamanho >= heap->capacidade) {
        return; // Heap nulo ou cheio
    }
    heap->vetor[heap->tamanho] = valor; // Adiciona o novo valor no final do heap
    heap->tamanho++; // Incrementa o tamanho do heap
    heapifyCima(heap, heap->tamanho - 1); // Mantém a propriedade do heap
}

// Função para remover e retornar o elemento máximo (raiz) do heap
int extrairMax(Heap* heap) {
    if (heap == NULL || heap->tamanho == 0) {
        return -1; // Valor inválido para indicar erro
    }
    int max = heap->vetor[0]; // Armazena o valor máximo
    heap->vetor[0] = heap->vetor[heap->tamanho - 1]; // Move o último elemento para a raiz
    heap->tamanho--; // Decrementa o tamanho do heap
    heapifyBaixo(heap, 0); // Mantém a propriedade do heap
    return max; // Retorna o valor máximo removido
}

// Função para obter o elemento máximo sem removê-lo
int obterMax(Heap* heap) { 
    if (heap == NULL || heap->tamanho == 0) {
        return -1; // Valor inválido para indicar erro
    }
    return heap->vetor[0]; // Retorna o valor máximo
}

// Função para verificar se o heap está vazio
int estaVazio(Heap* heap) {
    return heap == NULL || heap->tamanho == 0;
}

// Função para verificar o tamanho atual do heap
int obterTamanho(Heap* heap) {
    return heap != NULL ? heap->tamanho : 0;
}

// Função para liberar a memória alocada para o heap
void liberarHeap(Heap* heap) {
    if (heap != NULL) {
        if (heap->vetor != NULL) {
            free(heap->vetor);
        }
        free(heap);
    }
}

#endif // HEAP3_H