/*

The looping counter is a challenge that prints infinite number of lines. The first line has one *, the next line has one more * than this line, an example output is:

*
**
***
****
*****
******
*******
... (goes forever)
However, the question above is too simple and is a duplicate, so let's make it harder.

For every line, instead of printing *'s, print an uppercase english letter, also, the number of characters is not increased by one, but by the ASCII value of character in this line minus 64: the first line is one A, the second line is two B's, the third line is four C's, ..., the 26-th line is 326 Z's, the 27-th line is 352 A's, ...

A
BB
CCCC
DDDDDDD
EEEEEEEEEEE
FFFFFFFFFFFFFFFF
... (goes forever)
This is code-golf, so code in the fewest bytes.

Your output can be in any place (e.g.: Standard output, files, graphics, etc.), but must follow the format.

*/

#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

void
output()
{
	uvlong i, n, m;
	int c;

	c = 'A';
	n = 1;
	for (;;) {
		for (i = 0; i < n; i++)
			putchar(c);
		putchar('\n');

		m = c - 64;
		n = (ULLONG_MAX - n < m) ? ULLONG_MAX : n + m;
		c = (c == 'Z') ? 'A' : c + 1;
	}
}

int
main()
{
	output();
	return 0;
}
