// Arquivo de teste para a pilha
#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha *p = criarPilha(5); // 5 é a capacidade da pilha (quantidade de itens)

    empilhar(p, 10);    
    empilhar(p, 20);    
    empilhar(p, 30);

    printf("Topo atual da pilha: %d\n", top(p)); //Verifica qual o topo atual da pilha
    exibirPilha(p); // Exibe todos os elementos da pilha

    printf("\nRemovendo: %d", desempilhar(p));
    printf("\nRemovendo: %d", desempilhar(p));

    printf("\nTopo final da pilha, apos remocao: %d", top(p));

    destruirPilha(p);
    return 0;
}