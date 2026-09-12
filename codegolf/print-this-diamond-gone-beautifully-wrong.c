/*

Write a function (or a whole program) that outputs (or prints) the following ASCII art:

Output:
                    1
            1       2       1
      1      2      3      2      1
  1     2     3     4     3     2     1
1    2    3    4    5    4    3    2    1
1   2   3   4   5   6   5   4   3   2   1
  1  2  3  4  5  6  7  6  5  4  3  2  1
      1 2 3 4 5 6 7 8 7 6 5 4 3 2 1
            12345678987654321
      1 2 3 4 5 6 7 8 7 6 5 4 3 2 1
  1  2  3  4  5  6  7  6  5  4  3  2  1
1   2   3   4   5   6   5   4   3   2   1
1    2    3    4    5    4    3    2    1
  1     2     3     4     3     2     1
      1      2      3      2      1
            1       2       1
                    1
This is code-golf, so the shortest solution in bytes wins!

Allowed:
Any number of trailing spaces on each line
An equal number of additional leading spaces on each line (meaning of additional: without counting the already mandatory leading spaces shown in the output above)
Additional newlines at the beginning and/or at the end. These additional lines can contain any number of spaces
I'm late to the party, but as some of you may have recognized, this challenge is inspired by the bugged output in Carcigenicate's answer in Clojure for the Print this diamond challenge.

This answer also led to a chain of 3 challenges from Kevin Cruijssen : It was just a bug, It was just an input-bug, and I done did made a spaceship maw!

But i wanted to see something more "pulsar-y", as this is what i find most beautiful in the original answer!

I hope you will generate beautifully bugged ASCII arts while doing this challenge :)

*/

#include <stdio.h>

// ported from @Arnauld solution
void
roughdiamond(void)
{
	int c, p;
	int i, n;
	int q, x;

	for (n = 17; n >= 0; n--) {
		q = (n < 9) ? n : (16 - n);
		x = 9 - q;
		i = 0;
		while (q >= 0) {
			p = q + 1;
			c = x;
			if (++i <= q)
				p = i;
			if (i <= 1)
				c = (x + 12) - (q * x) + q;
			if (i > q)
				q -= 1;

			printf("%*d", c, p);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	roughdiamond();
	return 0;
}
