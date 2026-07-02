/*

Define a function that will receive a logarithm function, and returns the base of that logarithm.

guessBase(ln) == e

Base is a real number (not only integers) guaranteed to be less than 1e6.

Have a fun time coding!

*/

#include <stdio.h>
#include <math.h>

double
guessbase(double (*logb)(double))
{
	double p;

	p = 1 / logb(2);
	return pow(2, p);
}

int
main()
{
	printf("%f\n", guessbase(log));
	printf("%f\n", guessbase(log2));
	printf("%f\n", guessbase(log10));
	return 0;
}
