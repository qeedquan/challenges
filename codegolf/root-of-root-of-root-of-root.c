/*

This idea came to me when I saw my little brother playing with my calculator :D

The task

Taking a integer as an input, print that many graphical square roots under each other, like this:

n = 1

  ___
\/ 1


n = 3
    _______
   / _____
  / / ___
\/\/\/ 3


n = 5

      ___________
     / _________
    / / _______
   / / / _____
  / / / / ___
\/\/\/\/\/ 5


n = 10

           ______________________
          / ____________________
         / / __________________
        / / / ________________
       / / / / ______________
      / / / / / ____________
     / / / / / / __________
    / / / / / / / ________
   / / / / / / / / ______
  / / / / / / / / / ____
\/\/\/\/\/\/\/\/\/\/ 10

Each root consists of 4 parts, which I'm going to very scientifically name:

(s is the root size on the stack of roots, n is the input number, x is the number of digits)

    The "tail", which is a single \
    The "wall", which consists of / * s
    The "roof", which consists of _ * 2 * s + x
    And the number n under the smallest root, placed in the centre (leaving one empty space under the last _ in the smallest root)

Input

You must take input of the number n, no hardcoding the n
Output

The ascii roots your program made

This is a code-golf challenge, so lowest byte count for each language wins!


*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

int
diglen(int n)
{
	int r;

	for (r = 1; n > 0; n /= 10)
		r++;
	return r;
}

// Ported from @Dion solution
void
roots(int n)
{
	int s;

	printf("n=%d\n\n", n);
	if (n < 0)
		return;

	for (s = n; s > 0; s--) {
		repeat(" ", s);
		repeat("/ ", n - s);
		repeat("_", (2 * s) + diglen(n));
		printf("\n");
	}
	repeat("\\/", n);
	printf("%d\n\n", n);
}

int
main(void)
{
	roots(0);
	roots(1);
	roots(3);
	roots(5);
	roots(10);

	return 0;
}
