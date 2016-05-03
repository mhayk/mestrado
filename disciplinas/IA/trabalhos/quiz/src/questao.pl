enunciado(1,'Qual é o maior estado do brasil ?', ['Rio de Janeiro','Rio Grande do Sul', 'Amazonas'], 'Amazonas').
enunciado(2,'Qual é a capital de Roraima ?', ['Boa Vista','Rio Branco', 'Manaus'], 'Boa Vista').
enunciado(3,'Qual é o nome da minha filha ?', ['Alice','Alana', 'Ana'], 'Alice').

questao(I) :-
        enunciado(I,P,A,R),!,
	write(P),
	nl,
	write(A),
	nl,
	write(R).

resposta(I,X) :-
	enunciado(I,_,_,X),
	write(X).
		
