#ifndef __LISTA__
#define __LISTA__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lista_linha {
	int line;
	int amount;
	struct lista_linha *prox;
};

typedef struct lista_linha *ListaLinha;
typedef struct lista_linha ElementoLinha;

struct stpalavra {
	int indice;
	char word[255];
};
typedef struct stpalavra Palavra;

struct lista_hash {
	Palavra word;
	struct lista_linha *lprox;
    struct lista_hash *prox;
};

typedef struct lista_hash *ListaHash;
typedef struct lista_hash ElementoHash;

ListaHash* HASH_cria_lista();
void HASH_inserir_final_lista(ListaHash *lista, Palavra word, int linha);
void HASH_imprime_lista(ListaHash *lista);
void HASH_libera_lista(ListaHash *lista);
int HASH_pesquisar_lista(ListaHash *lista, int indice, int linha);

void print_all(ListaHash *lista);

ListaLinha* LINHA_cria_lista();
int LINHA_pesquisar_lista(ListaLinha *lista, int line);
void LINHA_inserir_final_lista(ListaLinha *lista, int linha, int amount);


#endif 
