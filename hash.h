#ifndef _HASH_H
#define _HASH_H
#define M 11

typedef struct TabHash {
    int key;
    int value;
    int excluida;
} TabHash;

TabHash *inicializa_tabela(void);

// função hash , onde k é a chave inteira
int h1(int k);
int h2(int k);

int busca(int k, TabHash *T1, TabHash *T2);

int insere (int k, TabHash *T1, TabHash *T2);

int exclui (int k, TabHash *T1, TabHash *T2);

#endif