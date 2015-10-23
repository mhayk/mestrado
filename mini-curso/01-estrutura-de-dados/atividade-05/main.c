#include "arvorebinaria.h"

int main(void)
{
	No *raiz;
	criarArvore(&raiz);
	inserir(&raiz, 4);
	inserir(&raiz, 6);
	inserir(&raiz, 8);
	inserir(&raiz, 15);
	exibirEmOrdem(raiz);
	inserirEsqueraDe(&raiz, 15, 20);
	printf("......\n");
	exibirEmOrdem(raiz);
	return 0;
}
