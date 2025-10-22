#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct No {
    int dado; // valor armazenado no nó
    struct No* esquerda; // ponteiro para o filho à esquerda
    struct No* direita; // ponteiro para o filho à direita
    int altura; // altura do nó
} No;

// Função para obter a altura de um nó
int altura(No* n) {
    return (n == NULL) ? 0 : n->altura; // altura de um nó nulo é 0
}

// Função para obter o maior entre dois números
int maior(int a, int b) {
    return (a > b) ? a : b; // retorna o maior valor
}

// Cria um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No)); // aloca memória para o novo nó
    novo->dado = valor; // atribui o valor ao nó
    novo->esquerda = NULL; // inicializa o filho esquerdo como NULL
    novo->direita = NULL; // inicializa o filho direito como NULL
    novo->altura = 1; // novo nó começa com altura 1
    return novo; // retorna o novo nó criado
}

// Calcula o fator de balanceamento de um nó
int fatorBalanceamento(No* n) {
    if (n == NULL)
        return 0;
    return altura(n->esquerda) - altura(n->direita); // retorna a diferença entre alturas das subárvores esquerda e direita
}

// Rotação simples à direita
No* rotacaoDireita(No* y) {
    No* x = y->esquerda; // nó à esquerda de y
    No* T2 = x->direita; // subárvore direita de x

    // Rotaciona
    x->direita = y; // y torna-se filho direito de x
    y->esquerda = T2; // T2 torna-se filho esquerdo de y

    // Atualiza alturas
    y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1; // atualiza altura de y
    x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1; // atualiza altura de x

    return x; // retorna a nova raiz
}

// Rotação simples à esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->direita; // nó à direita de x
    No* T2 = y->esquerda; // subárvore esquerda de y

    // Rotaciona
    y->esquerda = x; // x torna-se filho esquerdo de y
    x->direita = T2; // T2 torna-se filho direito de x

    // Atualiza alturas
    x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1; // atualiza altura de x
    y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1; // atualiza altura de y

    return y; // retorna a nova raiz
}

// Função para inserir um valor e balancear a árvore
No* inserir(No* raiz, int valor) {
    // Inserção normal (como em uma árvore binária de busca)
    if (raiz == NULL)
        return criarNo(valor); // se a árvore estiver vazia, cria um novo nó

    if (valor < raiz->dado)
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere na subárvore esquerda
    else if (valor > raiz->dado)
        raiz->direita = inserir(raiz->direita, valor); // insere na subárvore direita
    else
        return raiz; // valores duplicados não são inseridos

    // Atualiza altura do nó atual
    raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita)); // atualiza a altura do nó

    // Verifica o fator de balanceamento
    int fb = fatorBalanceamento(raiz); // obtém o fator de balanceamento

    // Casos de desbalanceamento:

    // Caso 1: Esquerda-Esquerda
    if (fb > 1 && valor < raiz->esquerda->dado)
        return rotacaoDireita(raiz); // realiza rotação à direita

    // Caso 2: Direita-Direita
    if (fb < -1 && valor > raiz->direita->dado)
        return rotacaoEsquerda(raiz); // realiza rotação à esquerda

    // Caso 3: Esquerda-Direita
    if (fb > 1 && valor > raiz->esquerda->dado) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda); // realiza rotação à esquerda
        return rotacaoDireita(raiz); // depois rotação à direita
    }

    // Caso 4: Direita-Esquerda
    if (fb < -1 && valor < raiz->direita->dado) {
        raiz->direita = rotacaoDireita(raiz->direita); // realiza rotação à direita
        return rotacaoEsquerda(raiz); // depois rotação à esquerda
    }

    // Retorna a raiz (balanceada)
    return raiz;
}

// Função auxiliar para encontrar o menor nó (sucessor) de uma subárvore
No* menorNo(No* raiz) {
    No* atual = raiz;
    while (atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// Função para remover um valor da árvore AVL
No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    // 1. Remoção normal de árvore binária de busca
    if (valor < raiz->dado)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->dado)
        raiz->direita = remover(raiz->direita, valor);
    else {
        // Caso 1 e 2: nó com 0 ou 1 filho
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == NULL) {
                // sem filhos
                temp = raiz;
                raiz = NULL;
            } else {
                // um filho
                *raiz = *temp; // copia os dados do filho
            }
            free(temp);
        } else {
            // Caso 3: nó com dois filhos
            No* temp = menorNo(raiz->direita);
            raiz->dado = temp->dado;
            raiz->direita = remover(raiz->direita, temp->dado);
        }
    }

    // Se a árvore ficou vazia
    if (raiz == NULL)
        return NULL;

    // 2. Atualiza a altura
    raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita));

    // 3. Verifica o fator de balanceamento
    int fb = fatorBalanceamento(raiz);

    // 4. Casos de desbalanceamento após a remoção

    // Caso 1: Esquerda-Esquerda
    if (fb > 1 && fatorBalanceamento(raiz->esquerda) >= 0)
        return rotacaoDireita(raiz);

    // Caso 2: Esquerda-Direita
    if (fb > 1 && fatorBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Caso 3: Direita-Direita
    if (fb < -1 && fatorBalanceamento(raiz->direita) <= 0)
        return rotacaoEsquerda(raiz);

    // Caso 4: Direita-Esquerda
    if (fb < -1 && fatorBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    // Retorna o nó balanceado
    return raiz;
}


// Percurso em ordem (esquerda, raiz, direita)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda); // percorre a subárvore esquerda
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita); // percorre a subárvore direita
    }
}

// Liberar memória
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); // libera a subárvore esquerda
        liberarArvore(raiz->direita); // libera a subárvore direita
        free(raiz); // libera o nó raiz
    }
}

#endif