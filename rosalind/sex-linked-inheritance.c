/*

Chromosomes Determine Sex

In “Independent Segregation of Chromosomes”, we discussed how chromosomes in diploid organisms form pairs of homologs.
It turns out that this is not the case for one pair of chromosomes in animals.
In 1905, Nettie Stevens and Edmund Wilson independently discovered that male animals possess one chromosome that is shorter than its partner, whereas female animals instead have two long chromosomes.
The shorter chromosome earned the title of Y chromosome for its stunted shape, whereas the longer chromosome became known as the X chromosome.
These two chromosomes are aptly termed sex chromosomes, or allosomes, and we write the female sex chromosome genotype as XX and the male genotype as XY.
The remaining homologous chromosome pairs are called autosomes.

Sex chromosomes are still passed on to gametes based on the outcome of a coin flip, but egg cells (deriving from females) must always possess an X chromosome, so that the sex of an individual is determined by whether it receives an X or a Y chromosome from its father's sperm cell.

Fast-forward five years to 1910 and the lab of Thomas Hunt Morgan, who is often considered the first modern geneticist because of his tireless work to place Mendel's work on sound footing.
One of Morgan's many experiments with fruit flies (genus Drosophila) began as he noticed a number of white-eyed males.
When these white-eyed flies were crossed with purebred red-eyed females, their progeny were all red-eyed, and yet crossing the second generation's red-eyed individuals with each other produced some white-eyed males but exclusively red-eyed females. Strange results indeed.

Morgan's experiments are summarized in Figure 1, after which he concluded that the trait for eye color in fruit flies must be sex linked, or encoded on a sex chromosome.
More specifically, the factor for white eye color is encoded by a recessive allele on the X chromosome.
Because a male only has one copy of the X chromosome, having only one recessive allele will cause the individual to exhibit white eyes, whereas a female fly requires both copies of the recessive allele to possess white eyes.

X-linked recessive traits are manifested in males much more often than in females, because a male only needs to receive a recessive allele from his mother to exhibit the trait: in the case of genetic conditions, half of all male children born to carrier mothers will inherit the condition.

Problem
The conditional probability of an event A given another event B, written Pr(A∣B), is equal to Pr(A and B) divided by Pr(B).

Note that if A and B are independent, then Pr(A and B) must be equal to Pr(A)×Pr(B), which results in Pr(A∣B)=Pr(A).
This equation offers an intuitive view of independence: the probability of A, given the occurrence of event B, is simply the probability of A (which does not depend on B).

In the context of sex-linked traits, genetic equilibrium requires that the alleles for a gene k are uniformly distributed over the males and females of a population. In other words, the distribution of alleles is independent of sex.

Given: An array A of length n for which A[k] represents the proportion of males in a population exhibiting the k-th of n total recessive X-linked genes.
Assume that the population is in genetic equilibrium for all n genes.

Return: An array B of length n in which B[k] equals the probability that a randomly selected female will be a carrier for the k-th gene.

Sample Dataset
0.1 0.5 0.8
Sample Output
0.18 0.5 0.32

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
show(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%.3f ", a[i]);
	printf("\n");
}

void
sexlink(double *a, size_t n, double *r)
{
	size_t i;

	for (i = 0; i < n; i++)
		r[i] = 2 * a[i] * (1 - a[i]);
}

void
test(double *a, size_t n, double *r)
{
	double p[32];
	size_t i;

	sexlink(a, n, p);
	show(p, n);
	for (i = 0; i < n; i++)
		assert(fabs(p[i] - r[i]) < 1e-2);
}

int
main()
{
	double a1[] = { 0.1, 0.5, 0.8 };
	double r1[] = { 0.18, 0.5, 0.32 };

	test(a1, nelem(a1), r1);
	return 0;
}
