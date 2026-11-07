/*

Write a program that takes two numbers as its input. The first one is the number of dimensions - 0 for a dot, 1 for a straight line, 2 for a circle, 3 for a sphere. The second number is the radius of the object, or, if it's 1-dimensional, the number itself. Output 0 for 0 dimensions. The output is the length/area/volume of the object.

If we call the first number n, the second one r, and the output x, we get that:

for n = 0, x = 1

for n = 1, x = 2×r

for n = 2, x = r^2×π

for n = 3, x = (4/3)×r^3×π

and so on... if you want, though.

Notes:

Cases when one or both numbers are negative, or when the first number is not whole, don't need to be covered.

The program must not read from any file and the only input are those two numbers.

The output should use only numerals (e.g. not "14*pi"), and should be accurate to at least two decimal digits.

As for n = 0, you can output 0 if it makes the code shorter.

Extra swag for an answer covering even 4 and more-dimensional "spheres"!

It's code-golf, so the shortest answer in bytes wins!

Examples:

 1 1 -> 2

 2 3 -> 28,27

 3 1 -> 4,19

 3 4,5 -> 381,70

 1 9.379 -> 18.758

 0 48 -> 1

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

// https://en.wikipedia.org/wiki/Volume_of_an_n-ball
double
nball(double n, double r)
{
	return pow(M_PI, n * 0.5) * pow(r, n) / tgamma((n * 0.5) + 1);
}

void
test(double n, double r, double v)
{
	double u;

	u = nball(n, r);
	printf("%f\n", u);
	assert(fabs(u - v) < 1e-2);
}

int
main(void)
{
	test(1, 1, 2);
	test(2, 3, 28.27);
	test(3, 1, 4.19);
	test(3, 4.5, 381.70);
	test(1, 9.379, 18.758);
	test(0, 48, 1);

	return 0;
}
