#ifndef __ARVORE_BINARIA_
#define __ARVORE_BINARIA_

#include <stdio.h>
#include <stdlib.h>

struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

void criarArvore(No **pRaiz);
void inserirold(No **pRaiz, int numero);
void inserirDireitaDe(No **pRaiz, int numero, int Novonumero);
void inserirEsqueraDe(No **pRaiz, int numero, int Novonumero);
void exibirEmOrdem(No *pRaiz);
void exibirPreOrdem(No *pRaiz);
void exibirPosOrdem(No *pRaiz);

No* BuscaEmOrdem(No *pRaiz, int numero);

#endif
