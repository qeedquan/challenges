/*

No Story

No Description

Only by Thinking and Testing

Look at the result of testcase, guess the code!

*/

#include <assert.h>

unsigned
digsum(unsigned n)
{
	unsigned r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

unsigned
testit(unsigned a, unsigned b)
{
	return digsum(a) * digsum(b);
}

int
main()
{
	assert(testit(0, 1) == 0);
	assert(testit(34, 54) == 63);
	return 0;
}
