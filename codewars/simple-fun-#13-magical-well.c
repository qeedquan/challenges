/*

Task
You are standing at a magical well. It has two positive integers written on it: a and b. Each time you cast a magic marble into the well, it gives you a * b dollars and then both a and b increase by 1. You have n magic marbles. How much money will you make?

Example
For a = 1, b = 2 and n = 2, the output should be 8

You will cast your first marble and get $2, after which the numbers will become 2 and 3. When you cast your second marble, the well will give you $6. Overall, you'll make $8. So, the output is 8.

Input/Output
[input] integer a

Constraints: 1 ≤ a ≤ 2000

[input] integer b

Constraints: 1 ≤ b ≤ 2000

[input] integer n

The number of magic marbles in your possession, a non-negative integer.

Constraints: 0 ≤ n ≤ 5

[output] an integer

*/

#include <assert.h>
#include <stdio.h>

int
triangular(int n)
{
	return n * (n + 1) / 2;
}

int
pyramidal(int n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

int
magicalwellbf(int a, int b, int n)
{
	int i, r;

	if (n < 0)
		return 0;

	for (i = r = 0; i < n; i++) {
		r += a * b;
		a += 1;
		b += 1;
	}
	return r;
}

/*

The sequence is:
(a * b) + (a + 1)*(b + 1) + (a + 2)*(b + 2) ... + (a + n)*(b + n)

Expand the terms out for n={1, 2, 3, ....} get the following pattern:
0
a*b
2*a*b + a + b + 1
3*a*b + 3*a + 3*b + 5
4*a*b + 6*a + 6*b + 14
5*a*b + 10*a + 10*b + 30
6*a*b + 15*a + 15*b + 55
7*a*b + 21*a + 21*b + 91
8*a*b + 28*a + 28*b + 140
9*a*b + 36*a + 36*b + 204
...

The 2nd and 3rd coefficients are triangular numbers
The 4th coefficient are pyramidal numbers

*/

int
magicalwell(int a, int b, int n)
{
	int p, t;

	if (n < 0)
		return 0;

	t = triangular(n - 1);
	p = pyramidal(n - 1);
	return (a * b * n) + (t * (a + b)) + p;
}

int
main()
{
	int a, b, n, l;

	assert(magicalwell(1, 2, 2) == 8);
	assert(magicalwell(1, 1, 1) == 1);
	assert(magicalwell(6, 5, 3) == 128);

	l = 100;
	for (a = -l; a <= l; a++) {
		for (b = -l; b <= l; b++) {
			for (n = -l; n <= l; n++)
				assert(magicalwell(a, b, n) == magicalwellbf(a, b, n));
		}
	}
	return 0;
}
