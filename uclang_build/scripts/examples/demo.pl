
father(bob,dylan).
father(bob,mike).
father(bob,robert).
father(luke,bob).

brother(A,B) :-
  father(X,A),
  father(X,B),
  A \= B.

descendent(A,B) :- father(B,A).
descendent(A,B) :-
  father(B,C),
  descendent(A,C).

conc([],L,L).
conc([H|L1],L2,[H|L3]) :- conc(L1,L2,L3).

