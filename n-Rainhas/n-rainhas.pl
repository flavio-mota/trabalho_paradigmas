/* 8 rainhas */

perm([X|Y],Z) :- perm(Y,W), tira(X,Z,W).   
perm([],[]).

tira(X,[X|R],R).
tira(X,[F|R],[F|S]) :- tira(X,R,S).

solucao(P) :-
     perm([1,2,3,4,5,6,7,8],P), 
     aloca([1,2,3,4,5,6,7,8],P,S,D),
     salvo(S),
     salvo(D).

aloca([X1|X],[Y1|Y],[S1|S],[D1|D]) :-
     S1 is X1 +Y1,
     D1 is X1 - Y1,
     aloca(X,Y,S,D).
aloca([],[],[],[]).

salvo([X|Y]) :-  \+member(X,Y), salvo(Y).
salvo([X]).

/*setof(P,solucao(P),Set), length(Set,L).*/