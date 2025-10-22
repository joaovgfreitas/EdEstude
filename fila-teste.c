#include <stdio.h>
#include "fila.h" 

int main() {    
    Fila *f = criarFila(5);

    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
    exibirFila(f);

    int removido = desenfileirar(f);
    printf("Elemento removido: %d\n", removido);
    exibirFila(f);

    printf("Elemento no inicio da fila: %d\n", frente(f));

    // Removendo todos os elementos
    printf("Esvaziando a fila:\n");
    while (!filaVazia(f)) {
        printf("Removido: %d\n", desenfileirar(f));
    }
    exibirFila(f);

    // Libera memória
    destruirFila(f);

    return 0;
}
