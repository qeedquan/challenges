/*

This code-challenge is based on OEIS sequence A261865.

A261865(n) is the least integer  k such that some multiple of sqrt(k) is in the interval  (n, n+1).

The goal of this challenge is to write a program that can find a value of n that makes  A261865(n) as large as you can.
A brute-force program can probably do okay, but there are other methods that you might use to do even better.

Example
For example, A261865(3)=3 because

there is no multiple of sqrt(1) in (3,4) (since 3*sqrt(1) and 4*sqrt(1)≥4);
there is no multiple of sqrt(2) in (3,4) (since 2*sqrt(2)≤3 and 3*sqrt(2)≥4);
and there is a multiple of sqrt(3) in (3,4), namely 2*sqrt(3)≈3.464.

Analysis
Large values in this sequence are rare!

70.7% of the values are 2s,
16.9% of the values are 3s,
5.5% of the values are 5s,
2.8% of the values are 6s,
1.5% of the values are 7s,
0.8% of the values are 10s, and
1.7% of the values are ≥11.

Challenge
The goal of this code-challenge is to write a program that finds a value of n that makes A261865(n) as large as possible.
Your program should run for no more than one minute and should output a number n.
Your score is given by  A261865(n).
In the case of a close call, I will run all entries on my 2017 MacBook Pro with 8GB of RAM to determine the winner.

For example, you program might output A261865(257240414)=227 for a score of 227.
If two entries get the same score, whichever does it faster on my machine is the winner.

(Your program should not rely on information about pre-computed values, unless you can justify that information with a heuristic or a proof.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

double
sqr(double x)
{
	return x * x;
}

// https://oeis.org/A261865
vlong
seq(vlong n)
{
	double a, b;
	vlong k;

	if (n < 1)
		return 0;

	for (k = 2; k < LLONG_MAX; k++) {
		a = sqr(n + 1) / k;
		b = sqr(n) / k;
		a = sqrt(a);
		b = sqrt(b);
		if (ceil(a) - floor(b) >= 2)
			return k;
	}
	return -1;
}

int
main()
{
	static const vlong tab[] = {
		2, 2, 3, 2, 2, 3, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 3, 2, 2, 3, 2, 2, 7,
		2, 2, 2, 3, 2, 2, 15, 2, 2, 2, 3, 2, 2, 7, 2, 2, 5, 2, 2, 2, 5, 2, 2,
		7, 2, 2, 2, 3, 2, 2, 13, 2, 2, 2, 3, 2, 2, 6, 2, 2, 3, 2, 2, 2, 6, 2,
		2, 3, 2, 2, 2, 6, 2, 2, 5, 2, 2, 3, 2, 2, 2, 6, 2
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i + 1) == tab[i]);

	return 0;
}
