#include <stdio.h>

#include "lista.h"

int hash (const char* word)
{
	int hash = 0;
	int n,i;
	int size = strlen(word);
	for (i = 0; word[i] != '\0'; i++)
	{
		// alphabet case
		if(isalpha(word[i]))
			n = word [i] - 'a' + 1;

		// comma case
		else
			n = 27;

		//hash = ((hash << 3) + n) % size;
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
	int line = -1;
	
	char filename[255];
	char nome[255]; 
	int indice;
	char ch;

	strcpy(filename,argv[1]);
	
	fd = fopen(filename, "r");

	lista = HASH_cria_lista();
	
	while( feof(fd) == 0)
	{
		while( fscanf(fd, "%s", nome) != EOF ) {

			ch = fgetc(fd);
			if (ch == '\n')
				line++;

			indice = hash(nome);
			//printf("%s -> %d\n",nome,indice);
			if(!HASH_pesquisar_lista(lista, indice, line))
			{
				//printf("Não encontrei o indice %d\n",indice);
				waux.indice = indice;
				strcpy(waux.word, nome);
				HASH_inserir_final_lista(lista, waux, line);

			}
			else
			{
					/*Se já existir na lista ... */
					/*
					printf("Já encontrei o índice %d -> %s\n",word->indice,word->word);
					if(word->prox == NULL)
					{
						printf("Na lista LINE não possui nenhum elemento ainda!\n");
						if(!LINHA_pesquisa_listA(listaLinha, linha))
						{
							LINHA_inserir_final_lista(listaLinha);
						}
						else
						{
							// Ao pesquisa quando ele já encontra.. ele já incrementa a quantidade. 
						}
					}
					*/
			}

		}
	}

	fclose(fd);

	print_all(lista);
	//printf("Total de linhas: %d\n",line);

	return 0;
}
