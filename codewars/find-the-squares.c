/*

Problem
Complete the function that takes an odd integer (0 < n < 1000000) which is the difference between two consecutive perfect squares, and return these squares as a string in the format "bigger-smaller"

Examples
9  -->  "25-16"
5  -->  "9-4"
7  -->  "16-9"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

/*

There are no solutions for even numbers.

For odd numbers, the solutions are:
1: 1-0
3: 4-1
5: 9-4
7: 16-9
9: 25-16
11: 36-25
13: 49-36
15: 64-49
17: 81-64
19: 100-81
21: 121-100
23: 144-121
...

The solution space are enumerating all of the square numbers without gaps

*/

char *
solvebf(vlong n, char *b)
{
	vlong i, x, y;

	for (i = 0; i < n; i++) {
		x = (i + 1) * (i + 1);
		y = i * i;
		if (x - y == n) {
			sprintf(b, "%lld-%lld", x, y);
			return b;
		}
	}
	sprintf(b, "no solution");
	return b;
}

char *
solve(vlong n, char *b)
{
	vlong x, y;

	if (n < 1 || !(n & 1)) {
		sprintf(b, "no solution");
		return b;
	}

	n /= 2;
	x = (n + 1) * (n + 1);
	y = n * n;
	sprintf(b, "%lld-%lld", x, y);
	return b;
}

int
main()
{
	char s[128], t[128];
	vlong i;

	assert(!strcmp(solve(5, s), "9-4"));
	assert(!strcmp(solve(7, s), "16-9"));
	assert(!strcmp(solve(9, s), "25-16"));
	assert(!strcmp(solve(1887, s), "891136-889249"));
	assert(!strcmp(solve(99991, s), "2499600016-2499500025"));

	for (i = 0; i <= 50000; i++)
		assert(!strcmp(solve(i, s), solvebf(i, t)));

	return 0;
}
