#include <stdio.h>
#include <string.h>

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
	Lista *lista;
	
	char filename[255];
	char nome[255]; 

	strcpy(filename,argv[1]);
	
	fd = fopen(filename, "r");
	
	while( feof(fd) == 0)
	{
		while( fscanf(fd, "%s", nome) != EOF ) {
			
		}
	}

	fclose(fd);

	return 0;
}
