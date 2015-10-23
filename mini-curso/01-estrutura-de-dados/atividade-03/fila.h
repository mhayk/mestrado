#ifndef __FILA__
#define __FILA__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0;

struct {
	int matricula;
	char nome[255];
	int idade;
} typedef Aluno;

typedef struct elemento {
	Aluno al;
	struct elemento *lig;
}tipo_elemento;

typedef struct {
	tipo_elemento *inicio;
	tipo_elemento *fim;
} fila;

void definir(fila *q);
int vazia(fila *q);
int inserir(fila *q, Aluno al); 
int remover(fila *q, Aluno al);
void imprimir(fila *q);

#endif
