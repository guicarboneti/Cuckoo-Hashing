#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "utils.h"

int main (void) {
    int n;
    TabHash *T1 = inicializa_tabela();
    TabHash *T2 = inicializa_tabela();
    Saida* saidas = (Saida*) malloc(M * sizeof(Saida));

    // lê e executa entrada
    executa_entrada(T1, T2);

    // Prepara a saída com os dados ordenados
    saida(saidas, T1, T2, &n);
    ordena_saida(saidas, n);
    imprime_saida(saidas, n);
    
    free(T1);
    free(T2);   
    free(saidas);
    
    return 0;
}