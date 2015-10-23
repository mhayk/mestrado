#include "fila.h"

int main(void)
{
	fila q;
	
	definir(&q);
	
	Aluno mhayk,alana,alice;
	mhayk.matricula = 1234;
	strcpy(mhayk.nome,"Mhayk");
	mhayk.idade = 28;
	alana.matricula = 4321;
	strcpy(alana.nome,"Alana");
	alana.idade = 26;
	alice.matricula = 6453;
	strcpy(alice.nome,"Alice");
	alice.idade = 1;
	inserir(&q, mhayk);
	inserir(&q, alana);
	inserir(&q, alice);
	imprimir(&q);
	return 0;
}
