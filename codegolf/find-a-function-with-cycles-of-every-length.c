/*

A function is said to have a cycle of length n if there exists an x in its domain such that f^n(x) = x and f^m(x) ≠ x for 0 < m < n, where the superscript n denotes n-fold application of f. Note that a cycle of length 1 is a fixed point f(x) = x.

Your task is to implement a bijective function from the integers to themselves, which has exactly one cycle of every positive length n. A bijective function is a one-to-one correspondence, i.e. every integer mapped to exactly once. Having exactly one cycle of length n means that there are exactly n distinct numbers x for which f^n(x) = x and f^m(x) ≠ x for 0 < m < n.

Here is an example of what such a function might look like around x = 0:

x     ... -7 -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6  7 ...
f(x)  ...  2  4  6 -3 -1  1 -4  0 -2  5  7 -7 -6  3 -5 ...
This excerpt contains cycles of length 1 to 5:

n   cycle
1    0
2   -2  1
3   -4 -3 -1
4   -5  6  3  7
5   -7  2  5 -6  4
...
Note that above I'm using "function" only in the mathematical sense. You may write either a function or a full program in your language of choice, as long as it takes a single (signed) integer as input and returns a single (signed) integer. As usual you may take input via STDIN, command-line argument, function argument etc. and output via STDOUT, function return value or function (out) argument etc.

Of course, many languages don't (easily) support arbitrary-precision integers. It's fine if your implementation only works on the range of your language's native integer type, as long as that covers at least the range [-127, 127] and that it would work for arbitrary integers if the language's integer type was replaced with arbitrary-precision integers.

Standard code-golf rules apply.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
remap(int x)
{
	if (x < 1)
		return 1 + (2 * floor(sqrt(abs(x))));
	return 2 * floor(sqrt(x) + 0.5);
}

/*

@Magenta

For every number greater than 0, there are even loops (len 2,4,6,8...), and less than 0, odd loops (1,3,5,7). 0 maps to 0.

(-3,-2,-1),(0),(1,2),(3,4,5,6)

maps to

(-2,-1,-3),(0),(2,1),(6,3,4,5)

*/

int
cycle(int x)
{
	int n, y;

	n = remap(x);
	if (x > 0)
		y = n * (n - 2) / 4;
	else {
		y = (n + 1) / 2;
		y = -(y * y);
	}
	return y + 1 + mod(x - y - 2, n);
}

int
main()
{
	int i;

	for (i = -3; i <= 6; i++)
		printf("%d -> %d\n", i, cycle(i));

	return 0;
}
