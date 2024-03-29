/*

Task
Your task is to print this exact text:

A
BCD
EFGHI
JKLMNOP
QRSTUVWXY
ZABCDEFGHIJ
KLMNOPQRSTUVW
XYZABCDEFGHIJKL
MNOPQRSTUVWXYZABC
DEFGHIJKLMNOPQRSTUV
WXYZABCDEFGHIJKLMNOPQ
RSTUVWXYZABCDEFGHIJKLMN
OPQRSTUVWXYZABCDEFGHIJKLM
NOPQRSTUVWXYZABCDEFGHIJKLMN
OPQRSTUVWXYZABCDEFGHIJKLMNOPQ
RSTUVWXYZABCDEFGHIJKLMNOPQRSTUV
WXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC
DEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKL
MNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW
XYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ
KLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXY
ZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOP
QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHI
JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCD
EFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZA
BCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ

Specs

You may do it in all-lowercase instead of all-uppercase.
Trailing newlines at the end of the triangle is allowed.
Trailing spaces after each line is allowed.
You must print to STDOUT instead of outputting an array of strings.

Scoring

This is code-golf. Program with lowest byte-count wins.

*/

#include <stdio.h>

void
triangle(int n)
{
	int i, j;
	char c;

	c = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= 2 * i; j++) {
			printf("%c", 'A' + c);
			c = (c + 1) % 26;
		}
		printf("\n");
	}
}

int
main(void)
{
	triangle(26);

	return 0;
}
