// Arvore de Busca Binária (ABB) em C
#ifndef ARVOREBB_H
#define ARVOREBB_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa um nó da árvore
typedef struct No {
    int dado; // valor armazenado no nó
    struct No* esquerda; // ponteiro para o filho esquerdo
    struct No* direita; // ponteiro para o filho direito
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No)); // aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n"); // imprime um erro se a alocação falhar
        exit(1);
    }
    novo->dado = valor; // atribui o valor ao nó
    novo->esquerda = NULL; // inicializa o filho esquerdo como NULL
    novo->direita = NULL; // inicializa o filho direito como NULL
    return novo; // retorna o novo nó criado
}

// Inserir um elemento na árvore (mantendo a propriedade da ABB)
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor); // se a árvore estiver vazia, cria um novo nó e o retorna
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere na subárvore esquerda
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor); // insere na subárvore direita
    }

    return raiz; // retorna a raiz (sem modificá-la)
}

// Função auxiliar para encontrar o menor valor de uma subárvore
No* encontrarMinimo(No* raiz) {
    while (raiz != NULL && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Função para remover um valor da árvore
No* remover(No* raiz, int valor) {
    if (raiz == NULL) // verifica se a árvore está vazia
        return NULL;

    if (valor < raiz->dado) {
        // valor está na subárvore esquerda
        raiz->esquerda = remover(raiz->esquerda, valor);
    } 
    else if (valor > raiz->dado) {
        // valor está na subárvore direita
        raiz->direita = remover(raiz->direita, valor);
    } 
    else {
        // valor encontrado — casos de remoção
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            // Caso 1: nó folha
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerda == NULL) {
            // Caso 2: só tem filho direito
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            // Caso 2: só tem filho esquerdo
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        else {
            // Caso 3: dois filhos
            No* sucessor = encontrarMinimo(raiz->direita);
            raiz->dado = sucessor->dado;
            raiz->direita = remover(raiz->direita, sucessor->dado);
        }
    }

    return raiz;
}


// Buscar um valor na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz; // retorna o nó se encontrado ou NULL se não encontrado
    }

    if (valor < raiz->dado) 
        return buscar(raiz->esquerda, valor); // busca na subárvore esquerda
    else
        return buscar(raiz->direita, valor); // busca na subárvore direita
}



// Percurso em-ordem (esquerda, raiz, direita)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda); // percorre a subárvore esquerda
        printf("%d ", raiz->dado); // visita o nó raiz
        emOrdem(raiz->direita); // percorre a subárvore direita
    }
}

// Percurso pré-ordem (raiz, esquerda, direita)
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado); // visita o nó raiz
        preOrdem(raiz->esquerda); // percorre a subárvore esquerda
        preOrdem(raiz->direita); // percorre a subárvore direita
    }
}

// Percurso pós-ordem (esquerda, direita, raiz)
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda); // percorre a subárvore esquerda
        posOrdem(raiz->direita); // percorre a subárvore direita
        printf("%d ", raiz->dado); // visita o nó raiz
    }
}

// Liberar memória da árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); // libera a subárvore esquerda
        liberarArvore(raiz->direita); // libera a subárvore direita
        free(raiz); // libera o nó raiz
    }
}

#endif // ARVORE_H