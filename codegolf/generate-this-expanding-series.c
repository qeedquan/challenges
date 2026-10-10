/*

Challenge
Your task is to generate a string using this sequence:

1,1,2,1,1,2,3,2,1,1,3,2,4,2,3,1,....
Which is more understandable in this format:

1
1 2 1
1 2 3 2 1
1 3 2 4 2 3 1
1 4 3 2 5 2 3 4 1
The pattern increases the number of Digits in the string by two for each increment in the Value of N

For each integer value up to the total N, aside from 1 the string is centred on the current value of N and bookended by the previous values of N in decreasing order on the left, and increasing order on the right - with the exception of the value 1, which bookends the entire string.

Input
Number of steps

Output
The series separated by comma

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
gen(int n, int *r)
{
	size_t l;
	int i, j;

	if (n < 1)
		return 0;

	l = 0;
	r[l++] = 1;
	for (i = 2; i <= n; i++) {
		r[l++] = 1;
		for (j = i - 1; j > 1; j--)
			r[l++] = j;

		r[l++] = i;
		for (j = 2; j < i; j++)
			r[l++] = j;

		r[l++] = 1;
	}
	return l;
}

int
main()
{
	static const int tab[] = {1, 1, 2, 1, 1, 2, 3, 2, 1, 1, 3, 2, 4, 2, 3, 1};
	int x[128] = {};

	gen(4, x);
	assert(!memcmp(x, tab, sizeof(tab)));

	return 0;
}
