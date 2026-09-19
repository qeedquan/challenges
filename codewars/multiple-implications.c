/*

In logic, an implication (or material conditional) states that

If p is true, q should be true too.

We can express the result of any implication of two statements as a logical table:

  q T F
p
T   T F
F   T T
In this kata, we will take that further.

Given an array, assume that from first to last item in the array, each implies the next (for example, in an array of three items p, q, and r: (p -> q) -> r). Return the boolean answer.
If the array is empty, return None, null or a similar empty value.

There will be no more than 8 variables in the array, and the array will contain only boolean values.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

enum {
	F = 0,
	T = 1,
};

int
implies(int x, int y)
{
	int lut[2][2] = {
	    {T, T},
	    {F, T},
	};

	return lut[!!x][!!y];
}

int
eval(int *a, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return F;

	r = a[0];
	for (i = 1; i < n; i++)
		r = implies(r, a[i]);
	return r;
}

int
main()
{
	int a1[] = {F};
	int a2[] = {T};
	int a3[] = {F, F};
	int a4[] = {F, T};
	int a5[] = {T, F};
	int a6[] = {T, T};
	int a7[] = {F, F, F};
	int a8[] = {F, F, T};
	int a9[] = {F, T, F};
	int a10[] = {F, T, T};
	int a11[] = {T, F, F};
	int a12[] = {T, F, T};
	int a13[] = {T, T, F};
	int a14[] = {T, T, T};

	assert(eval(NULL, 0) == false);
	assert(eval(a1, nelem(a1)) == false);
	assert(eval(a2, nelem(a2)) == true);
	assert(eval(a3, nelem(a3)) == true);
	assert(eval(a4, nelem(a4)) == true);
	assert(eval(a5, nelem(a5)) == false);
	assert(eval(a6, nelem(a6)) == true);
	assert(eval(a7, nelem(a7)) == false);
	assert(eval(a8, nelem(a8)) == true);
	assert(eval(a9, nelem(a9)) == false);
	assert(eval(a10, nelem(a10)) == true);
	assert(eval(a11, nelem(a11)) == true);
	assert(eval(a12, nelem(a12)) == true);
	assert(eval(a13, nelem(a13)) == false);
	assert(eval(a14, nelem(a14)) == true);

	return 0;
}
