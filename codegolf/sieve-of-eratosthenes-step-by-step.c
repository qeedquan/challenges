/*

Given a number N, draw a left aligned NxN board of numbers, leaving 1 blank (as a space) (I will show diagrams with N=5)

   2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
Your job is to construct the Sieve of Eratosthenes, step by step. First, start with 2. It's prime, so leave it there, and replace all other numbers divisible by 2 with the proper number of spaces.

   2  3     5
   7     9
11    13    15
   17    19
21    23    25
Next, go to the next unprinted number (3 in this case) and do the same.

   2  3     5
   7
11    13
   17    19
      23    25
And so on, until you reach N.

You need to first print the complete grid, and every time you go to a new number, print the board with the multiples removed. Make sure you print a blank line in between!

Examples
Text in parenthesis () are just for reference, you don't need to print it

N = 2:

  2 (complete grid)
3 4

  2 (remove multiples of 2)
3
N = 3:

  2 3 (complete grid)
4 5 6
7 8 9

  2 3 (remove multiples of 2)
  5
7   9

  2 3 (remove multiples of 3)
  5
7

Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int
mark(char *p, int x, int n)
{
	int i;

	for (i = 2; x * i <= n * n; i++)
		p[x * i] = 1;

	for (i = x + 1; i <= n * n; i++) {
		if (!p[i])
			return i;
	}
	return 0;
}

void
draw(char *p, int l, int n)
{
	int i, j, x;

	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			x = (i * n) + j;
			if (p[x])
				printf("%*s", l, " ");
			else
				printf("%*d", l, x);
		}
		printf("\n");
	}
	printf("\n\n");
}

int
visualize(int n)
{
	int l, x;
	char *p;

	if (n < 2)
		return 0;

	p = calloc(n + 1, n);
	if (!p)
		return -errno;

	p[0] = 1;
	p[1] = 1;
	l = ceil(log10(n)) + 2;

	x = 2;
	do {
		draw(p, l, n);
		x = mark(p, x, n);
	} while (x);

	free(p);

	return 0;
}

int
main(void)
{
	visualize(5);
	visualize(2);
	visualize(3);

	return 0;
}
