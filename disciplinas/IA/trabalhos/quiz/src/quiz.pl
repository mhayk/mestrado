/*
Prolog Script Quiz.
Aluno: Mhayk Whandson da Silva Lima
UFAM - Universidade Federal do Amazonas
Disciplina: Inteligência Artificial.
*/

enunciado(2,'Qual é o maior estado do brasil ?', ['Rio de Janeiro','Rio Grande do Sul', 'Amazonas'], 'Amazonas').
enunciado(2,'Qual é a capital de Roraima ?', ['Boa Vista','Rio Branco', 'Manaus'],'Boa Vista').

questao(I,P,A,R) :-
        enunciado(I,P,A,R),
        write(I).
