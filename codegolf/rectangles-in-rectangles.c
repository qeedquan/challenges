/*

This code-golf challenge will give you two positive integers n and k as inputs and have you count the number of rectangles with integer coordinates that can be drawn with vertices touching all four sides of the n×k rectangle

{(x,y):0≤x≤n,0≤y≤k}.

That is, there should be:

at least one vertex with an x-coordinate of 0,
at least one vertex with an x-coordinate of n,
at least one vertex with an y-coordinate of 0, and
at least one vertex with an y-coordinate of k.

Example

There are a(5,7)=5 rectangles with integer coordinates touching all four sides of a 5×7 rectangle:

https://i.stack.imgur.com/D6RQw.png

The lower triangle of the (symmetric) table of a(n,k) for n,k≤12 is

n\k| 1  2  3  4  5   6   7   8   9  10  11  12
---+----------------------------------------------
 1 | 1  .  .  .  .   .   .   .   .   .   .   .
 2 | 1  2  .  .  .   .   .   .   .   .   .   .
 3 | 1  1  5  .  .   .   .   .   .   .   .   .
 4 | 1  1  1  6  .   .   .   .   .   .   .   .
 5 | 1  1  1  3  9   .   .   .   .   .   .   .
 6 | 1  1  1  1  1  10   .   .   .   .   .   .
 7 | 1  1  1  1  5   1  13   .   .   .   .   .
 8 | 1  1  1  1  1   1   5  14   .   .   .   .
 9 | 1  1  1  1  1   5   1   1  17   .   .   .
10 | 1  1  1  1  1   3   1   3   1  18   .   .
11 | 1  1  1  1  1   1   5   1   5   5  21   .
12 | 1  1  1  1  1   1   1   1   5   1   1  22

This is a code-golf challenge, so the shortest code wins.

*/

#include <assert.h>
#include <stdio.h>

int
rectangles(int n, int k)
{
	int i, r;
	int x, y;

	if (n < 1 || k < 1)
		return 0;

	r = 0;
	for (i = 0; i < n * k; i++) {
		x = (i % n) * (n - (i % n));
		y = (i / n) * (k - (i / n));
		r += (x == y);
	}
	return r;
}

int
main(void)
{
	int k, n;

	for (k = 1; k <= 12; k++) {
		for (n = 1; n <= k; n++) {
			printf("%2d ", rectangles(n, k));
			assert(rectangles(n, k) == rectangles(k, n));
		}
		printf("\n");
	}
	return 0;
}
