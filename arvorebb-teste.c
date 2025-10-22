#include <stdio.h>
#include <stdlib.h>
#include "arvorebb.h"

int main() {
    No* raiz = NULL; // raiz da árvore

    // Inserindo elementos
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Percurso em ordem crescente: ");
    emOrdem(raiz);
    printf("\n");

    printf("Percurso pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Percurso pos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Removendo o valor 50\n");
    raiz = remover(raiz, 50);

    printf("Buscando o valor 40\n");
    int valorBusca = 40;
    No* encontrado = buscar(raiz, valorBusca);
    if (encontrado)
        printf("Valor %d encontrado na arvore!\n", valorBusca); 
    else
        printf("Valor %d nao encontrado.\n", valorBusca);

    liberarArvore(raiz);
    return 0;
}