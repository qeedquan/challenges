/*

To model the Hardy-Weinberg principle, assume that we have a population of N diploid individuals.
If an allele is in genetic equilibrium, then because mating is random, we may view the 2*N chromosomes as receiving their alleles uniformly.
In other words, if there are m dominant alleles, then the probability of a selected chromosome exhibiting the dominant allele is simply p=m/(2*N).

Because the first assumption of genetic equilibrium states that the population is so large as to be ignored, we will assume that N is infinite, so that we only need to concern ourselves with the value of p.

Given: An array A for which A[k] represents the proportion of homozygous recessive individuals for the k-th Mendelian factor in a diploid population. Assume that the population is in genetic equilibrium for all factors.

Return: An array B having the same length as A in which B[k] represents the probability that a randomly selected individual carries at least one copy of the recessive allele for the k-th factor.

Sample Dataset
0.1 0.25 0.5

Sample Output
0.532 0.75 0.914

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

Let x = proportion homozygous recessive, y = proportion heterozygous.
We want the proportion of the population carrying at least one recessive gene, so the answer is x + y.

Assume that the allele frequency is stable, meaning that it remains the same after mating.
We're given the proportion of recessive individuals, so setup an equation for the proportion of recessive indiviudals.
Observe that the only way we get the recessive trait is mating between recessives and/or heterozygous.

Use the total law of probability, noting that the unlist terms are zero:
Proportion Recessive = P(Recessive|2 Rec Mate)*P(2 Rec Mate) + P(Recessive|1 Rec 1 Het Mate)*P(1 Rec 1 Het Mate) + P(Recessive|2 Het Mate)*P(2 Het Mate)
In terms of variables:  x = (1)*(x^2) + (0.5)(2*x*y) + (0.25)*(y^2)
                        x = x^2 + xy + 0.25y^2

Use the quadratic formula to solve for y: y = -2x +/- 2*sqrt(x)  ==> y = 2*sqrt(x) - 2x since y must be positive. (note x in [0,1] ==> y in [0,1])

Subsititute into the solution formula: x + y = x +(2*sqrt(x)-2x) = 2*sqrt(x) - x

Thus, the solution is 2*sqrt(x) - x

*/

void
solve(double *A, size_t n, double *B)
{
	size_t i;

	for (i = 0; i < n; i++)
		B[i] = (2 * sqrt(A[i])) - A[i];
}

void
test(double *A, size_t n, double *R)
{
	double B[32];
	size_t i;

	solve(A, n, B);

	for (i = 0; i < n; i++)
		printf("%.3f ", B[i]);
	printf("\n");

	for (i = 0; i < n; i++)
		assert(fabs(B[i] - R[i]) < 1e-3);
}

int
main()
{
	double A1[] = { 0.1, 0.25, 0.5 };
	double R1[] = { 0.532, 0.75, 0.914 };

	test(A1, nelem(A1), R1);

	return 0;
}
