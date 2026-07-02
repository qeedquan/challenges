/*

Task
Given positive integer n, output a(n) where a is the sequence defined below:

a(n) is the smallest positive integer not yet appeared so that the sum of the first n elements in the sequence is divisible by n.

Example
a(1) is 1 because it is the smallest positive integer that has not appeared in the sequence, and 1 is divisible by 1.
a(10) is 16 because look at the first nine elements: 1,3,2,6,8,4,11,5,14. They sum up to 54, so for the first ten elements to sum up to a multiple of 10, a(10) would need to have a remainder of 6 when divided by 10. 6 has already appeared, so a(10) is 16 instead.

Testcases
n     a(n)
1     1
2     3
3     2
4     6
5     8
6     4
7     11
8     5
9     14
10    16
11    7
12    19
13    21
14    9
15    24
16    10
17    27
18    29
19    12
20    32
100   62
1000  1618
10000 16180
a(n) from n=1 to n=10000

References
OEIS A019444

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://oeis.org/A019444

@xnor

a(n) = A002251(n-1) + 1

to Wythoff pairs. Takes from the upper or lower Beatty sequence by multiplying or dividing by the golden ratio and converting to an integer.

*/

long
natperm(long n)
{
	static const double PHI = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890;

	double a, b;

	a = (n / PHI) + 1;
	b = n * PHI;
	if (fmod(n, PHI) < 1)
		return b;
	return a;
}

int
main(void)
{
	static const long tab[] = {1, 3, 2, 6, 8, 4, 11, 5, 14, 16, 7, 19, 21, 9, 24, 10, 27, 29, 12, 32, 13, 35, 37, 15, 40, 42, 17, 45, 18, 48, 50, 20, 53, 55, 22, 58, 23, 61, 63, 25, 66, 26, 69, 71, 28, 74, 76, 30, 79, 31, 82, 84, 33, 87, 34, 90, 92, 36, 95, 97, 38, 100, 39, 103, 105, 41, 108, 110, 43, 113};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(natperm(i + 1) == tab[i]);

	assert(natperm(100) == 62);
	assert(natperm(1000) == 1618);
	assert(natperm(10000) == 16180);

	return 0;
}
