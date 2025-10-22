#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa um nó da lista
typedef struct No {
    int dado; // valor armazenado no nó
    struct No* proximo; // ponteiro para o próximo nó
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No)); // aloca memória para o novo nó
    if (novo == NULL) { // verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória!\n"); 
        exit(1);
    }
    novo->dado = valor; // atribui o valor ao nó
    novo->proximo = NULL; // inicializa o próximo como NULL
    return novo; // retorna o novo nó criado
}

// Inserir um elemento no início da lista
void inserirInicio(No** inicio, int valor) {
    No* novo = criarNo(valor); // cria um novo nó
    novo->proximo = *inicio; // aponta o próximo do novo nó para o início atual
    *inicio = novo; // atualiza o início para o novo nó
}

// Inserir um elemento no final da lista
void inserirFim(No** inicio, int valor) {
    No* novo = criarNo(valor); // cria um novo nó

    if (*inicio == NULL) { // verifica se a lista está vazia
        *inicio = novo; // se a lista estiver vazia, o novo nó é o início
        return;
    }

    No* atual = *inicio; // ponteiro para percorrer a lista
    while (atual->proximo != NULL) { // percorre até o último nó
        atual = atual->proximo; // avança para o próximo nó
    }

    atual->proximo = novo; // insere o novo nó no final da lista
}

// Remover um elemento da lista (por valor)
void removerElemento(No** inicio, int valor) {
    if (*inicio == NULL) { // verifica se a lista está vazia
        printf("Lista vazia.\n"); // informa que a lista está vazia
        return;
    }

    No* atual = *inicio; // ponteiro para percorrer a lista
    No* anterior = NULL; // ponteiro para o nó anterior

    while (atual != NULL && atual->dado != valor) { // procura o valor na lista
        anterior = atual;  // atualiza o nó anterior
        atual = atual->proximo; // avança para o próximo nó
    }

    if (atual == NULL) { // Avisa caso o valor não tenha sido encontrado
        printf("Elemento %d não encontrado.\n", valor);
        return;
    }

    if (anterior == NULL) { 
        *inicio = atual->proximo;  // removendo o primeiro nó
    } else {
        anterior->proximo = atual->proximo; // removendo um nó do meio ou do fim
    }

    free(atual); // libera a memória do nó removido
}

// Exibir todos os elementos da lista
void exibirLista(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = inicio; // ponteiro para percorrer a lista
    printf("Lista: ");
    while (atual != NULL) { // enquanto atual não for nulo, percorrer a lista
        printf("%d ", atual->dado);
        atual = atual->proximo; // avança para o próximo nó
    }
    printf("\n");
}

// Liberar toda a memória da lista
void liberarLista(No** inicio) {
    No* atual = *inicio; // ponteiro para percorrer a lista
    No* temp; // ponteiro temporário para liberar nós
    while (atual != NULL) {
        temp = atual; // armazena o nó atual
        atual = atual->proximo; // avança para o próximo nó
        free(temp); // libera o nó armazenado
    }
    *inicio = NULL; // define o início como NULL após liberar a lista
}

#endif