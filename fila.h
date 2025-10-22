#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma fila
typedef struct {
    int *dados;       // vetor que armazena os elementos
    int inicio;       // índice do primeiro elemento da fila
    int fim;          // índice do último elemento da fila
    int tamanho;      // quantidade atual de elementos
    int capacidade;   // tamanho máximo da fila
} Fila;

// Função para criar uma fila
Fila* criarFila(int capacidade) {
    Fila *f = (Fila*) malloc(sizeof(Fila));        // aloca memória para a fila
    f->dados = (int*) malloc(capacidade * sizeof(int)); // aloca vetor
    f->inicio = 0;     // início da fila
    f->fim = -1;       // fim começa em -1 (vazia)
    f->tamanho = 0;    // fila começa vazia
    f->capacidade = capacidade; // define a capacidade máxima
    return f;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return (f->tamanho == 0); // retorna 1 se vazia, 0 caso contrário
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return (f->tamanho == f->capacidade); // retorna 1 se cheia, 0 caso contrário
}

// Enfileira um elemento no final da fila
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: fila cheia!\n");
        return;
    }

    // movimenta o índice do fim de forma circular
    f->fim = (f->fim + 1) % f->capacidade; // atualiza o índice do fim
    f->dados[f->fim] = valor; // insere o novo elemento
    f->tamanho++; // incrementa o tamanho da fila
}

// Desenfileira (remove) o elemento do início da fila
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: fila vazia!\n");
        return -1;
    }

    int valor = f->dados[f->inicio]; // obtém o elemento do início
    f->inicio = (f->inicio + 1) % f->capacidade; // atualiza o índice do início de forma circular
    f->tamanho--; // decrementa o tamanho da fila
    return valor; // retorna o elemento removido
}

// Retorna o elemento do início da fila sem removê-lo
int frente(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: fila vazia!\n");
        return -1;
    }
    return f->dados[f->inicio]; // retorna o elemento do início
}

// Exibe os elementos da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int indice = (f->inicio + i) % f->capacidade;
        printf("%d ", f->dados[indice]);
    }
    printf("\n");
}

// Libera a memória da fila
void destruirFila(Fila *f) {
    free(f->dados);
    free(f);
}

#endif
