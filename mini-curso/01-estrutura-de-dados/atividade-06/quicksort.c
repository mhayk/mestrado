#include <stdio.h>

void quickSort(int *vetor, int inicio, int fim);

int main(void){

	int vetor[100] = {32, 545, 7676, 121, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5, 7, 9, 4, 3, 6, 1, 18, 2, 10, 5};

	int i;   
	printf("Vetor desordenado:\n");
	for(i = 0; i < 100; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");   

	quickSort(vetor, 0, 99);

	printf("Vetor ordenado:\n");
	for(i = 0; i < 100; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");   

	return 0;
}

void quickSort(int *vetor, int inicio, int fim){

	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int) (j + (i - j) / 2);
	
	pivo = vetor[meio];

	do {
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	} while(j > i);

	if(inicio < j) {
		quickSort(vetor, inicio, j);
	}
	if(i < fim) {
		quickSort(vetor, i, fim);   
	}

}
