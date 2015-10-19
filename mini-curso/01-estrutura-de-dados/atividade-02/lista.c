#include "lista.h"

void inicializa_lista(Lista *l)

{
    *l = NULL;
}

int lista_vazia(Lista l)

{
    if(l == NULL)
        return 1;

    return 0;
}

int insere_elemento(Lista *l, Aluno al)
{
    Lista inserindo, anterior;

    inserindo = (Lista) malloc(sizeof(struct no));
    if (inserindo == NULL)
        return 0;

    inserindo->al = al;
    
    while (anterior->prox != NULL )
        anterior = anterior->prox;

    inserindo->prox = anterior->prox;
    anterior->prox = inserindo;
    return 1;
}

int remove_elemento(Lista *l, Aluno al)
{
    Lista anterior, remover;

    if(lista_vazia(*l))
        return 0;


    while(anterior->prox != NULL && strcmp((anterior->prox)->al->matricula, al.matricula) < 0)
        anterior = anterior->prox;

    if(anterior->prox == NULL || strcmp((anterior->prox)->al->matricula, al.matricula) < 0)
        return 0;

    remover = anterior->prox;
    anterior->prox = remover->prox;
    free(remover);
    return 1;
}
