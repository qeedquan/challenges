/*

Inspiration: https://codegolf.stackexchange.com/questions/32451/9-digit-problem

Given a positive integer 1≤n≤9, output all positive n-digit integers i for which the following is true:

Each digit from 1 to n appears exactly once in i. Therefore, i's digits are a permutation of the digits from 1 to n.
i is divisible by n
Removing the rightmost digit from i yields another integer itrunc(1) which is divisible by n-1
Removing the rightmost digit from itrunc(1) yields another integer itrunc(2) which is divisible by n-2
And so on, until itrunc(n-1), which is divisible by 1.
For example, for n=3, one such integer is 321, as 321 is divisible by 3, 32 by 2 and 3 by 1.

For n=4,5,7, there are no such integers. In this case, you may output anything that cannot be confused with a possible output (e.g. 0, [], nothing, etc.).
For n=3,6, you may output the two numbers in any format in which the two numbers are clearly separated from one another.

This is code-golf so the shortest code in bytes wins.

If you use a lookup table method, brownie points† are awarded if you also include a version that calculates the correct output.

†
Brownie points may or may not be in the form of an upvote

Test cases
These cases are exhaustive, so you will never receive (or have to handle) an input not included here.

n -> i
1 -> [1]
2 -> [12]
3 -> [123, 321]
4 -> []
5 -> []
6 -> [123654, 321654]
7 -> []
8 -> [38165472]
9 -> [381654729]

*/

#include <stdio.h>

void
print(const long *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%ld", a[i]);
		if (i + 1 < n)
			printf(" ");
	}
	printf("]\n");
}

const long *
pd(long n, size_t *l)
{
	static const long tab[][2] = {
	    {1},
	    {12},
	    {123, 321},
	    {},
	    {},
	    {123654, 321654},
	    {},
	    {38165472},
	    {381654729},
	};

	const long *p;

	*l = 0;
	if (n < 1 || n > 9)
		return NULL;

	p = tab[n - 1];
	*l = !!p[0] + !!p[1];
	return p;
}

void
test(long n)
{
	const long *p;
	size_t l;

	p = pd(n, &l);
	print(p, l);
}

int
main()
{
	long i;

	for (i = 1; i <= 9; i++)
		test(i);

	return 0;
}
