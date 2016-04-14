% Disciplina de Inteligência Artificial
% Aluno: Mhayk 
acima(X,Y) :- sobre(X,Y).
acima(X,Y) :- sobre(X,Y), acima(Y,Z).
sobre(a,b).
sobre(b,c).
sobre(c,d).
