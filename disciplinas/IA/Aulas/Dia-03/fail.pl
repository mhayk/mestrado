% Maria gosta de todos os animais menos de cobra.
cobra(jararaca).
animal(cavalo).
gosta(maria, X) :- animal(X).
gosta(maria, X) :- cobra(X), !, fail.
