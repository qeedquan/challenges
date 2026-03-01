/*

In this Kata, you will be given an array of numbers and a number n, and your task will be to determine if any array elements, when summed (or taken individually), are divisible by n.

For example:

solve([1,3,4,7,6],9) == true, because 3 + 6 is divisible by 9
solve([1,2,3,4,5],10) == true for similar reasons.
solve([8,5,3,9],7) == true, because 7 evenly divides 5 + 9
but solve([8,5,3],7) == false.
All numbers in the array will be greater than 0.

More examples in the test cases.

Good luck!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

bool
recurse(int *a, size_t n, int m, int s, size_t i)
{
	for (; i < n; i++) {
		s += a[i];
		if (!mod(s, m) || recurse(a, n, m, s - a[i], i + 1))
			return true;
	}
	return false;
}

bool
solve(int *a, size_t n, int m)
{
	if (m < 1)
		return false;
	return recurse(a, n, m, 0, 0);
}

int
main()
{
	int a1[] = { 1, 3, 4, 7, 6 };
	int a2[] = { 1, 2, 3, 4, 5 };
	int a3[] = { 8, 5, 3, 9 };
	int a4[] = { 8, 5, 3 };

	assert(solve(a1, nelem(a1), 9) == true);
	assert(solve(a2, nelem(a2), 10) == true);
	assert(solve(a3, nelem(a3), 7) == true);
	assert(solve(a4, nelem(a4), 7) == false);

	return 0;
}
