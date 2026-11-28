/*

The legend says that Prime Spiral was invented by Polish-American mathematician Stanislaw Ulam while attending somewhat boring conference - to struggle with drowsiness he had written natural integers in the form of rectangular spiral and started cross-out primes among them, e.g.:

                            36  35  34  33  32  31      -   -   -   -   -   X
                            17  16  15  14  13  30      X   -   -   -   X   -
    3       5   4   3       18  5   4   3   12  29      -   X   -   X   -   X
1   2   =>  6   1   2   =>  19  6   1   2   11  28  =>  X   -   ?   X   X   -
            7   8   9       20  7   8   9   10  27      -   X   -   -   -   -
                            21  22  23  24  25  26      -   -   X   -   -   -
Here we can see how the Spiral is constructed: we put 1 in the center then step right and put 2, step up and put 3, step left and put 4. We can't go down from here so spiral "widens" - we go left again to put 5, then go down putting 6 and down again putting 7 and so on.

The rightmost square shows what happens when we mark all primes with X (also 1 is marked with ? for easier reference): curious fact is that primes create "diagonal lines", sometimes quite long.

Let's introduce coordinate system here - cell with 1 is the origin (0, 0), with Y axis directed upwards, so that 33 is in the (1, 3) for example.

This pattern creates many amusing questions - for example, how large should be the Spiral, to contain rectangular "window" of the given size without primes (crosses)?

Problem Statement
Let's solve simpler exercise, somewhat "geometric": given coordinates of rectangular window, print out this rectangular part of the spiral. To further simplify we are only interested in windows from the upper-right "quadrant" of the coordinate plane.

Input contains four values X1, X2, Y1, Y2 in this order. They are all positive.

Output should contain the rectangle printed out from X1 to X2 and from Y1 to Y2 inclusive. Note that the first line of the output corresponds to Y2 and the last to Y1. Put single spaces between characters inside each line to improve readability.

Example

input:
17 41 65 85

answer:
- - - - - - X - - - X - - - - - - - - - - - - - -
- X - - - - - - - - - - - X - X - - - - - - - - -
X - - - - - - - X - - - - - - - - - - - X - - - -
- - - - - - - - - - - - - - - X - - - - - X - - -
- - - - - - X - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - - - - - -
- - - - - - - - - - X - - - - - - - X - - - X - -
- - - X - - - - - - - - - X - - - - - X - - - - -
X - - - - - - - - - - - - - X - - - - - X - - - X
- X - - - - - - - X - - - - - - - - - X - - - - -
X - - - - - - - - - - - X - - - - - X - - - - - -
- - - - - - - - - - - X - - - X - - - - - - - - -
X - - - - - X - - - - - - - - - X - - - - - - - -
- - - - - - - X - X - - - - - - - - - - - X - - -
- - - - - - X - - - - - - - X - - - - - - - - - -
- - - - - - - X - - - - - X - - - - - - - - - - -
X - - - - - - - - - - - X - - - - - - - - - - - -
- - - - - - - - - - - X - - - X - - - - - - - - -
- - - - - - - - - - X - - - - - - - - - - - X - -
- X - - - - - - - X - - - - - X - - - - - X - - -
- - - - - - - - X - - - - - - - - - - - - - - - -

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
sqr(int x)
{
	return x * x;
}

bool
isprime(int n)
{
	int i, l;

	if (n <= 1)
		return 0;

	l = sqrt(n);
	for (i = 2; i <= l; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

/*

http://www.ulisp.com/show?35SJ
https://mathoverflow.net/questions/29038/ulam-spiral-coordinate-system
https://www.quora.com/How-do-I-convert-a-number-in-Ulam-spiral-to-X-and-Y-coordinates-and-vice-versa
https://www.emergentmind.com/visualizations/prime-spirals
https://en.wikipedia.org/wiki/Ulam_spiral

*/

int
xy2n(int x, int y)
{
	int k, m;

	if (x == 0 && y == 0)
		return 1;

	k = max(abs(x), abs(y));
	m = sqr((2 * k) - 1);
	if (x == k && y != -k)
		return m + k + y;
	if (y == k && x != k)
		return m + (3 * k) - x;
	if (x == -k && y != k)
		return m + (5 * k) - y;
	return m + (7 * k) + x;
}

void
draw(int x1, int x2, int y1, int y2)
{
	int n, x, y;

	printf("%d %d %d %d\n", x1, x2, y1, y2);
	for (y = y2; y >= y1; y--) {
		for (x = x1; x <= x2; x++) {
			n = xy2n(x, y);
			if (isprime(n))
				printf("X");
			else
				printf("-");

			if (x + 1 <= x2)
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	draw(17, 41, 65, 85);
	return 0;
}
