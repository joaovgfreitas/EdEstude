#include <stdio.h>
#include <stdlib.h>
#include "arvoreavl.h"

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 50);

    printf("\nRemovendo 20...\n");
    raiz = remover(raiz, 20);

    printf("Percurso ordenado: ");
    emOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);
    return 0;
}