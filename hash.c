#include <stdlib.h>
#include <math.h>
#include "hash.h"

void inicializa_tabela(TabHash *T) {
  for (int i = 0; i < M; i++) {
    T[i].key = 0;
    T[i].value = 0;
    T[i].excluida = 0;
  }
}

int h1(int k) {
  return k % M;
}

int h2(int k) {
  return floor(M * (k * 0.9 - floor(k*0.9)));
}

// retorna o valor correspondente à chave k
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
}