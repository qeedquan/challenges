/*

Now we will confect a reagent. There are eight materials to choose from, numbered 1,2,..., 8 respectively.

We know the rules of confect:

material1 and material2 cannot be selected at the same time
material3 and material4 cannot be selected at the same time
material5 and material6 must be selected at the same time
material7 or  material8 must be selected(at least one, or both)
Task
You are given a integer array formula. Array contains only digits 1-8 that represents material 1-8. Your task is to determine if the formula is valid. Returns true if it's valid, false otherwise.

Example
For formula = [1,3,7], The output should be true.

For formula = [7,1,2,3], The output should be false.

For formula = [1,3,5,7], The output should be false.

For formula = [1,5,6,7,3], The output should be true.

For formula = [5,6,7], The output should be true.

For formula = [5,6,7,8], The output should be true.

For formula = [6,7,8], The output should be false.

For formula = [7,8], The output should be true.

Note

All inputs are valid. Array contains at least 1 digit. Each digit appears at most once.

Happy Coding ^_^

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
set(int x, int b)
{
	return (x & (1 << b)) != 0;
}

bool
valid(int *a, size_t n)
{
	size_t i;
	int x;
	bool r;

	x = 0;
	for (i = 0; i < n; i++)
		x |= 1 << a[i];

	r = !(set(x, 1) && set(x, 2));
	r = r && !(set(x, 3) && set(x, 4));
	r = r && (set(x, 5) == set(x, 6));
	r = r && (set(x, 7) || set(x, 8));
	return r;
}

int
main()
{
	int a1[] = {1, 3, 7};
	int a2[] = {7, 1, 2, 3};
	int a3[] = {1, 3, 5, 7};
	int a4[] = {1, 5, 6, 7, 3};
	int a5[] = {5, 6, 7};
	int a6[] = {5, 6, 7, 8};
	int a7[] = {6, 7, 8};
	int a8[] = {7, 8};

	assert(valid(a1, nelem(a1)) == true);
	assert(valid(a2, nelem(a2)) == false);
	assert(valid(a3, nelem(a3)) == false);
	assert(valid(a4, nelem(a4)) == true);
	assert(valid(a5, nelem(a5)) == true);
	assert(valid(a6, nelem(a6)) == true);
	assert(valid(a7, nelem(a7)) == false);
	assert(valid(a8, nelem(a8)) == true);

	return 0;
}
