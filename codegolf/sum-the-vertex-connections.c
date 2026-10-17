/*

Let's say you have a positive integer N. First, build a regular polygon, that has N vertices, with the distance between neighbouring vertices being 1. Then connect lines from every vertex, to every other vertex. Lastly, calculate the length of all lines summed up together.

Example
Given the input N = 6, build a hexagon with lines connecting every vertex with the other vertices.

Hexagon
https://i.stack.imgur.com/ZXclz.png

As you can see, there are a total of 6 border lines (length=1), 3 lines that have double the border length (length=2) and 6 other lines that we, by using the Pythagoras Theorem, can calculate the length for, which is

If we add the lengths of the lines together we get (6 * 1) + (3 * 2) + (6 * 1.732) = 22.392.

Additional Information
As structures with 2 or less vertices are not being considered polygons, output 0 (or NaN, since distance between a single vertex doesn't make much sense) for N = 1, since a single vertice cannot be connected to other vertices, and 1 for N = 2, since two vertices are connected by a single line.

Input
An integer N, in any reasonable format.

Output
The length of all the lines summed up together, accurate to at least 3 decimal places, either as a function return or directly printed to stdout.

Rules
Standard loopholes are forbidden.
This is code-golf, so the shortest code in bytes, in any language, wins.
Good luck!

Test Cases
(Input) -> (Output)
1 -> 0 or NaN
2 -> 1
3 -> 3
5 -> 13.091
6 -> 22.392

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@Jonathan Allan

This uses a formula for the sum of the lengths if a polygon is inscribed inside a unit circle, n*cot(pi/2/n)/2 and adjusts the result to one for the side length being one by dividing by the sin of that cord length sin(pi/n).

The first formula is acquired by considering the n-1 cord lengths of all the diagonals emanating from one corner which are of lengths sin(pi/n) (again), sin(2*pi/n), ..., sin((n-1)pi/n). The sum of this is cot(pi/2/n), there are n corners so we multiply by n, but then we've double counted all the cords, so we divide by two.

The resulting n*cot(pi/2/n)/2/sin(pi/n) was then simplified by xnor to n/2/(1-cos(pi/n)) (holding for n>1)

...this (so long as the accuracy is acceptable) now no longer requires sympy over the built-in math module (math.pi=3.141592653589793).

*/

double
vertexsum(int n)
{
	if (n < 2)
		return 0;
	return (n / 2.0) / (1 - cos(M_PI / n));
}

void
test(int n, double r)
{
	double v;

	v = vertexsum(n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(1, 0);
	test(2, 1);
	test(3, 3);
	test(5, 13.091);
	test(6, 22.392);

	return 0;
}
