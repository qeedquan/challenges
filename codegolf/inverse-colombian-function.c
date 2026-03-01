/*

Let's define a sequence: The n digit summing sequence (n-DSS) is a sequence that starts with n. If the last number was k, then the next number is k + digit-sum(k). Here are the first few n-DSS:

1-DSS: 1, 2, 4, 8, 16, 23, 28, 38, 49, 62, 70...
2-DSS: 2, 4, 8, 16, 23, 28, 38, 49, 62, 70, 77...
3-DSS: 3, 6, 12, 15, 21, 24, 30, 33, 39, 51, 57...
4-DSS: 4, 8, 16, 23, 28, 38, 49, 62, 70, 77, 91...
5-DSS: 5, 10, 11, 13, 17, 25, 32, 37, 47, 58, 71...
6-DSS: 6, 12, 15, 21, 24, 30, 33, 39, 51, 57, 69...
7-DSS: 7, 14, 19, 29, 40, 44, 52, 59, 73, 83, 94...
8-DSS: 8, 16, 23, 28, 38, 49, 62, 70, 77, 91, 101...
9-DSS: 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99...
For 1, this is A004207, although the first few digits are different due to a slightly different definition. For 3, it's A016052; for 9, A016096.

Today's challenge is to find the lowest n digit sum sequence that a given number appears in. This is called the "Inverse Colombian Function", and is A036233. The first twenty terms, starting with 1 are:

1, 1, 3, 1, 5, 3, 7, 1, 9, 5, 5, 3, 5, 7, 3, 1, 5, 9, 7, 20
Some other good test cases:

117: 9
1008: 918
You only have to handle integers greater than 0, and you can take input and output in any standard format. As usual, this is code-golf, so shortest answer in each language wins.

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

// https://oeis.org/A036233
int
invcolombian(int n)
{
	int i, x;

	if (n < 1)
		return 0;

	i = x = 1;
	while (n > x) {
		x += digsum(x);
		if (x > n) {
			i += 1;
			x = i;
		}
	}
	return i;
}

int
main(void)
{
	static const int tab[] = {1, 1, 3, 1, 5, 3, 7, 1, 9, 5, 5, 3, 5, 7, 3, 1, 5, 9, 7, 20, 3, 20, 1, 3, 5, 20, 9, 1, 7, 3, 31, 5, 3, 20, 31, 9, 5, 1, 3, 7, 20, 42, 31, 7, 9, 20, 5, 42, 1, 31, 3, 7, 53, 9, 31, 20, 3, 5, 7, 42, 53, 1, 9, 64, 31, 42, 20, 53, 3, 1, 5, 9, 7, 64, 75, 31, 1, 42, 5, 20, 9, 53, 7, 3, 64, 86, 75, 20};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(invcolombian(i + 1) == tab[i]);

	assert(invcolombian(117) == 9);
	assert(invcolombian(1008) == 918);

	return 0;
}
