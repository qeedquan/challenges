/*

Given the value of N, you will have to find the value of G. The definition of G is given below:

G = Sum[i=1, i<N] Sum[j=i+1, j<=N] GCD(i, j)

Here GCD(i, j) means the greatest common divisor of integer i and integer j.

For those who have trouble understanding summation notation, the meaning of G is given in the
following code:

G=0;
for(i=1;i<N;i++)
for(j=i+1;j<=N;j++)
{
    G+=GCD(i,j);
}
// Here GCD() is a function that finds the greatest common divisor of the two input numbers

Input
The input file contains at most 100 lines of inputs. Each line contains an integer N (1 < N < 501).
The meaning of N is given in the problem statement. Input is terminated by a line containing a single
zero. This zero should not be processed.

Output
For each line of input produce one line of output. This line contains the value of G for corresponding N.

Sample Input
10
100
500
0

Sample Output
67
13015
442011

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
gcd(vlong a, vlong b)
{
	vlong t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// https://oeis.org/A178881
vlong
solve(vlong n)
{
	vlong i, j, r;

	r = 0;
	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++)
			r += gcd(i, j);
	}
	return r;
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 3, 7, 11, 20, 26, 38, 50, 67, 77, 105, 117, 142, 172, 204, 220,
		265, 283, 335, 379, 420, 442, 518, 558, 607, 661, 737, 765, 870, 900,
		980, 1052, 1117, 1199, 1331, 1367, 1440, 1526, 1666, 1706, 1859, 1901,
		2025, 2169, 2258, 2304, 2496, 2580, 2725
	};

	size_t i;

	assert(solve(10) == 67);
	assert(solve(100) == 13015);
	assert(solve(500) == 442011);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
