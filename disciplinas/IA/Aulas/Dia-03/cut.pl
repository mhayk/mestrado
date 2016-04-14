% problema de loop. e utilização de cut(!).
casado(paulo,joana).
%casado(joana,joana).

casado(X,Y) :- casado(Y,X), !.

