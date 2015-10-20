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

struct elemento {
    Aluno aluno;
    struct elemento *prox;

};

typedef struct elemento *Lista;
typedef struct elemento Elemento;

Lista* cria_lista();
void inserir_final_lista(Lista *lista, Aluno al);
void imprime_lista(Lista *lista);
void libera_lista(Lista *lista);


#endif 
