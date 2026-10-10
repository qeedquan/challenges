/*

Time to dig up your old trigonometry notes from high school! The challenge is to solve the unknown sides and angles of different triangles. And as is customary in code golf, the smallest working code wins.

This is not a trivial problem; my reference implementation in python is currently down to 838 837 characters, but I'm sure you'll be able to golf solutions far smaller.

Additionally, if you're stuck, this section on Wikipedia should get you going: Triangle: Computing the sides and angles.

Input
The following triangle shows the names of the sides and angles used in this challenge. Note that sides are lowercase and angles are uppercase.

https://upload.wikimedia.org/wikipedia/commons/a/a0/LabeledTriangle.svg

Input is given as six space-separated values, either on stdin or as command-line arguments (your choice). The six values correspond to the sides a, b, c and the angles A, B, C.
The unknown sides are given as question marks (?). Both input and output angles has to be in radians.
You may assume that the input values are correct (you don't have to validate anything).
You may also assume that the input triangle is non-degenerate, and that all sides and angles are nonzero.

The following example input tells you that side a is 8, side b is 12 and angle A is 0.5 radians:

8 12 ? 0.5 ? ?

Output
Output is given in the same format as the input - six space-separated numbers on stdout. The only exception is when it is not possible to solve the input triangle - then the string "No solution" must be written to stdout. If two solutions are possible, they are both outputted with a newline between them.

Following is the output for the above input:

8.0 12.0 16.0899264342 0.5 0.802561439714 1.83903121388
8.0 12.0 4.97205505116 0.5 2.33903121388 0.302561439714
Output is not required to have a lot of precision, but at least a couple decimals is required.

Rules
Input is read from stdin or command-line arguments
Output is written to stdout
If two solutions are possible with the given input, output both
If there is too little information to get one or two clear solutions, consider it a "No solution" case
No built-in or pre-existing code may be used (of course you can use trig functions, but not "solveTriangle" or such)
Shortest code wins

Test cases
In   3 4 5 ? ? ?

Out 3.0 4.0 5.0 0.643501108793 0.927295218002 1.57079630572

In   ? 4 ? 0.64 0.92 1.57

Out 3.00248479301 4.0 5.02764025486 0.64 0.92 1.57

In   ? ? 5 ? 0.92 ?

Out No solution

In   ? ? 5 ? 0.92 1.57

Out 3.03226857833 3.97800936148 5.0 0.65159265359 0.92 1.57

In   8 12 ? 0.5 ? ?

Out (two solutions)

8.0 12.0 16.0899264342 0.5 0.802561439714 1.83903121388
8.0 12.0 4.97205505116 0.5 2.33903121388 0.302561439714
In   8 12 ? ? .5 ?

Out 8.0 12.0 18.3912222133 0.325325285223 0.5 2.31626736837

Good luck!

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void
parse(const char *s, double r[6])
{
	size_t i, n;
	char *ep;

	i = 0;
	for (n = 0; n < 6; n++) {
		while (isspace(s[i]))
			i++;

		if (s[i] == '?') {
			r[n] = 0;
			i += 1;
		} else {
			r[n] = strtod(s + i, &ep);
			i = ep - s;
		}
	}
}

int
nzm(double r[6])
{
	int i, m;

	m = 0;
	for (i = 0; i < 6; i++) {
		if (r[i] != 0)
			m |= (1 << i);
	}
	return m;
}

/*

https://en.wikipedia.org/wiki/Solution_of_triangles

Sum of Angle identity (SOA)
A + B + C = 180

Three sides given (SSS), use law of cosine

A = (b^2 + c^2 - a^2) / (2 * b * c)
B = (a^2 + c^2 - b^2) / (2 * a * c)
C = 180 - A - B

Two sides and one angle (SSA), use law of sines
a / sin(A) = b / sin(B) = c / sin(C)

*/

bool
grind(double r[6])
{
	double *s, *a;
	size_t i, j, k;
	int f, nf;

	s = r;
	a = r + 3;
	f = nzm(r);
	for (;;) {
		// SSS
		if (f == 0x7) {
			a[0] = acos(((s[1] * s[1]) + (s[2] * s[2]) - (s[0] * s[0])) / (2 * s[1] * s[2]));
			a[1] = acos(((s[0] * s[0]) + (s[2] * s[2]) - (s[1] * s[1])) / (2 * s[0] * s[2]));
			a[2] = M_PI - a[0] - a[1];
		}

		// SSA
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (j == i || s[i] == 0 || a[i] == 0)
					continue;

				if (s[j] != 0 && a[j] == 0)
					a[j] = asin(s[j] / s[i] * sin(a[i]));

				if (s[j] == 0 && a[j] != 0)
					s[j] = s[i] * sin(a[j]) / sin(a[i]);
			}
		}

		// SOA
		for (i = 0; i < 3; i++) {
			j = (i + 1) % 3;
			k = (i + 2) % 3;
			if (a[i] != 0 && a[j] != 0 && a[k] == 0)
				a[k] = M_PI - a[i] - a[j];
		}

		nf = nzm(r);
		if (f == nf)
			break;
		f = nf;
	}
	return f == 0x3f;
}

bool
solve(const char *s, double r[6])
{
	parse(s, r);
	return grind(r);
}

void
test(const char *s)
{
	double r[6];

	solve(s, r);
	printf("%f %f %f %f %f %f\n",
	       r[0], r[1], r[2], r[3], r[4], r[5]);
}

int
main()
{
	test("3 4 5 ? ? ?");
	test("? 4 ? 0.64 0.92 1.57");
	test("? ? 5 ? 0.92 ?");
	test("? ? 5 ? 0.92 1.57");
	test("8 12 ? 0.5 ? ?");
	test("8 12 ? ? .5 ?");

	return 0;
}
