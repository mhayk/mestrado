#include "lista.h"

Lista* cria_lista(void)
{
	Lista *lista = (Lista *) malloc(sizeof(Lista));
	if(lista != NULL)
		*lista = NULL;
	else
		printf("Não foi possível criar a lista!\n");
		
	return lista;
}

void inserir_final_lista(Lista *lista, Aluno al)
{
		if(lista == NULL)
			printf("[error] Primeiro crie a lista\n");
			
		Elemento *no = (Elemento *) malloc(sizeof(Elemento));
		
		if(no == NULL)
		{
			printf("[error] Não foi possível alocar memória para o novo elemento!\n");
			return;
		}
		
		no->aluno = al;
		no->prox = NULL;
		
		if( (*lista) == NULL )
			*lista = no;
		else
		{
			Elemento *aux = *lista;
			
			while(aux->prox != NULL)
				aux = aux->prox;
				
			aux->prox = no;
		}
		printf("Nó inserido com sucesso\n");				
}

void imprime_lista(Lista *lista)
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
}

void libera_lista(Lista *lista)
{
	if(lista != NULL) {
		Elemento *no;
		
		while( (*lista) != NULL) {
			no = *lista;
			*lista = (*lista)->prox;;
			free(no);
		}
		free(lista);
	}
}
