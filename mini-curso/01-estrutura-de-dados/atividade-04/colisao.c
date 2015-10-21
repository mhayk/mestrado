#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5431
#define MAX_RANDOM 1000000

#define RANDOM_MIN 0
#define RANDOM_MAX 1000000

int main()
{
	int vetor[MAX_RANDOM];
	int i;
	int colidiu = 0;
	int hash;
	
	memset(&vetor,0,MAX_SIZE);
	
	for(i=0; i < 2000; i++)
	{
		hash = ((rand() % (RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN) % MAX_SIZE);
		
		if(hash == vetor[hash])
			colidiu++;
			
		vetor[hash] = hash;
	}
		
	printf("Total de colisões: %d\n",colidiu);
	return 0;
}
