/*

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

*/

#include <assert.h>

unsigned
testit(unsigned a, unsigned b)
{
	return a | b;
}

int
main()
{
	assert(testit(0, 1) == 1);
	assert(testit(1, 2) == 3);
	assert(testit(10, 20) == 30);

	assert(testit(1, 1) == 1);
	assert(testit(1, 3) == 3);

	return 0;
}
