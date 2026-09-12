/*

Description

A Compiler Mystery: We are given a C-language style for loop of type
for (variable = A; variable != B; variable += C)

  statement;

I.e., a loop which starts by setting variable to value A and while variable is not equal to B, repeats statement followed by increasing the variable by C. We want to know how many times does the statement get executed for particular values of A, B and C, assuming that all arithmetics is calculated in a k-bit unsigned integer type (with values 0 <= x < 2k) modulo 2k.

Input

The input consists of several instances. Each instance is described by a single line with four integers A, B, C, k separated by a single space. The integer k (1 <= k <= 32) is the number of bits of the control variable of the loop and A, B, C (0 <= A, B, C < 2k) are the parameters of the loop.

The input is finished by a line containing four zeros.

Output

The output consists of several lines corresponding to the instances on the input. The i-th line contains either the number of executions of the statement in the i-th instance (a single integer number) or the word FOREVER if the loop does not terminate.

Sample Input

3 3 2 16
3 7 2 16
7 3 2 16
3 4 2 16
0 0 0 0

Sample Output

0
2
32766
FOREVER

Source

CTU Open 2004

*/

#include <assert.h>

long
egcd(long a, long b, long *rx, long *ry)
{
	long px, py;
	long nx, ny;
	long x, y;
	long c, q;

	px = 1;
	py = 0;
	x = 0;
	y = 1;
	while (b != 0) {
		q = a / b;

		nx = px - (q * x);
		px = x;
		x = nx;

		ny = py - (q * y);
		py = y;
		y = ny;

		c = a % b;
		a = b;
		b = c;
	}

	*rx = px;
	*ry = py;
	return a;
}

long
executions(long A, long B, long C, long K)
{
	long d, x, y;
	long k, s, r;

	d = egcd(C, 1L << K, &x, &y);
	if (d == 0 || ((B - A) % d))
		return -1;

	k = (B - A) / d;
	r = k * x;
	s = (1L << K) / d;
	return ((r % s) + s) % s;
}

int
main(void)
{
	assert(executions(3, 3, 2, 16) == 0);
	assert(executions(3, 7, 2, 16) == 2);
	assert(executions(7, 3, 2, 16) == 32766L);
	assert(executions(3, 4, 2, 16) == -1);

	return 0;
}
