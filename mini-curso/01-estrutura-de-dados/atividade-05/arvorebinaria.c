#include "arvorebinaria.h"

void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

void inserirValorNaArvore(No **pRaiz, int ValorASerInserido, char direcao, int valorDoPai)
{
	No *eleito;
	
	eleito = BuscaEmOrdem(*pRaiz, valorDoPai);

	if(eleito == NULL)
	{
		printf("\nO número [%d] não foi localizado na árvore!\n",valorDoPai);
		return;
	}
	
	No *novo;

	novo = (No *) malloc(sizeof(struct No));
	novo->numero = ValorASerInserido;
	novo->esquerda = NULL;
	novo->direita = NULL;


	if(direcao == 'E')
	{
		if(eleito->esquerda != NULL)
		{
			printf("\nJá existe elemento na posição esquerda de %d\n",valorDoPai);
			return;
		}
		eleito->esquerda = novo;
	}
	
	if(direcao == 'D')
	{
		if(eleito->direita != NULL)
		{
			printf("\nJá existe elemento na posição direita de %d\n",valorDoPai);
			return;
		}
		eleito->direita = novo;
	}
	
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
			return pRaiz;
		}
		else
			BuscaEmOrdem(pRaiz->esquerda, numero);
        
        if(pRaiz->numero == numero){
			//printf("\n%d == %d ?\n",pRaiz->numero, numero);
			return pRaiz;
		}
		else
			BuscaEmOrdem(pRaiz->direita, numero);   
    }
}
