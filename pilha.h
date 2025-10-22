// Para evitar conflitos de dupla inclusão, é necessário incluir o ifdef no começo do programa e o endif no final
#ifndef PILHA_H
#define PILHA_H

// Conteúdo do arquivo pilha.h
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha
typedef struct {
    int *dados;      // vetor que armazena os elementos
    int topo;        // índice do topo da pilha
    int capacidade;  // tamanho máximo da pilha
} Pilha;

// Função para criar uma pilha
Pilha* criarPilha(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha)); // aloca memória para a estrutura da pilha
    p->dados = (int*) malloc(capacidade * sizeof(int)); // aloca memória para os dados da pilha
    p->topo = -1; // inicializa o topo como -1, indicando que a pilha está vazia
    p->capacidade = capacidade; // define a capacidade da pilha
    return p; 
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1; // retorna 1 (true) se estiver vazia, 0 (false) caso contrário
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *p) {
    return p->topo == p->capacidade - 1; // retorna 1 (true) se estiver cheia, 0 (false) caso contrário
}

// Insere um elemento no topo da pilha
void empilhar(Pilha *p, int valor) { 
    if (estaCheia(p)) { // verifica se a pilha está cheia
        printf("Erro: pilha cheia!\n"); // se estiver cheia, imprime uma mensagem de erro
        return;
    }
    p->dados[++p->topo] = valor; // incrementa o topo e insere o valor
}

// Remove e retorna o elemento do topo
int desempilhar(Pilha *p) {
    if (estaVazia(p)) { // verifica se a pilha está vazia
        printf("Erro: pilha vazia!\n"); // se estiver vazia, imprime uma mensagem de erro
        return -1;
    }
    return p->dados[p->topo--]; // retorna o valor do topo e decrementa o topo
}

// Retorna o elemento do topo (sem remover)
int top(Pilha *p) {
    if (estaVazia(p)) { // verifica se a pilha está vazia
        printf("Erro: pilha vazia!\n"); // se estiver vazia, imprime uma mensagem de erro
        return -1;
    }
    return p->dados[p->topo]; // retorna o valor do topo
}

// Exibe todos os elementos da pilha
void exibirPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Exibindo elementos da pilha: \n");
    for (int i = p->topo; i >= 0; i--) { // percorre do topo até a base
        printf("%d ", p->dados[i]); // imprime o valor do elemento
    }
}


// Libera a memória alocada
void destruirPilha(Pilha *p) { 
    free(p->dados); 
    free(p); 
}

#endif