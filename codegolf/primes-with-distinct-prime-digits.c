/*

There are 18 primes with distinct prime digits (A124674). Namely, they are:

2,3,5,7,23,37,53,73,257,523,2357,2753,3257,3527,5237,5273,7253,7523

Your task is to output this sequence.

Rules
sequence rules apply. This means valid solutions may use any of the following formats:

Given some index n it can return the n-th entry of the list.
Given some index n it can return all entries up to the nth one in the sequence.
Without taking any index, it can output all entries by e.g. ...
...printing them one by one (potentially infinitely) or...
...returning a list (lazy if the sequence is infinite) or...
...returning a generator that represents the whole sequence.
Note: the solution may print/generate infinitely, but once the entire sequence is output, subsequent outputs must be blank.
If taken, you may assume the input n is always valid. (with 0-based indexing, 0≤n≤17; with 1-based indexing, 1≤n≤18)

This is code-golf; fewest bytes wins.

Standard loopholes apply.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A124674
unsigned
pdpd(unsigned n)
{
	static const unsigned tab[] = {2, 3, 5, 7, 23, 37, 53, 73, 257, 523, 2357, 2753, 3257, 3527, 5237, 5273, 7253, 7523};

	return (n < nelem(tab)) ? tab[n] : 0;
}

int
main(void)
{
	static const unsigned tab[] = {2, 3, 5, 7, 23, 37, 53, 73, 257, 523, 2357, 2753, 3257, 3527, 5237, 5273, 7253, 7523};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(pdpd(i) == tab[i]);

	return 0;
}
