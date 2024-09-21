#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hash.h"

// Inicializa a tabela hash com tamanho M e define todas as posições como vazias
TabHash *inicializa_tabela(void) {
  TabHash* hash = (TabHash*) malloc(M * sizeof(TabHash));
  if (hash == NULL) {
      printf("Error: memory allocation.\n");
      exit(1);
  }
  for (int i = 0; i < M; i++) {
    hash[i].key = 0;
    hash[i].value = 0;
    hash[i].excluida = 0;
  }
  return hash;
}

int h1(int k) {
  return k % M;
}

int h2(int k) {
  double frac_part = k * 0.9 - floor(k * 0.9);
  return (int)(M * frac_part);
}

// Busca pela chave k nas tabelas T1 e T2. Retorna o valor correspondente ou -1 se não encontrar
int busca(int k, TabHash *T1, TabHash *T2) {
  if (T1[h1(k)].key == 0 && T1[h1(k)].excluida == 0)
    return -1; // chave não existe
  if (T1[h1(k)].key == k)
    return T1[h1(k)].value;
  if (T2[h2(k)].key == k) {
    return T2[h2(k)].value;
  }
  else return -1;
}

// Insere a chave k em T1. Se houver colisão, move a chave antiga para T2 e insere a nova em T1
int insere (int k, TabHash *T1, TabHash *T2) {
  if (T1[h1(k)].key == 0 || T1[h1(k)].excluida == 1) {
    T1[h1(k)].key = k;
    T1[h1(k)].value = h1(k);
  }
  else {  // colisão (h1(ki) = h1(kj))
    int ki = T1[h1(k)].key;
    int kj = k;

    T2[h2(ki)].key = ki;  // insere ki em T2
    T2[h2(ki)].value = h2(ki);

    T1[h1(kj)].key = kj;  // insere kj em T1
    T1[h1(kj)].value = h1(kj);
  }
  return 0;
}

// Exclui a chave k das tabelas. Marca como "excluída" em T1 se necessário
int exclui (int k, TabHash *T1, TabHash *T2) {
  if (T2[h2(k)].key == k) {
    T2[h2(k)].key = 0;
    T2[h2(k)].value = 0;
  }
  else {
    T1[h1(k)].key = 0;
    T1[h1(k)].value = 0;
    T1[h1(k)].excluida = 1;
  }
  return 0;
}