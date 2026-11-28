/*

A triangle is called an equable triangle if its area equals its perimeter. Return true, if it is an equable triangle, else return false. You will be provided with the length of sides of the triangle. Happy Coding!

*/

#include <stdio.h>

void
swap(long *a, long *b)
{
	long t;

	t = *a;
	*a = *b;
	*b = t;
}

void
sort3(long *a, long *b, long *c)
{
	if (*a > *b)
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
}

/*

https://en.wikipedia.org/wiki/Equable_shape

Combining restrictions that a shape be equable and that its dimensions be integers is significantly more restrictive than either restriction on its own.
For instance, there are infinitely many Pythagorean triples describing integer-sided right triangles, and there are infinitely many equable right triangles with non-integer sides;
however, there are only two equable integer right triangles, with side lengths (5,12,13) and (6,8,10).

More generally, the problem of finding all equable triangles with integer sides (that is, equable Heronian triangles) was considered by B. Yates in 1858.
As W. A. Whitworth and D. Biddle proved in 1904, there are exactly three solutions, beyond the right triangles already listed, with sides (6,25,29), (7,15,20), and (9,10,17).

*/

bool
equable(long a, long b, long c)
{
	long p, s;

	sort3(&a, &b, &c);
	if (a < 1 || b < 1 || c < 1 || a + b < c)
		return false;

	p = a + b + c;
	s = (-a + b + c) * (a - b + c) * (a + b - c) * (a + b + c);
	return (16 * p * p) == s;
}

int
main()
{
	long a, b, c, n;

	n = 1000;
	for (a = 0; a <= n; a++) {
		for (b = a; b <= n; b++) {
			for (c = b; c <= n; c++) {
				if (equable(a, b, c))
					printf("%ld %ld %ld\n", a, b, c);
			}
		}
	}
	return 0;
}
