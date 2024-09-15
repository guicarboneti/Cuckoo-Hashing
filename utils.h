#ifndef _UTILS_H
#define _UTILS_H
#include "hash.h"

typedef struct {
    int key;
    char table[3];
    int value;
} Saida;

Saida saidas[M];

void executa_entrada(TabHash *T1, TabHash *T2);

void saida(Saida *saidas, TabHash *T1, TabHash *T2, int *tam_saida);

void ordena_saida(Saida *saidas, int n);

void imprime_saida(Saida saidas[], int n);

#endif