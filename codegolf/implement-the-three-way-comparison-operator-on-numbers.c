/*

In C++, there exists a a <=> b three-way comparison operator that, for numerical types, does the following:

If a < b, then return -1.
If a = b, then return 0.
If a > b, then return 1.
The Challenge
Implement the shortest full program, function, method, or custom operator such that, when given two numbers of the same type a and b,

If a < b, then return -1.
If a = b, then return 0.
If a > b, then return 1.

Notes
If you're writing in x86 assembly, this question may be of use to you.
This is code-golf, so shortest answer in bytes wins!

*/

#include <assert.h>

int
threeway(int a, int b)
{
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

int
main(void)
{
	assert(threeway(1, 2) == -1);
	assert(threeway(1, 1) == 0);
	assert(threeway(2, 1) == 1);

	return 0;
}
