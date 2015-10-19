#ifndef __LISTA__
#define __LISTA__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	int matricula;
	char nome[255];
	int idade;
} typedef Aluno;

struct no{
    Aluno al;
    struct no *prox;

};

typedef struct no *Lista;

void inicializa_lista(Lista *l);
int lista_vazia(Lista l);
int insere_elemento(Lista *l, Aluno al);
int remove_elemento(Lista *l, Aluno al);


#endif 
