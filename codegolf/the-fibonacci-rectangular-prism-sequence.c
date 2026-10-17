/*

What is the Fibonacci Rectangular Prism Sequence?
The Fibonacci Rectangular Prism Sequence is a sequence derived from the Fibonacci sequence starting with one. The first 3 numbers of the Fibonacci sequence (starting with one) are 1, 1, and 2, so the first number of the Fibonacci Rectangular Prism Sequence is the square of the diagonal length of a rectangular prism (X in this picture) with the dimensions 1x1x2. The next number of the Fibonacci Rectangular Prism Sequence is the square of the diagonal length of a prism with the dimensions 1x2x3, followed by the square of the diagonal of 2x3x5, and so on. The formula for each number in the series would be A127546:

a(n) = F[n]^2 + F[n+1]^2 + F[n+2]^2

where Fn is the nth number of the Fibonacci sequence. The convention is that F0 is 0, and F1 is 1. (See A000045 for more information about the Fibonacci sequence.)

Your Challenge:
Write code that takes an index n and outputs the n'th element of the sequence. It’s code-golf, so the shortest code wins!

Test cases:
0 ==> 2
1 ==> 6
2 ==> 14
3 ==> 38
4 ==> 98
5 ==> 258
6 ==> 674
7 ==> 1766
8 ==> 4622
9 ==> 12102
10 ==> 31682

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

/*

https://oeis.org/A127546

@Lynn

The closed form is
a(n) = 4*round(phi^(2*n + 2) / 5) - 2*((-1)^n)
where phi is the golden ratio

*/

vlong
fibrp(vlong n)
{
	static const double phi = 1.6180339887498948482045868343656381177203091798058;

	vlong x, y;

	if (n < 0)
		return 0;

	x = round(pow(phi, (2 * n) + 2) / 5);
	y = (n & 1) ? 2 : -2;
	return (4 * x) + y;
}

int
main(void)
{
	vlong tab[] = {
		2, 6, 14, 38, 98, 258, 674, 1766, 4622, 12102, 31682,
		82946, 217154, 568518, 1488398, 3896678, 10201634,
		26708226, 69923042, 183060902, 479259662, 1254718086,
		3284894594, 8599965698, 22515002498, 58945041798,
		154320122894, 404015326886, 1057725857762
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(fibrp(i) == tab[i]);

	return 0;
}
