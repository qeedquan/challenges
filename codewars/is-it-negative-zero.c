/*

There exist two zeroes: +0 (or just 0) and -0.

Write a function that returns true if the input number is -0 and false otherwise (True and False for Python).

In JavaScript / TypeScript / Coffeescript the input will be a number.

In Python / Java / C / NASM / Haskell / the input will be a float.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

bool
negzero(double x)
{
	return signbit(x) != 0;
}

int
main()
{
	assert(negzero(+0.0) == false);
	assert(negzero(0.0) == false);
	assert(negzero(-0.0) == true);
	return 0;
}
