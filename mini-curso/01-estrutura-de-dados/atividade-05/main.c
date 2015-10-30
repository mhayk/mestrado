#include "arvorebinaria.h"

int main(void)
{
	No *raiz;
	criarArvore(&raiz);
	inserir(&raiz, 4);
	inserir(&raiz, 1);
	inserir(&raiz, 8);
	inserir(&raiz, 15);
	exibirEmOrdem(raiz);
	inserirValorNaArvore(&raiz, 2, 'D', 8);
	printf("\n......\n");
	exibirEmOrdem(raiz);
	return 0;
}
