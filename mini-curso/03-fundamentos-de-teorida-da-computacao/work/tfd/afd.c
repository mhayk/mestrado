#include <stdio.h>
#include <stdlib.h>
#include <string.h> //necessário para operacoes com string

#include "afd.h"


//ERRO 01
//Uso de símbolos que não fazem parte do alfabeto nas transições
void VerificaSimbolos(char verifica[]) {

	//verificar o ERRO 01
	//Uso de símbolos que não fazem parte do alfabeto nas transições;
	int v, res;
	int continua = 0;
	char carac[100];
	for (v = 0; v < qtdAlfatabeto; v++) {
		strcpy(carac, alfabeto[v]);
		res = strcmp(carac,verifica);
		if (res == 0) {
			continua = 1; //encontrou, pode continuar
			break;
		}
	}
	if (continua == 0) { //se não encontrar nenhum, sai com erro
		printf("\nErro 01 ;");
		exit(0);
	}

}


//ERRO 03
//Uso de estados que não fazem parte do conjunto de estados nas transições
void VerificaEstados(char verifica[]) {

	int v, res;
	int continua = 0;
	char carac[100];
	for (v = 0; v < qtdEstados; v++) {
		strcpy(carac, estados[v]);
		res = strcmp(carac,verifica);
		if (res == 0) {
			continua = 1; //encontrou, pode continuar
			break;
		}
	}
	if (continua == 0) { //se não encontrar nenhum, sai com erro
		printf("\nErro 03 ;");
		exit(0);
	}

}

//estado Final (B ou C)
void eFinal(char plvra[]){
	printf("\n%s sim ;", plvra);
}

//estado Erro
void eErro(char plvra[]){
	printf("\n%s não ;", plvra);
}

//verifica se a palavra, na posicao atual, tem letra para continuar a verificacao
int temLetraNessaPosicao(int pos, char plvra[]) {

	if (pos >= strlen(plvra)) {
		return 0; //false
	} else {
		return 1; //true
	}
}


void LerTransicaoEstado(int posicao, char qualPalavra[], char qualEstado[]) {

	int i;

	//o caractere faz parte, vamos continuar com a verificação
	int posProx = posicao+1; //proximo caractere
	int ret;
	ret = temLetraNessaPosicao(posicao, qualPalavra);
	//se a posição da letra for valida, continua
	if (ret==1) {

		char caractere = qualPalavra[posicao]; //caractere a ser verificado

		//ERRO 02
		//verificar se o caractere faz parte do alfabeto de palavras
		int fazParte = 0;
		for (i=0;i<qtdAlfatabeto;i++) {

			if (caractere == alfabeto[i][0]) {
				fazParte = 1;
				break;
			}
		}
		if (fazParte == 0) {
			printf("\nErro 02 ;");
			return; //sai da função
		}


		// de posse do caractere e do estado em que se encontra,
		// verificar o proximo estado nas transicoes
		char proxEstado[10];
		int resE;
		for (i=0;i<qtdTransicoes;i++) {
			resE = strcmp(posTransicaoDe[i], qualEstado);
			if (resE == 0 && posTransicaoLer[i][0] == caractere) {
				strcpy(proxEstado, posTransicaoPara[i]);
				break; //pode sair do for
			}
		}

		LerTransicaoEstado(posProx, qualPalavra, proxEstado);

	} else {

		//não havendo caractere na posição, verificamos se é um estado final
		int isFinal = 0, resF;
		for (i=0;i<qtdEstadosFinais; i++) {
			resF = strcmp(qualEstado, estadoFinal[i]);
			if (resF == 0) {
				isFinal = 1; //é um estado final
				break;
			}
		}
		//se for final, a palavra é válida
		if (isFinal == 1) {
			eFinal(qualPalavra);
		} else {
			//se não for um estado final, então acabando aqui, e a palavra é invalida no automato
			eErro(qualPalavra);
		}

	}

}

//inicio da verificacao
void Iniciar(char plvra[]) {
	//vai pro primeiro estado, e verifica a primeira posição "0"
	LerTransicaoEstado(0, plvra, estadoInicial);
}


//***********************************************************************
// PARA VERIFICAÇÃO
//***********************************************************************
void ImprimeEstados() {
	int i, cont = qtdEstados;
	for (i=0;i<=cont;i++) {
		printf("estados[%d] = '%s'\n",i,estados[i]);
	}
	printf("\n\n");
}

void ImprimeAlfabeto() {
	int i, cont = qtdAlfatabeto;
	for (i=0;i<=cont;i++) {
		printf("alfabeto[%d] = '%s'\n",i,alfabeto[i]);
	}
	printf("\n\n");
}

void ImprimeTransicoes() {
	int i,cont = qtdTransicoes;
	for (i=0;i<=cont;i++) {
		printf("posTransicaoDe[%d] = '%s'\n",i,posTransicaoDe[i]);
		printf("posTransicaoPara[%d] = '%s'\n",i,posTransicaoPara[i]);
		printf("posTransicaoLer[%d] = '%s'\n\n",i,posTransicaoLer[i]);
	}
	printf("\n\n");
}

void ImprimeEstadoInicial() {
	printf("Estado Inicial: '%s'\n", estadoInicial);
	printf("\n\n");
}

void ImprimeEstadoFinal() {
	int i,cont = qtdEstadosFinais;
	for (i=0;i<=cont;i++) {
		printf("estadoFinal[%d] = '%s'\n",i,estadoFinal[i]);
	}
	printf("\n\n");
}

void ImprimePalavras() {
	int i,cont = qtdPalavras;
	for (i=0;i<=cont;i++) {
		printf("palavra[%d] = '%s'\n",i,palavra[i]);
	}
	printf("\n\n");
}
//***********************************************************************
// PARA VERIFICAÇÃO
//***********************************************************************
int main(void)
{
	char n[2];
	int i = 0;
	char chr;
	char lido[1024] = "";


	qtdEstados = 0;
	while(1){
		scanf("%s", lido);
		if(strlen(lido) == 1 && lido[0] == ';'){
			break;
		}
		strcpy(estados[qtdEstados], lido);
		qtdEstados++;
	}


	qtdAlfatabeto = 0;
	while(1){
		scanf("%s", lido);
		if(strlen(lido) == 1 && lido[0] == ';'){
			break;
		}
		strcpy(alfabeto[qtdAlfatabeto], lido);
		qtdAlfatabeto++;
	}


	qtdTransicoes = 0;
	while(1){

		while(1){
			scanf("%s", lido);

			if(lido[0] == '#'||(strlen(lido) == 1 && lido[0] == ';')){
				break;
			}

			strcpy(posTransicaoDe[qtdTransicoes], lido); // copiamos a n-ésima palavra para a string
			scanf("%s", lido);

			strcpy(posTransicaoPara[qtdTransicoes], lido); // copiamos a n-ésima palavra para a string
			scanf("%s", lido);

			strcpy(posTransicaoLer[qtdTransicoes], lido); // copiamos a n-ésima palavra para a string

			qtdTransicoes++;
		}

		if(lido[0] == '#'){
			scanf("%s", lido);
			break;
		}
	}


    while(1){
		scanf("%s", lido);
		if(lido[0] == ';'){
			break;
		}
		strcpy(estadoInicial, lido);

	}


     qtdEstadosFinais = 0;
     while(1){
		scanf("%s", lido);
		if(lido[0] == ';'){
			break;
		}
		 strcpy(estadoFinal[qtdEstadosFinais], lido);
		qtdEstadosFinais++;
	}


	 qtdPalavras=0;
     while(1){
		scanf("%s", lido);
		if(lido[0] == ';'){
			break;
		}
		strcpy(palavra[qtdPalavras], lido);
		qtdPalavras++;
	}

	//ArrumaPalavras(lido, 0);

	int ver = 0; //0 não verifica - 1 verifica os valores inseridos
	if (ver == 1) {
		//fazendo a impressão dos valores inseridos
		ImprimeEstados();
		ImprimeAlfabeto();
		ImprimeTransicoes();
		ImprimeEstadoInicial();
		ImprimeEstadoFinal();
		ImprimePalavras();
	}
	//verificando os erros 01 e 03 nas transições
	for (i=0; i< qtdTransicoes; i++) {

		//ERRO 01
		//Verificando se os símbolos digitados não fazem parte do alfabeto nas transições
		VerificaSimbolos(posTransicaoLer[i]);

		//ERRO 03
		//Verificando os estados que não fazem parte do conjunto de estados nas transições
		VerificaEstados(posTransicaoDe[i]);
		VerificaEstados(posTransicaoPara[i]);
	}

	//nao há erro de símbolos nem de estados, vamos continuar com a verificação das palavras
	for (i=0;i< qtdPalavras; i++) {
		Iniciar(palavra[i]);
	}

	return 0;
}


