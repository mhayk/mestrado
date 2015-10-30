#include "lista.h"

ListaHash* HASH_cria_lista(void)
{
	ListaHash *lista = (ListaHash *) malloc(sizeof(ListaHash));
	if(lista != NULL)
		*lista = NULL;
	else
		printf("Não foi possível criar a lista!\n");
		
	return lista;
}

void HASH_inserir_final_lista(ListaHash *lista, Palavra al, int linha)
{
		if(lista == NULL)
			printf("[error] Primeiro crie a lista\n");
			
		ElementoHash *no = (ElementoHash *) malloc(sizeof(ElementoHash));
		
		if(no == NULL)
		{
			printf("[error] Não foi possível alocar memória para o novo elemento!\n");
			return;
		}
		
		no->word = al;
		no->prox = NULL;
		
		if( (*lista) == NULL )
			*lista = no;
		else
		{
			ElementoHash *aux = *lista;
			while(aux->prox != NULL)
				aux = aux->prox;
				
			aux->prox = no;
		}
		//printf("Nó inserido com sucesso\n");				

		ElementoLinha *lno = (ElementoLinha *) malloc(sizeof(ElementoLinha));

		lno->line = linha;
		lno->amount = 1;
		lno->prox = NULL;

		no->lprox = lno;
		//printf("Nó da lista da palavra %s inserido com sucesso!\n",no->word.word);
}

void LINHA_inserir_final_lista(ListaLinha *lista, int linha, int amount)
{

	if (lista == NULL)
	{
	}

	ElementoLinha *no;
	no = (ElementoLinha *) malloc(sizeof(ElementoLinha));

	no->line = linha;
	no->amount = amount;
	no->prox = NULL;

	if( (*lista) == NULL)
		*lista = no;
	else
	{
		ElementoLinha *aux = *lista;
		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = no;
	}
	//printf("Sub-nó inserido com sucesso\n");
}

/*void imprime_lista(Lista *lista)
{
		int i=0;
		if(lista == NULL)
			printf("[error] Primeiro crie a lista\n");
		
		Elemento *aux = *lista;	
		
		printf("-----------------------------------------\n");
		printf("        Relatório de Alunos!             \n");
		printf("-----------------------------------------\n");
		do
		{
			printf("Dados do aluno[%d]....\n",i);
			printf("A matrícula do aluno: %d\n",aux->aluno.matricula);
			printf("Nome do aluno: %s\n",aux->aluno.nome);
			printf("Idade aluno: %d\n",aux->aluno.idade);
			i++;
			aux = aux->prox;
		} while(aux->prox != NULL);
		printf("Dados do aluno[%d]....\n",i);
		printf("A matrícula do aluno: %d\n",aux->aluno.matricula);
		printf("Nome do aluno: %s\n",aux->aluno.nome);
		printf("Idade aluno: %d\n",aux->aluno.idade);
		printf("-----------------------------------------\n");
}*/

void HASH_libera_lista(ListaHash *lista)
{
	if(lista != NULL) {
		ElementoHash *no;
		
		while( (*lista) != NULL) {
			no = *lista;
			*lista = (*lista)->prox;;
			free(no);
		}
		free(lista);
	}
}

int HASH_pesquisar_lista(ListaHash *lista, int indice, int linha)
{
	if( lista == NULL)
		return 0;

	ElementoHash *no = *lista;
	
	while( no != NULL && no->word.indice != indice)
	{
		no = no->prox;
	}

	if( no == NULL)
		return 0;
	else{
		/* Índice já existe na lista! */
		//printf("Indice já existe na lista! : %d\n",no->word.indice);
		//*el = &no->word;
		if(!LINHA_pesquisar_lista(&no->lprox, linha))
		{
			//printf("I\n");
			LINHA_inserir_final_lista(&no->lprox, linha, 1);
		}
		else
			return 1;
	}
}

int LINHA_pesquisar_lista(ListaLinha *lista, int line)
{
	if( lista == NULL)
		return 0;

	ElementoLinha *no = *lista;

	while( no != NULL && no->line != line)
		no = no->prox;

	if( no == NULL)
	{
		return 0;
	}
	else {
		/* Incrementa a quantidade referente a palavra que já encontra-se inserido. */
		//printf("!!=====!! [%d] JÁ EXISTE ! INCREMENTANDO AMOUNT++!!!-> \n",no->line);
		no->amount++;
	}

}

void print_all(ListaHash *lista)
{
	ElementoHash *no = *lista;
	ElementoLinha *lno;

	while( no != NULL )
	{
		printf("%s: ",no->word.word);
		lno = no->lprox;
		while ( lno != NULL)
		{
			printf("(%d,%d) ",lno->line, lno->amount);
			lno = lno->prox;
		}
		printf("\n");
		no = no->prox;
	}
}
