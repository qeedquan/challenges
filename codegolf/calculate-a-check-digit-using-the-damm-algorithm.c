/*

There are popular check digit algorithms such as Luhn and then there are good ones, for example the Damm algorithm. The only possible reason behind the popularity of algorithms such as Luhn is that there exist code golfed implementations of them. This means that we as a community have the power to change the world by providing golfed implementations of better algorithms.

So this challenge is to change the world by writing a function or a complete program in your language of choice that calculates a check digit using the Damm algorithm. The answer with the smallest number of characters (not bytes) will be chosen as a winner in a few weeks. Note that all helping functions and the declaration of the operation table must be included in the character count. In case of a tie the most popular answer will be chosen.

This algorithm revolves around an operation table that must be a weakly totally anti-symmetric quasigroup of order 10. The operation table that can be found in the Wikipedia article about the Damm algorithm is the one which is to be used in this challenge. For completeness sake I will reproduce it below:

    |   0   1   2   3   4   5   6   7   8   9
----+----------------------------------------
0   |   0   3   1   7   5   9   8   6   4   2
1   |   7   0   9   2   1   5   4   8   6   3
2   |   4   2   0   6   8   7   1   3   5   9
3   |   1   7   5   0   9   8   3   4   2   6
4   |   6   1   2   3   0   4   5   9   7   8
5   |   3   6   7   4   2   0   9   5   8   1
6   |   5   8   6   9   7   2   0   1   3   4
7   |   8   9   4   5   3   6   2   0   1   7
8   |   9   4   3   8   6   1   7   2   0   5
9   |   2   5   8   1   4   3   6   7   9   0
In short (for details see the Wikipedia article) the algorithm works as follows:

You start with a list of digits to be processed and an interim digit which is set to 0.
For every digit in the list you calculate a new interim digit by using the digit as the column index and the previous interim digit as the row index.
The final interim digit is the check digit. If you are validating a number that already has an added check digit the final interim digit is 0 if the number is valid.
Your program or function must accept a string that can contain any characters except null, but it should only concern itself with the digits in the string. It must either print (if a program) or return (if a function) the original string with the calculated check digit appended. If you chose to write a program the program may either accept the input as an argument or as standard input. If the input string is empty or doesn't contain any digits you must return or append a zero.

Some examples:

Input       |   Output
------------+-------------
42          |   427
427         |   4270
2 to 2      |   2 to 29
23 42 76-   |   23 42 76-5
-           |   -0

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// https://en.wikipedia.org/wiki/Damm_algorithm
char *
damm(const char *s, char *b)
{
	static const int tab[10][10] = {
	    {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
	    {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
	    {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
	    {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
	    {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
	    {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
	    {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
	    {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
	    {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
	    {2, 5, 8, 1, 4, 3, 6, 7, 9, 0},
	};

	size_t i;
	int r, c;

	r = 0;
	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (isdigit(s[i])) {
			c = s[i] - '0';
			r = tab[r][c];
		}
	}
	b[i++] = r + '0';
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	damm(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("42", "427");
	test("427", "4270");
	test("2 to 2", "2 to 29");
	test("23 42 76-", "23 42 76-5");
	test("-", "-0");

	return 0;
}
