/*

Alex (Alex@codegolfcorp.example) Hey champ, we've just had a huge order for those new noise-cancelling headphones we're meant to be making. Unfooooorrttunately... The software isn't done yet.

Julia (Julia@codegolfcorp.example) ...wasn't that your job?

Alex (Alex@codegolfcorp.example) That's beside the point, and we need it done, like yesterday. Can someone please write it? Minimum amount of space please, microcontroller memory doesn't grow on trees.

You (You@codegolfcorp.example) On it...

Input: A list of non-negative integers in any format desired.

Output: The same list inputted, but "outliers" are multiplied by -1, to make them negative.

An outlier is any value greater or less than 20% of the mean without it. There will only ever be 1 outlier in any given input list, or it would get too complex.

Test Cases:

[0,0,0,0] -> [0,0,0,0]

[1,1,1,1] -> [1,1,1,1]

[2,2,2,1] -> [2,2,2,-1]

[2,2,2,3] -> [2,2,2,-3]

[11,11,8] -> [11,11,-8]

[10,9,6,9,9,10,10,9,9] -> [10,9,-6,9,9,10,10,9,9]

These cases are admittedly rather simplistic, but should be sufficient to confirm your program's functionality.

Good luck, and happy golfing! Minimum byte count wins, standard rules apply, no loopholes ;).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Luis Mendo

An element x of the input needs to be negated if and only if the following condition is satisfied,
where n is the size of the input and S is the sum of the input:

abs((n - 1)/(S/x - 1) - 1) > 0.2

*/

void
outliers(int *x, size_t n)
{
	double s, v;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += x[i];

	for (i = 0; i < n; i++) {
		v = (n - 1) / ((s / x[i]) - 1) - 1;
		if (fabs(v) > 0.2)
			x[i] = -x[i];
	}
}

void
test(int *x, size_t n, int *r)
{
	outliers(x, n);
	assert(!memcmp(x, r, sizeof(*r) * n));
}

int
main()
{
	int x1[] = { 0, 0, 0, 0 };
	int x2[] = { 1, 1, 1, 1 };
	int x3[] = { 2, 2, 2, 1 };
	int x4[] = { 2, 2, 2, 3 };
	int x5[] = { 11, 11, 8 };
	int x6[] = { 10, 9, 6, 9, 9, 10, 10, 9, 9 };

	int r1[] = { 0, 0, 0, 0 };
	int r2[] = { 1, 1, 1, 1 };
	int r3[] = { 2, 2, 2, -1 };
	int r4[] = { 2, 2, 2, -3 };
	int r5[] = { 11, 11, -8 };
	int r6[] = { 10, 9, -6, 9, 9, 10, 10, 9, 9 };

	test(x1, nelem(x1), r1);
	test(x2, nelem(x2), r2);
	test(x3, nelem(x3), r3);
	test(x4, nelem(x4), r4);
	test(x5, nelem(x5), r5);
	test(x6, nelem(x6), r6);

	return 0;
}
