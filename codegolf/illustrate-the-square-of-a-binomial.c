/*

Given (by any means) two different natural numbers (of any reasonable size), output (by any means) the square of their sum as in the examples below:

Given 4 and 3, output:

12 12 12 12  9  9  9
12 12 12 12  9  9  9
12 12 12 12  9  9  9
16 16 16 16 12 12 12
16 16 16 16 12 12 12
16 16 16 16 12 12 12
16 16 16 16 12 12 12
Given 1 and 3, output:

3 9 9 9
3 9 9 9
3 9 9 9
1 3 3 3
Whitespace may vary within reason but the columns must be left-aligned, right-aligned, or (pseudo-)centered.

A trailing newline is fine, but standard loopholes are not.

This is code-golf so include a header like # LanguageName, 123 in your answer, where the number is chars (bytes for languages that are not text-based). Packing code to large Unicode chars is not allowed.

Bonus: -3 if your code outputs just one square when one of the numbers is 0; e.g. given 0 and 3, output:

9 9 9
9 9 9
9 9 9

*/

#include <stdio.h>
#include <math.h>

unsigned
max(unsigned a, unsigned b)
{
	return (a > b) ? a : b;
}

void
illustrate(unsigned m, unsigned n)
{
	unsigned l, s, v;
	unsigned x, y;

	l = max(m * n, max(m * m, n * n)) + 1;
	l = ceil(log10(l));

	s = m + n;
	printf("m=%d n=%d\n", m, n);
	for (y = 0; y < s; y++) {
		for (x = 0; x < s; x++) {
			v = m * n;
			if (y < n && x >= m)
				v = n * n;
			else if (y >= n && x < m)
				v = m * m;

			printf("%*u", l, v);
			if (x + 1 < s)
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	illustrate(4, 3);
	illustrate(1, 3);
	illustrate(0, 3);
	return 0;
}
