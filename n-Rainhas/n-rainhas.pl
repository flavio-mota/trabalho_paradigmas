diagonal(X, N) :- 
  maplist(plus, X, N, Z1),  
  maplist(plus, X, Z2, N), 
  is_set(Z1), is_set(Z2).
 
rainhas(N, Qs) :-
  numlist(1, N, P), %gera uma lista P de 1 até N
  findall(Q, (permutation(P, Q), diagonal(Q, P)), Qs). %faz o backtracking dos resultados das permutações de P em Q, e dO teste das diagonais  