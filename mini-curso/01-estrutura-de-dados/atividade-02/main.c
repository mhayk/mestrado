#include "lista.h"

int main(void)
{
	int quantidade, i;
	Aluno al;
	Lista *lista;
	
	printf("Informe a quantidade de alunos você deseja inserir: ");
	scanf("%d",&quantidade);
	getchar();
	
	lista = cria_lista();
	
	for(i=0; i < quantidade; i++)
	{
		printf("------------------------------\n");
		printf("Dados do aluno[%d]....\n",i);
		printf("Informe a matrícula do aluno: ");
		scanf("%d",&al.matricula);
		getchar();
		printf("Informe o nome do aluno: ");
		scanf("%s",al.nome);
		getchar();
		printf("Informe a idade do aluno: ");
		scanf("%d",&al.idade);
		getchar();
		inserir_final_lista(lista, al);
		printf("------------------------------\n\n\n");
	}
	imprime_lista(lista);
	libera_lista(lista);
	return 0;
}
