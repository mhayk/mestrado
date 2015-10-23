#include "fila.h"

void definir(fila *q)
{
	/*
	 * 
	 */
	q->inicio = NULL;
	q->fim = NULL;
}

int vazia(fila *q)
{

	/* Retorna true se a fila não contém elementos, false caso contrário */
	return (q->inicio == NULL);
}

int inserir(fila *q, Aluno al)
{
	/* Adiciona um item no fim da fila q. Retorna true se operação realizada com sucesso, false contrário. */
	tipo_elemento *p;
	
	p = (tipo_elemento *) malloc(sizeof(tipo_elemento));
	if ( p == NULL )
		return false;
		
	p->al = al;
	p->lig = NULL;
	
	if (vazia(q))
		q->inicio = p;
	else
		q->fim->lig = p;
	
	q->fim = p;	
	return true;
}

int remover(fila *q, Aluno al)
{
	/* Remover um item do início da fila q. Returna true se operação realizada com sucesso, false caso contrário. */
	
	tipo_elemento *p;
	
	if (vazia(q))
		return false;
		
	p = q->inicio;
	al = p->al;
	q->inicio = p->lig;
	
	if (q->inicio == NULL)
		q->fim = NULL;
		
	free(p);
	return true;
}

void imprimir(fila *q)
{
	tipo_elemento *p;
	
	if(!vazia(q)) {
	p = q->inicio;
		while(p != NULL)
		{
			printf("Matricula: %d\n",p->al.matricula);
			printf("Nome: %s\n",p->al.nome);
			printf("Idade: %d\n",p->al.idade);
			p = p->lig;
		}
	}
}
