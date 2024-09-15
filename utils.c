#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "utils.h"

// le arquivo de entrada e executa as operações
void executa_entrada(TabHash *T1, TabHash *T2) {
    char op;
    int k;

    while (scanf(" %c %d", &op, &k) != EOF)
        if (op == 'i')
            insere(k, T1, T2);
        else if (op == 'r')
            exclui(k, T1, T2);
        else
            printf("ERRO: Operação desconhecida: %c\n", op);
}

// armazena o resultado final das operacoes
void saida(Saida *s, TabHash *T1, TabHash *T2, int *tam_saida) {
    int i, j=0;
    for(i=0; i<M; i++) {
        if (T1[i].key != 0) {
            saidas[j].key = T1[i].key;
            strcpy(saidas[j].table, "T1");
            saidas[j].value = T1[i].value;
            j++;
        }
    }
    for(i=0; i<M; i++) {
        if (T2[i].key != 0) {
            saidas[j].key = T2[i].key;
            strcpy(saidas[j].table, "T2");
            saidas[j].value = T2[i].value;
            j++;
        }
    }
    *tam_saida = j;
}

// função de comparação usada na ordenação
int compara(const void *a, const void *b) {
    Saida *saidaA = (Saida *)a;
    Saida *saidaB = (Saida *)b;

    if (saidaA->key != saidaB->key)
        return saidaA->key - saidaB->key;

    int cmpTable = strcmp(saidaA->table, saidaB->table);
    if (cmpTable != 0)
        return cmpTable;

    return saidaA->value - saidaB->value;
}

void ordena_saida(Saida *saidas, int n) {
    qsort(saidas, n, sizeof(Saida), compara);
}

void imprime_saida(Saida saidas[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d,%s,%d\n", saidas[i].key, saidas[i].table, saidas[i].value);
}