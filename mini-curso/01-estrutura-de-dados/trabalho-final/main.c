#include <stdio.h>

#include "lista.h"

int hash (const char* word)
{
	int hash = 0;
	int n,i;
	int size = strlen(word);
	for (i = 0; word[i] != '\0'; i++)
	{
		if(isalpha(word[i]))
			n = word [i] - 'a' + 1;

		else
			n = 27;

		hash = ((hash << 3) + n);
	}
	return hash;
}

int main(int argc, char *argv[])
{
	int i =0;
	FILE *fd;
	ListaHash *lista;
	Palavra *word;
	Palavra waux;
	int line = 0;
	
	char filename[255];
	char nome[255]; 
	int indice;
	char ch;

	strcpy(filename,argv[1]);
	
	fd = fopen(filename, "r");

	lista = HASH_cria_lista();

	while( fscanf(fd, "%s", nome) != EOF ) {

		indice = hash(nome);
		//printf("%s -> %d\n",nome,indice);
		if(!HASH_pesquisar_lista(lista, indice, line))
		{
			//printf("Não encontrei o indice %d\n",indice);
			waux.indice = indice;
			strcpy(waux.word, nome);
			HASH_inserir_final_lista(lista, waux, line);

		}
		ch = fgetc(fd);
		if (ch == '\n')
			line++;

	}

	fclose(fd);

	print_all(lista);

	return 0;
}
