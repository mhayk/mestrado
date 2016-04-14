homem(mhayk).
homem(jadson).
mulher(alana).
mulher(érica).
casado(jadson,érica).
casado(mhayk,alana).

casal(X,Y) :- homem(X), mulher(Y).
