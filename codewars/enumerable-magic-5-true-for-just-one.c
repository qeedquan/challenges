/*

Task
Create a function called one that accepts two params:

a sequence
a function
and returns true only if the function in the params returns true for exactly one (1) item in the sequence.

Example
one([1, 3, 5, 6, 99, 1, 3], bigger_than_ten) -> true
one([1, 3, 5, 6, 99, 88, 3], bigger_than_ten) -> false
one([1, 3, 5, 6, 5, 1, 3], bigger_than_ten) -> false
If you need help, here is a resource ( in Ruby ).

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
ten(int n)
{
	return n > 10;
}

bool
one(int *a, size_t n, bool (*f)(int))
{
	size_t c, i;

	for (c = i = 0; i < n && c < 2; i++) {
		if (f(a[i]))
			c++;
	}
	return c == 1;
}

int
main()
{
	int a1[] = {1, 3, 5, 6, 99, 1, 3};
	int a2[] = {1, 3, 5, 6, 99, 88, 3};
	int a3[] = {1, 3, 5, 6, 5, 1, 3};

	assert(one(a1, nelem(a1), ten) == true);
	assert(one(a2, nelem(a2), ten) == false);
	assert(one(a3, nelem(a3), ten) == false);

	return 0;
}
