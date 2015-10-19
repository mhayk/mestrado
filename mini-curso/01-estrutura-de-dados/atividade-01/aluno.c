#include <stdio.h>
#include <string.h>

int posicao = 0;
int quantidade = 0;

struct {
	int matricula;
	char nome[255];
	int idade;
} typedef Aluno;

Aluno alunos[100];


int inseriAluno(Aluno al)
{	
	alunos[posicao] = al;
	posicao++;
	quantidade++;
}

int formAluno(void)
{
	Aluno al;
	
	printf("Matricula do Aluno: ");
	scanf("%d",&al.matricula);
	getchar();
	printf("Nome do Aluno: ");
	scanf("%s",al.nome);
	getchar();
	printf("Idade do Aluno: ");
	scanf("%d",&al.idade);
	getchar();
	inseriAluno(al);
}

int removeAluno(int posicao)
{
	Aluno al;
	alunos[posicao] = al;
	quantidade--;
}

int imprimeAlunos(void)
{
	int i;
	for(i=0; i < quantidade; i++)
	{
		printf("-------\n");
		printf("Aluno[%d]\n",i);
		printf("Matricula: %d\n",alunos[i].matricula);
		printf("Nome: %s\n",alunos[i].nome);
		printf("Idade: %d\n",alunos[i].idade);
		printf("-------\n");
	}
}

int statusAlunos(void)
{
	printf("O sistema possui %d alunos registrados.\n",quantidade);
}


int menu(void)
{
	char opcao;
	while(1) 
	{	
	printf("Opcoes disponiveis:\n");
	printf("[i]nserir aluno!\n");
	printf("[r]emover aluno!\n");
	printf("[q]uantidade de alunos!\n");
	printf("[f]ichas impressas\n");
	printf("[s]air\n");
	printf("Digite a opçao que deseja:\n");
	scanf("%c",&opcao);

	switch(opcao) {
		case 'i':
			printf("inserir\n");
			formAluno();
			break;
		case 'r':
			printf("remover\n");
			break;
		case 'q':
			printf("quantidade\n");
			statusAlunos();
			break;
		case 'f':
			printf("fichas\n");
			imprimeAlunos();
			break;
		case 's':
			printf("Voce saiu! Obrigado.\n");
			return;
		default:
			printf("default\n");
			break;
	};
	}
	
}

int readme(void)
{	
	printf("[xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx]\n");
	printf("Este programa armazena no maximo 100 registros!\n");
	printf("[xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx]\n");
}

int main(void)
{

	Aluno mhayk;
	mhayk.matricula = 20150554;
	strcpy(mhayk.nome,"Mhayk Whandson");
	inseriAluno(mhayk);
	statusAlunos();
	imprimeAlunos();
	readme();
	menu();
	
	return 0;
}
