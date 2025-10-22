#include <stdio.h>
#include <stdlib.h>
#include "listae.h"

int main() {
    No* lista = NULL; // lista inicialmente vazia

    inserirInicio(&lista, 10);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    inserirInicio(&lista, 5);

    exibirLista(lista);

    removerElemento(&lista, 20);
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}