/*

A digit addition generator of an integer n is any integer x that satisfy the equation x + s(x) = n, with s(x) being the sum of the digits of x. (We will work under base 10 for convenience.)

For example, a digit addition generator for 29 would be 19, because 19 + (1 + 9) = 29. Some numbers have more than one generator. An example might be 216, which has generators of 198 and 207.

Your objective is to generate the sequence a_n where a_i is the lowest digit addition generator of every non-negative integer i, and anything other than a non-negative integer if there is none for i. The non-negative terms in your result should match the sequence A096234. You may find this paper related to the challenge.

Fewest bytes win; standard rules apply.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A096234
int
ldag(int n)
{
	int i;

	if (n == 0)
		return 0;

	for (i = 0; i < n; i++) {
		if (i + digsum(i) == n)
			return i;
	}
	return -1;
}

int
main(void)
{
	static const int tab[] = {
		0, -1, 1, -1, 2, -1, 3, -1, 4, -1, 5, 10, 6, 11, 7, 12, 8, 13, 9, 14,
		-1, 15, 20, 16, 21, 17, 22, 18, 23, 19, 24, -1, 25, 30, 26, 31, 27, 32,
		28, 33, 29, 34, -1, 35, 40, 36, 41, 37, 42, 38, 43, 39, 44, -1, 45, 50,
		46, 51, 47, 52, 48, 53, 49, 54, -1, 55, 60, 56, 61, 57, 62
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(ldag(i) == tab[i]);

	return 0;
}
