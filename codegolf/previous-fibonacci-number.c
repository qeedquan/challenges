/*

The sequence of Fibonacci numbers is defined as follows:

F0 = 0
F1 = 1
Fn = F[n-1] + F[n-2]

Given a Fibonacci number, return the previous Fibonacci number in the sequence.
You do not need to handle the inputs 0 or 1, nor any non-Fibonacci numbers.

Errors as a result of floating point inaccuracies are permitted.

This is code-golf, so the shortest code in bytes wins.

*/

#include <assert.h>

#define SQRT5 2.23606797749978969640917366873

typedef long long vlong;

vlong
prevfib(vlong n)
{
	if (n < 1)
		return 0;
	return ((n * SQRT5) - n + 1) / 2;
}

int
main()
{
	assert(prevfib(2) == 1);
	assert(prevfib(3) == 2);
	assert(prevfib(5) == 3);
	assert(prevfib(8) == 5);
	assert(prevfib(13) == 8);
	assert(prevfib(21) == 13);
	assert(prevfib(34) == 21);
	assert(prevfib(55) == 34);
	assert(prevfib(89) == 55);
	assert(prevfib(144) == 89);

	return 0;
}
