/*

Goal
Your goal is to find the simplest value in an open interval. In other words, given two values a,b with a<b, output the simplest x with a<x<b. This is a code golf, so fewest bytes wins.

Simplicity
All values in this problem are dyadic rationals, which means their binary expansions are finite, or equivalently, are rationals in simplest form a/2^b for some integer a and non-negative integer b. Integers are dyadic rationals with b=0.

Being simpler means having smaller b, tiebroken by smaller absolute value |a|.

Equivalently in terms of binary expansions, to find the simpler number:

Take the one with a shorter fractional part (fewer binary digits after the point).
In case of tie, take the lexicographically earlier one with length the primary sort, ignoring sign.
So, the numbers in simplicity order are

0, ±1, ±2, ±3, ±4, ...
±1/2, ±3/2, ±5/2, ...
±1/4, ±3/4, ±5/4, ...
±1/8, ±3/8, ...
±1/16, ...
...
There's no need to say which of ±x is simpler because any interval that contains both candidates also contains 0, which is simpler than both.

(A bit of background and motivation: In combinatorial game theory, positions in a two-player games have a numerical value representing magnitude of advantage, with the sign saying which player is favored. This value is determined recursively from the two values resulting from the best move of each player. You might guess that one averages them, but in fact it's the simplest value in between.)

Program requirements
Write, in as few bytes as possible, a program or named function that takes two dyadic rationals a,b and outputs the simplest dyadic rational x with a<x<b. Input can be function input or STDIN, and output can be function return or printing.

Input format

Two dyadic rationals a,b in whatever type your languages use for real or finite-precision binary values (float, double, etc). Fraction or rational types that store the value as a numerator and denominator are not acceptable. If you language has no valid type (and only then), you may use binary strings like 101.1101, or post a comment and we'll work something out.

You are guaranteed that a,b are dyadic rationals and a<b. Integer values will be given like 3.0, not 3.

You can assume you have sufficient precision to store the values, the output, and any intermediate steps exactly. So, you shouldn't worry about precision or overflows. I won't give an explicit bound on inputs, but your algorithm should take a reasonable amount of time on inputs like the test cases.

You may take your two numbers in any reasonable built-in container like pair, tuple, list, array, or set. Structures specifically representing intervals are not allowed though.

Output

The simplest dyadic rational strictly between a and b. The same rules for the input types apply, except outputting 3 rather than 3.0 is OK.

Test cases

(-1.0, 1.0)
0.0
(0.0, 2.0)
1.0
(0.0, 4.0)
1.0
(0.5, 2.0)
1.0
(-3.25, -2.5)
-3.0
(-4, 1.375)
0.0
(4.5, 4.625)
4.5625
(-1.875, -1.5)
-1.75

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
recurse(double a, double b, double i)
{
	double r;

	r = 0;
	if (a >= 0)
		r = floor(a * i + 1) / i;
	if (b <= 0)
		return -recurse(-b, -a, i);
	if (r < b)
		return r;
	return recurse(a, b, i * 2);
}

// ported from @KSab solution
double
simplest(double a, double b)
{
	return recurse(a, b, 1);
}

void
test(double a, double b, double r)
{
	double x;

	x = simplest(a, b);
	printf("%f %f | %f %f\n", a, b, x, r);
	assert(fabs(x - r) < 1e-2);
}

int
main(void)
{
	test(-1, 1, 0);
	test(0, 2, 1);
	test(0, 4, 1);
	test(0.5, 2, 1);
	test(-3.25, -2.5, -3);
	test(-4, 1.375, 0);
	test(4.5, 4.625, 4.5625);
	test(-1.875, -1.5, -1.75);
	return 0;
}
