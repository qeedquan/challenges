/*

Challenge
Given two binary vectors (containing two consistent values of your choice) of length n and m, output a corresponding ascii-art hitomezashi stitching pattern.

You are to fill the following pattern, where n is the number of A-columns and m is the number of B-rows:

 A A A A A
B+B+B+B+B+B
 A A A A A
B+B+B+B+B+B
 A A A A A
Here A can be one of | and  (space), and B can be one of - and  (space). The rows and columns alternate between these two values. The binary vectors indicate, whether to start in the "on" (|/-) or "off" ( ) position for each row or column.

You may be interested in a recent Numberphile video on that topic.

Rules
n,m⩾1
There are n×m +s.
You may take input in any consistent order (rows first or columns first) and following any direction (right-to-left and top-to-bottom or reversed or mixed).
Output in any reasonable format, including one of: single string with newlines, list of lines, matrix of characters.
Output as char codes is allowed only if your language doesn't support strings natively.
Trailing whitespace is optional.

Test cases
Input: 0 1 0 1, 0 1 1
Working out:

 0 1 0 1
0+?+?+?+?
 ? ? ? ?
1+?+?+?+?
 ? ? ? ?
1+?+?+?+?
 ? ? ? ?
Output:

   |   |
 +-+ +-+
 |   |
-+ +-+ +-
   |   |
-+ +-+ +-
 |   |
Input: 0, 0
Output:


 +-
 |
Input: 1, 1
Output:

 |
-+

Input: 1 0 1 0 1, 1 0 1 0 1 0 1
Output:

 |   |   |
-+ +-+ +-+
   |   |
 +-+ +-+ +-
 |   |   |
-+ +-+ +-+
   |   |
 +-+ +-+ +-
 |   |   |
-+ +-+ +-+
   |   |
 +-+ +-+ +-
 |   |   |
-+ +-+ +-+
   |   |

*/

#include <stdio.h>
#include <string.h>

int
at(const char *a, const char *b, size_t x, size_t y)
{
	int p0, p1;

	if (!(y & 1)) {
		p0 = a[x >> 1] == '1';
		p1 = (y >> 1) & 1;
		if (!(x & 1) || p0 == p1)
			return ' ';
		return '|';
	}

	p0 = b[y >> 1] == '1';
	p1 = (x >> 1) & 1;
	if (x & 1)
		return '+';
	if (p0 ^ p1)
		return '-';
	return ' ';
}

void
pattern(const char *a, const char *b)
{
	size_t x, y, w, h;
	size_t n, m;

	n = strlen(a);
	m = strlen(b);
	w = (2 * n) + 1;
	h = (2 * m) + 1;
	printf("%s %s\n", a, b);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", at(a, b, x, y));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	pattern("0101", "011");
	pattern("0", "0");
	pattern("1", "1");
	pattern("10101", "1010101");
	return 0;
}
