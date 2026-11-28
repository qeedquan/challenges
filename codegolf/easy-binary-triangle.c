/*

Given as input a positive integer n>=1, output the first n rows of the following triangle:

                  1
                1 0 1
              0 0 1 0 0
            1 1 1 0 1 1 1
          0 0 0 0 1 0 0 0 0
        1 1 1 1 1 0 1 1 1 1 1
      0 0 0 0 0 0 1 0 0 0 0 0 0
    1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
  0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1
The rows alternate between all zeroes and all ones, except the center column is flipped.

Test cases
Input: 3

Output:

    1
  1 0 1
0 0 1 0 0

Input: 10

Output:

                  1
                1 0 1
              0 0 1 0 0
            1 1 1 0 1 1 1
          0 0 0 0 1 0 0 0 0
        1 1 1 1 1 0 1 1 1 1 1
      0 0 0 0 0 0 1 0 0 0 0 0 0
    1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
  0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1
Your code must work for any n<100. This is code-golf, hence the shortest code in bytes wins!

Trailing spaces / newlines and leading newlines are allowed!

*/

#include <stdio.h>

void
bt(int n)
{
	int d, l, s;
	int i, j;
	int c;

	c = 0;
	l = (4 * (n - 1)) + 1;
	for (i = 0; i < n; i++) {
		s = (l / 2) - (2 * i);
		d = (2 * i) + 1;

		for (j = 0; j < s; j++)
			printf(" ");

		for (j = 0; j < d; j++) {
			if (j == d / 2)
				printf("%d", !c);
			else
				printf("%d", c);

			if (j + 1 < d)
				printf(" ");
		}
		c ^= 1;

		printf("\n");
	}
}

int
main(void)
{
	bt(3);
	bt(10);

	return 0;
}
