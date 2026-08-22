/*

A Shot in the Dark

In “Locating Restriction Sites”, we first familiarized ourselves with restriction enzymes. Recall that these enzymes are used by bacteria to cut through both strands of viral DNA, thus disarming the virus: the viral DNA locations where these cuts are made are known as restriction sites. Recall also that every restriction enzyme is preprogrammed with a reverse palindromic interval of DNA to which it will bind and cut, called a recognition sequence. These even length intervals are usually either 4 or 6 base pairs long, although longer ones do exist; rare-cutter enzymes have recognition sequences of 8 or more base pairs.

In this problem, we will ask a simple question: how does the bacterium "know" that it will probably succeed in finding a restriction site within the virus's DNA? The answer is that the short length of recognition sequences guarantees a large number of matches occurring randomly.

Intuitively, we would expect for a recognition sequence of length 6 to occur on average once every 4^6=4,096

base pairs. Note that this fact does not imply that the associated restriction enzyme will cut the viral DNA every 4,096 bp; it may find two restriction sites close together, then not find a restriction site for many thousand nucleotides.

In this problem, we will generalize the problem of finding an average number of restriction sites to take into account the GC-content of the underlying string being analyzed.

Problem

Say that you place a number of bets on your favorite sports teams.
If their chances of winning are 0.3, 0.8, and 0.6, then you should expect on average to win 0.3 + 0.8 + 0.6 = 1.7 of your bets (of course, you can never win exactly 1.7!)

More generally, if we have a collection of events A1,A2,…,An, then the expected number of events occurring is Pr(A1)+Pr(A2)+⋯+Pr(An) (consult the note following the problem for a precise explanation of this fact).
In this problem, we extend the idea of finding an expected number of events to finding the expected number of times that a given string occurs as a substring of a random string.

Given: A positive integer n (n≤1,000,000), a DNA string s of even length at most 10, and an array A of length at most 20, containing numbers between 0 and 1.

Return: An array B having the same length as A in which B[i] represents the expected number of times that s will appear as a substring of a random DNA string t of length n, where t is formed with GC-content A[i] (see “Introduction to Random Strings”)

Sample Dataset
10
AG
0.25 0.5 0.75

Sample Output
0.422 0.563 0.422


The Mathematical Details

In this problem, we are speaking of an expected number of events; how can we tie this into the definition of expected value that we already have from “Calculating Expected Offspring”?
The answer relies on a slick mathematical trick. For any event A, we can form a random variable for A, called an indicator random variable IA. For an outcome x, IA(x)=1 when x belongs to A and IA(x)=0 when x belongs to Ac.

For an indicator random variable IA(x)=1, verify that E(IA)=Pr(A).

You should also verify from our original formula for expected value that for any two random variables X and Y, E(X+Y) is equal to E(X)+E(Y).
As a result, the expected number of events A1,A2,…,Am occurring, or E(IA1+IA2+⋯+IAm), reduces to Pr(A1)+Pr(A2)+⋯+Pr(Am).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%.4f ", a[i]);
	printf("\n");
}

void
solve(int n, const char *s, double *A, size_t L, double *R)
{
	const char *p;
	double AT, GC;
	size_t i;

	AT = GC = 0;
	for (p = s; *p; p++) {
		AT += (*p == 'A') + (*p == 'T');
		GC += (*p == 'G') + (*p == 'C');
	}

	for (i = 0; i < L; i++) {
		R[i] = pow((1 - A[i]) * 0.5, AT);
		R[i] *= pow(A[i] * 0.5, GC);
		R[i] *= (n - (p - s) + 1);
	}
}

void
test(int n, const char *s, double *A, size_t L, double *R)
{
	double P[16];
	size_t i;

	solve(n, s, A, L, P);
	dump(P, L);
	for (i = 0; i < L; i++)
		assert(fabs(P[i] - R[i]) < 1e-3);
}

int
main()
{
	double A1[] = { 0.25, 0.5, 0.75 };
	double R1[] = { 0.422, 0.563, 0.422 };

	test(10, "AG", A1, nelem(A1), R1);

	return 0;
}
