% Disciplina de Inteligência Artificial
% Aluno: Mhayk 
% Mundo de Blocos.
% Recursão!
%  _
% |a|
% |b|
% |c|
% |d|
%  -
% Estudar Unificação, resolução e backtraking.
% árvore de prova.
% -? guitracer.
% -? trace.
% -? acima(a,d).
sobre(a,b).
sobre(b,c).
sobre(c,d).

acima(X,Y) :- sobre(X,Y).
acima(X,Z) :- sobre(X,Y), acima(Y,Z).
