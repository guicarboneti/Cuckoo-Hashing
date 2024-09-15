#include <stdio.h>
#include "hash.h"
#include "utils.h"

int main () {
    int i, k, n;
    inicializa_tabela(T1);
    inicializa_tabela(T2);

    // insere(8, T1, T2);
    // insere(2, T1, T2);
    // insere(13, T1, T2);
    // exclui(8, T1, T2);
    // insere(19, T1, T2);
    // exclui(2, T1, T2);
    // insere(24, T1, T2);

    executa_entrada(T1, T2);
    saida(saidas, T1, T2, &n);
    ordena_saida(saidas, n);
    imprime_saida(saidas, n);
    return 0;
}