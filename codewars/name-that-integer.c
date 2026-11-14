/*

Ruby
Write a method detect_int that returns the first positive integer for which an arbitrary number of lambdas returns true. If no arguments are passed in, then detect_int should return 1.

For example:

lam1 = x => x > 9
lam2 = x => x**0.5 % 1 == 0

detect_int()             // => 1
detect_int(lam1)         // => 10
detect_int(lam2)         // => 1
detect_int(lam1,lam2)    // => 16

The testing rubric will never ask for a number that does not exist, like:

detect_int(n=>n%2==1, n=>n%2==0)      // => !??

For examples, see the example test cases.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef bool (*fn)(int);

bool
f1(int x)
{
	return x > 9;
}

bool
f2(int x)
{
	return fmod(sqrt(x), 1) == 0;
}

int
detectint(fn f[], size_t n)
{
	int i;
	size_t j;

	if (n == 0)
		return 1;

loop:
	for (i = 1; i < INT_MAX; i++) {
		for (j = 0; j < n; j++) {
			if (!f[j](i))
				continue loop;
		}
		return i;
	}
	return -1;
}

int
main()
{
	fn lam1[] = { f1 };
	fn lam2[] = { f2 };
	fn lam3[] = { f1, f2 };

	assert(detectint(NULL, 0) == 1);
	assert(detectint(lam1, nelem(lam1)) == 10);
	assert(detectint(lam2, nelem(lam2)) == 1);
	assert(detectint(lam3, nelem(lam3)) == 16);

	return 0;
}
