/*

Have you heard about the myth that if you fold a paper enough times, you can reach the moon with it? Sure you have, but exactly how many? Maybe it's time to write a program to figure it out.

You know that a piece of paper has a thickness of 0.0001m. Given distance in units of meters, calculate how many times you have to fold the paper to make the paper reach this distance.
(If you're not familiar with the concept of folding a paper: Each fold doubles its total thickness.)

Note: Of course you can't do half a fold. You should know what this means ;P

Also, if somebody is giving you a negative distance, it's clearly bogus and you should yell at them by returning null (or whatever equivalent in your language). In Shell please return None. In C and COBOL please return -1.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

r = 0.0001
r*2^x = n
x = log2(n/r)

*/

long
folds(double n)
{
	if (n < 0)
		return -1;
	return ceil(log2(n / 0.0001));
}

int
main()
{
	assert(folds(3.84 * 1e8) == 42);
	return 0;
}
