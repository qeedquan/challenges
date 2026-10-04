/*

Your job is to create the slowest growing function you can in no more than 100 bytes.

Your program will take as input a nonnegative integer, and output a nonnegative integer. Let's call your program P.

It must meet the these two criterion:

Its source code must be less than or equal to 100 bytes.
For every K, there is an N, such that for every n >= N, P(n) > K. In other words, lim(n->∞)P(n)=∞. (This is what it means for it to be "growing".)
Your "score" is the growth rate of your program's underlying function.

More specifically, program P is grows slower than Q if there is a N such that for all n>=N, P(n) <= Q(n), and there is at least one n>=N such that P(n) < Q(n). If neither program is better than the other, they are tied. (Essentially, which program is slower is based on the value of lim(n->∞)P(n)-Q(n).)

The slowest growing function is defined as the one that grows slower than any other function, according to the definition in the previous paragraph.

This is growth-rate-golf, so the slowest growing program wins!

Notes:

To assist in scoring, try to put what function your program calculates in the answer.
Also put some (theoretical) input and outputs, to help give people an idea of how slow you can go.

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
ackermann(uvlong m, uvlong n)
{
	if (m == 0)
		return n + 1;
	if (n == 0)
		return ackermann(m - 1, 1);
	return ackermann(m - 1, ackermann(m, n - 1));
}

uvlong
inverse_ackermann(uvlong m, uvlong n)
{
	uvlong i;

	if (n == 0)
		return 0;

	i = 1;
	while (ackermann(i, m / n) <= log2(n))
		i++;
	return i - 1;
}

int
main(void)
{
	uvlong m, n;
	uvlong x, y;

	for (m = 0; m <= 3; m++) {
		for (n = 0; n <= 4; n++) {
			x = ackermann(m, n);
			y = inverse_ackermann(m, n);
			printf("%llu %llu | %llu %llu\n", m, n, x, y);
		}
	}

	return 0;
}
