/*

Consider the fraction, n/d, where n and d are positive integers. If n < d and HCF(n, d) = 1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d <= 8 in ascending order of size, we get:

1/8
1/7
1/6
1/5
1/4
2/7
1/3
3/8
2/5
3/7
1/2
4/7
3/5
5/8
2/3
5/7
3/4
4/5
5/6
6/7
7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12000?

*/

#include <stdio.h>

typedef struct {
	long n, d;
} Rat;

Rat
R(long n, long d)
{
	return (Rat){n, d};
}

/*

https://en.wikipedia.org/wiki/Farey_sequence
https://oeis.org/A005728
https://oeis.org/A006842
https://oeis.org/A006843

*/

void
farey(long n, int (*f)(Rat, void *), void *ud)
{
	long a, b, c, d, k, x, y;

	a = 0;
	b = 1;
	c = 1;
	d = n;

	if (f(R(a, b), ud))
		return;

	while (c <= n) {
		k = (n + b) / d;
		x = (k * c) - a;
		y = (k * d) - b;

		a = c;
		b = d;
		c = x;
		d = y;

		if (f(R(a, b), ud))
			break;
	}
}

int
count(Rat r, void *ud)
{
	Rat *rp;
	long *c, *t;
	void **p;

	p = ud;
	c = p[2];
	t = p[3];

	rp = (*t == 0) ? p[0] : p[1];
	if (r.n == rp->n && r.d == rp->d)
		*t += 1;
	else if (*t == 1)
		*c += 1;

	return *t == 2;
}

long
solve(long d, Rat r0, Rat r1)
{
	long c, t;
	void *ud[4];

	c = 0;
	t = 0;
	ud[0] = &r0;
	ud[1] = &r1;
	ud[2] = &c;
	ud[3] = &t;
	farey(d, count, ud);

	return c;
}

int
main(void)
{
	Rat r0, r1;

	r0 = R(1, 3);
	r1 = R(1, 2);
	printf("%ld\n", solve(8, r0, r1));
	printf("%ld\n", solve(12000, r0, r1));

	return 0;
}
