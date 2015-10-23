#include "arvorebinaria.h"

void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

void inserirDireitaDe(No **pRaiz, int numero, int Novonumero)
{
	No *eleito = NULL;
	
	eleito = BuscaEmOrdem(*pRaiz, Novonumero);
	
	if(eleito == NULL)
	{
		printf("O número [%d] não foi localizado na árvore!\n",Novonumero);
		return;
	}
	
	inserir(&(*pRaiz)->direita, Novonumero);
}

void inserirEsqueraDe(No **pRaiz, int numero, int Novonumero)
{
	No *eleito;
	
	eleito = BuscaEmOrdem(*pRaiz, numero);
	
	if(eleito == NULL)
	{
		printf("\nO número [%d] não foi localizado na árvore!\n",numero);
		printf("%d\n",eleito->numero);
		return;
	}
	
	inserir(&(*pRaiz)->esquerda, Novonumero);
		
}

void inserir(No **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }else{
        if(numero < (*pRaiz)->numero)
            inserir(&(*pRaiz)->esquerda, numero);
        if(numero > (*pRaiz)->numero)
            inserir(&(*pRaiz)->direita, numero);
    }
}

void exibirEmOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf("\n%i", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
}

void exibirPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("\n%i", pRaiz->numero);
        exibirPreOrdem(pRaiz->esquerda);
        exibirPreOrdem(pRaiz->direita);
    }
}

void exibirPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->numero);
    }
}

No* BuscaEmOrdem(No *pRaiz, int numero)
{
	if(pRaiz != NULL){
		if(pRaiz->numero == numero){
			//printf("\n%d == %d ?\n",pRaiz->numero, numero);
			return &pRaiz->esquerda;
		}
		else
			BuscaEmOrdem(pRaiz->esquerda, numero);
        
        if(pRaiz->numero == numero){
			//printf("\n%d == %d ?\n",pRaiz->numero, numero);
			return &pRaiz->direita;
		}
		else
			BuscaEmOrdem(pRaiz->direita, numero);   
    }
}
