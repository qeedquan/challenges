/*

Background:
You're working in a number zoo, and it seems that one of the numbers has gone missing!

Zoo workers have no idea what number is missing, and are too incompetent to figure it out, so they're hiring you to do it for them.

In case the zoo loses another number, they want your program to work regardless of how many numbers there are in total.

Task:
Write a function that takes a shuffled list of unique numbers from 1 to n with one element missing (which can be any number including n). Return this missing number.

Note: huge lists will be tested.

Examples:
[1, 3, 4]  =>  2
[1, 2, 3]  =>  4
[4, 2, 3]  =>  1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
missing(int *a, size_t n)
{
	size_t i;
	int s;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	return n * (n + 3) / 2 - s + 1;
}

int
main()
{
	int a1[] = {1, 3, 4};
	int a2[] = {1, 2, 3};
	int a3[] = {4, 2, 3};
	int a4[] = {1, 3, 2, 4, 6};

	assert(missing(a1, nelem(a1)) == 2);
	assert(missing(a2, nelem(a2)) == 4);
	assert(missing(a3, nelem(a3)) == 1);
	assert(missing(a4, nelem(a4)) == 5);

	return 0;
}
