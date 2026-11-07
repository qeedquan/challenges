/*

1729, known as the Hardy–Ramanujan number, is the smallest positive integer that can be expressed as the sum
of two cubes of positive integers in two ways (123+13=103+93=1729).
Given an integer n (as input in whatever form is natural to your language of choice)
find the smallest positive integer that can be expressed as the sum of two positive integers raised to the nth power in two unique ways.
No use of external sources.
Fewest characters wins.

Note that this is actually an unsolved problem for  n>4. For those numbers, let your program run forever in search, or die trying!
Make it so that if given infinite time and resources, the program would solve the problem.

https://en.wikipedia.org/wiki/Generalized_taxicab_number

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned long long uvlong;

// Ported from @Darren Stone solution
uvlong
find(uvlong n)
{
	uvlong a, c, b, d;
	uvlong x, y, z, w;
	uvlong r, s;

	for (r = 1; r < ULLONG_MAX; r++) {
		for (a = 0; a < r; a++) {
			x = pow(a, n);
			if (x > r)
				break;
			for (b = a; b < r; b++) {
				y = pow(b, n);
				s = x + y;
				if (s > r)
					break;
				if (s != r)
					continue;

				for (c = a + 1; c < r; c++) {
					z = pow(c, n);
					for (d = 0; d < r; d++) {
						w = pow(d, n);
						s = z + w;
						if (s == r && a != d)
							return r;
					}
				}
			}
		}
	}
	return 0;
}

int
main()
{
	printf("%llu\n", find(2));
	printf("%llu\n", find(3));

	return 0;
}
