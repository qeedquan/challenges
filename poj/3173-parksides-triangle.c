/*

Description

Bessie taught the cows to make Parkside's Triangle. It is generated from two numbers: the size and the seed. The size N (1 <= N <= 20) determines how many rows are in the triangle and the seed S (1 <= S <= 9) determines the first number in the triangle. Here are two examples:

 N=5, S=3                  N=6, S=1



3 4 6 9 4                1 2 4 7 2 7

  5 7 1 5                  3 5 8 3 8

    8 2 6                    6 9 4 9

      3 7                      1 5 1

        8                        6 2

                                   3
The first line of any triangle has no blanks at its front.

Analyze the above examples, discover the rule, and write a program that will generate Parkside's Triangle given any size N (1 <= N <= 20) and any seed S (1 <= S <= 9).

Input

Line 1: Two space-separated integers: N and S

Output

Lines 1..N: Parkside's Triangle as above; no trailing blanks on any line.

Sample Input

5 3

Sample Output

3 4 6 9 4
  5 7 1 5
    8 2 6
      3 7
        8
Source

USACO 2006 December Bronze

*/

#include <stdio.h>
#include <string.h>

void
parkside(unsigned n, unsigned s)
{
	unsigned a[n][n];
	unsigned i, j;

	memset(a, 0, sizeof(a));
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			a[j][i] = s;
			s = (s < 9) ? s + 1 : 1;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j])
				printf("%u", a[i][j]);
			else
				printf(" ");

			if (j + 1 < n)
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	parkside(5, 3);
	parkside(6, 1);

	return 0;
}
