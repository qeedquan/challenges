/*

The "schoolgirls problem" posed and answered by Kirkman in 1850 is: "Fifteen young ladies in a school walk out three abreast for seven days in succession: it is required to arrange them daily so that no two shall walk twice abreast."

Also in 1850, Sylvester asked whether it is possible for the girls to walk every day for a term of 13 weeks, such that every two girls walk together exactly once each week and every three girls walk together exactly once in the term.

Sylvester's question was answered in the affirmative by Denniston in 1973, with the aid of a (targeted) computer search.

Your task is to output a solution to Sylvester's problem.

It is apparently not known whether the solution is unique up to the obvious symmetries. One million meaningless bonus points if you give a solution that is demonstrably not isomorphic to Denniston's or prove uniqueness.

See wikipedia for more

Task
In other words, your task is to output in any reasonable form a 4-dimensional array x of shape (13,7,5,3) that satisfies:

Each element x[i,j,k,l] belongs to a fixed set S of 15 fixed values. (E.g. 0,1,...,14, but any values are allowed).
For each i,j and each value a in S, x[i,j,:,:] contains a.
For each i and each pair of distinct values a,b in S, there exist j,k such that x[i,j,k,:] contains a and b.
For each triple of distinct values a,b,c in S, there exist i,j,k such that x[i,j,k,:] contains a, b and c.
(Above, x[i,j,:,:] means the set of all elements x[i,j,k,l] where i and j are given but k and l are allowed to vary arbitrarily, etc.)

Brute force searches that could never finish in practice are acceptable, but practical solutions may be more interesting.

This is code-golf, so shortest answer in each language wins.

*/

#include <stdio.h>

// https://en.wikipedia.org/wiki/Kirkman%27s_schoolgirl_problem
void
solve()
{
	puts("Day 1 ABJ CEM FKL HIN DGO");
	puts("Day 2 ACH DEI FGM JLN BKO");
	puts("Day 3 ADL BHM GIK CFN EJO");
	puts("Day 4 AEG BIL CJK DMN FHO");
	puts("Day 5 AFI BCD GHJ EKN LMO");
	puts("Day 6 AKM DFJ EHL BGN CIO");
	puts("Day 7 BEF CGL DHK IJM ANO");
}

int
main()
{
	solve();
	return 0;
}
