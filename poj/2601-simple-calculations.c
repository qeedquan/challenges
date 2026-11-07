/*

Description

There is a sequence of n+2 elements a0, a1, ..., an+1 (n <= 3000, -1000 <= ai <=1000). It is known that ai = (ai-1 + ai+1)/2 - ci for each i=1, 2, ..., n.
You are given a0, an+1, c1, ... , cn. Write a program which calculates a1.

Input

The first line of an input contains an integer n. The next two lines consist of numbers a0 and an+1 each having two digits after decimal point, and the next n lines contain numbers ci (also with two digits after decimal point), one number per line.

Output

The output file should contain a1 in the same format as a0 and an+1.

Sample Input

1
50.50
25.50
10.15

Sample Output

27.85
Source

Ural State University collegiate programming contest 2000

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

2a1 = a0 + a2 - 2c1
2a2 = a1 + a3 - 2c2
2a3 = a2 + a4 - 2c3
...
2an = an-1 + an+1 - 2cn，

2a1 = a0 + a2 - 2c1

a1 + a2 = a0 + a3 - 2(c1 + c2)
a1 + a3 = a0 + a4 - 2(c1 + c2 + c3)
...
a1 + an = a0 + an+1 - 2(c1 + c2 + c3 + …… + cn)
(n + 1)a1 = na0 + an+1 - 2(nc1 + (n-1)c2 + (n-2)c3 + …… + cn)

*/

double
recover(double a0, double an1, double *c, size_t n)
{
	double r;
	size_t i;

	r = (n * a0) + an1;
	for (i = 0; i < n; i++)
		r -= 2 * (n - i) * c[i];
	return r / (n + 1);
}

void
test(double a0, double an1, double *c, size_t n, double r)
{
	double x;

	x = recover(a0, an1, c, n);
	printf("%f\n", x);
	assert(fabs(x - r) < 1e-8);
}

int
main(void)
{
	double c[] = {10.15};

	test(50.50, 25.50, c, nelem(c), 27.85);
	return 0;
}
