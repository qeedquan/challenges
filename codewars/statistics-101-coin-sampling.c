/*

You're given a loaded coin with unknown probability p of turning up a head when flipping, and you want to know this probability!

You need to write a function sample which, given a function coin, estimates its probability of turning up head, up to an absolute error of 1% (1/100). To flip a coin, simply call the function: coin().

For simplicity, a head is represented as true *while a tail is represented as *false.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int
coin1()
{
	return 1;
}

int
coin2()
{
	return rand() & 1;
}

int
coin3()
{
	double x;

	x = drand48() * 2 * M_PI;
	return round(fabs(sin(x)));
}

double
sample(int (*coin)())
{
	long c, i, n;

	n = 1000000;
	for (c = i = 0; i < n; i++) {
		if (coin())
			c++;
	}
	return (c * 1.0) / n;
}

int
main()
{
	srand(time(NULL));
	printf("%f\n", sample(coin1));
	printf("%f\n", sample(coin2));
	printf("%f\n", sample(coin3));
	return 0;
}
