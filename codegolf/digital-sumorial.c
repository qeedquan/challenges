/*

Given an input n, write a program or function that outputs/returns the sum of the digital sums of n for all the bases 1 to n.

n + Sum[b=2, n] Sum[i=0, inf] floor(n/b^i) mod b

Example:
n = 5

Create the range [1...n]: [1,2,3,4,5]

For each element x, get an array of the base-x digits of n: [[1,1,1,1,1],[1,0,1],[1,2],[1,1],[1,0]]

bijective base-1 of 5 is [1,1,1,1,1]

base-2 (binary) of 5 is [1,0,1]

base-3 of 5 is [1,2]

base-4 of 5 is [1,1]

base-5 of 5 is [1,0]

Sum the digits: 13

Test cases:
1    1
2    3
3    6
4    8
5    13
6    16
7    23
8    25
9    30
10   35

36   297
37   334

64   883
65   932
The sequence can be found on OEIS: A131383

Scoring:
code-golf: The submission with the lowest score wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://oeis.org/A131383

@Dennis

a(n) = Sum[b=2, n+1] Sum[i=0, n-1] floor(n/b^i) mod b
which works since floor(n/(n+1)^0) mod(n+1) = n

*/

int
digitalsumorial(int n)
{
	int b, i, r, v;

	r = 0;
	for (b = 2; b <= n + 1; b++) {
		for (i = 0; i <= n - 1; i++) {
			v = n / pow(b, i);
			r += v % b;
		}
	}
	return r;
}

int
main(void)
{
	static const int tab[] = {1, 3, 6, 8, 13, 16, 23, 25, 30, 35, 46, 46, 59, 66, 75, 74, 91, 91, 110, 112, 125, 136, 159, 152, 169, 182, 195, 199, 228, 223, 254, 253, 274, 291, 316, 297, 334, 353, 378, 373, 414, 409, 452, 460, 475, 498, 545, 520, 557, 565, 598, 608, 661, 652, 693, 690};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(digitalsumorial(i + 1) == tab[i]);

	assert(digitalsumorial(64) == 883);
	assert(digitalsumorial(65) == 932);

	return 0;
}
