#ifndef _AFD_H_
#define _AFD_H_

//variaveis globais
//const int TAM_BUFFER = 1000; // quantidade de caracteres a serem lidos no buffer de cada vez
//char linha[][1000]; //cada linha do arquivo, no maximo 1000 caracteres cada linha

// X estados com maximo de 10 caracteres ( A B C D ) ou (Azul Bege Cinza Dourado)
char estados[100][10];
int qtdEstados = 0;
char alfabeto[100][10];
int qtdAlfatabeto = 0;

// posição transicao => ex: transicao[0] = "A B 0"
char posTransicaoDe[100][10];
char posTransicaoPara[100][10];
char posTransicaoLer[100][10];
int qtdTransicoes = 0;

// 1 caracter ( ex: A )
char estadoInicial[10];

// X estados com 1 carcater ( B C )
char estadoFinal[100][10];
int qtdEstadosFinais = 0;

//cada palavra a ser verificada, com no maximo 100 caracteres
char palavra[100][100];
int qtdPalavras;

void VerificaSimbolos(char verifica[]);
void VerificaEstados(char verifica[]);
void eFinal(char plvra[]);
void eErro(char plvra[]);
int temLetraNessaPosicao(int pos, char plvra[]);
void LerTransicaoEstado(int posicao, char qualPalavra[], char qualEstado[]);
void Iniciar(char plvra[]);
void ImprimeEstados();
void ImprimeAlfabeto();
void ImprimeTransicoes();
void ImprimeEstadoInicial();
void ImprimeEstadoFinal();
void ImprimePalavras();

#endif
