/*

The Need for Averages

Averages arise everywhere. In sports, we want to project the average number of games that a team is expected to win; in gambling, we want to project the average losses incurred playing blackjack; in business, companies want to calculate their average expected sales for the next quarter.

Molecular biology is not immune from the need for averages. Researchers need to predict the expected number of antibiotic-resistant pathogenic bacteria in a future outbreak, estimate the predicted number of locations in the genome that will match a given motif, and study the distribution of alleles throughout an evolving population. In this problem, we will begin discussing the third issue; first, we need to have a better understanding of what it means to average a random process.

Problem
For a random variable X taking integer values between 1 and n, the expected value of X is E(X) = Sum[k = 1, n] k*Pr(X=k).
The expected value offers us a way of taking the long-term average of a random variable over a large number of trials.

As a motivating example, let X be the number on a six-sided die.
Over a large number of rolls, we should expect to obtain an average of 3.5 on the die (even though it's not possible to roll a 3.5).
The formula for expected value confirms that E(X) = Sum[k = 1, 6] k * Pr(X=k) = 3.5.

More generally, a random variable for which every one of a number of equally spaced outcomes has the same probability is called a uniform random variable (in the die example, this "equal spacing" is equal to 1).
We can generalize our die example to find that if X is a uniform random variable with minimum possible value a and maximum possible value b, then E(X)=(a+b)/2.
You may also wish to verify that for the dice example, if Y is the random variable associated with the outcome of a second die roll, then E(X+Y)=7.

Given: Six nonnegative integers, each of which does not exceed 20,000. The integers correspond to the number of couples in a population possessing each genotype pairing for a given factor. In order, the six given integers represent the number of couples having the following genotypes:

AA-AA
AA-Aa
AA-aa
Aa-Aa
Aa-aa
aa-aa
Return: The expected number of offspring displaying the dominant phenotype in the next generation, under the assumption that every couple has exactly two offspring.

Sample Dataset
1 0 0 1 0 1
Sample Output
3.5

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
offspring(long x[6])
{
	static const double coeff[] = { 1, 1, 1, 0.75, 0.5, 0 };

	size_t i;
	double r;

	r = 0;
	for (i = 0; i < 6; i++)
		r += coeff[i] * x[i];
	return r * 2;
}

void
test(long x[6], double r)
{
	double v;

	v = offspring(x);
	printf("%.2f\n", v);
	assert(fabs(v - r) < 1e-1);
}

int
main()
{
	long x1[] = { 1, 0, 0, 1, 0, 1 };
	long x2[] = { 17617, 16020, 16669, 19072, 17125, 17968 };

	test(x1, 3.5);
	test(x2, 146345.0);

	return 0;
}
