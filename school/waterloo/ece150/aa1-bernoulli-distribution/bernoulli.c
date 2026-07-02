/*

A random 0-1 event (say, flipping a coin) is said to follow a Bernoulli distribution with probability p if the probability of a 1 is p and the probability of a 0 is 1-p where 0≤p≤1.

A fair coin would follow a Bernoulli distribution with p=1/2.

Implement a function that returns a 1 with probability p.

Use an assertion to ensure that the argument p falls in the desired interval.

The rand(), found in the cstdlib library, returns an integer between 0 and RAND_MAX, inclusive.

Now, be careful, for if p=0, then this function should always return a 0 and if p=1, then this function should always return a 1.

#include <cstdlib>
#include <cassert>

// Function declaration
int bernoulli( double p );
Class implementation
Implement a class Bernoulli_distribution where:

The constructor Bernoulli_distribution::Bernoulli_distribution( double p ); takes an argument p and creates an instance that generates random values that follow the Bernoulli distribution.
The member function int Bernoulli_distribution::operator()() const; returns a 1 with probability p and 0 with probability 1-p.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
bernoulli(double p)
{
	return drand48() <= p;
}

void
sim(long n, double p)
{
	long c[2], i;

	c[0] = c[1] = 0;
	for (i = 0; i < n; i++)
		c[bernoulli(p)]++;
	printf("%ld %f | %ld %ld\n", n, p, c[0], c[1]);
}

int
main(void)
{
	srand48(time(NULL));

	sim(10000L, .8);
	sim(100000L, .3);
	sim(1000000L, .6);

	return 0;
}
