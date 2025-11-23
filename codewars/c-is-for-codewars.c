/*

Task:

Build a string representing a capital letter C of a given size out of 'C' characters.
Examples:

generate_C(1)

should return this string:

CCCCC
C
C
C
CCCCC

generate_C(2)

should be

CCCCCCCCCC
CCCCCCCCCC
CC
CC
CC
CC
CC
CC
CCCCCCCCCC
CCCCCCCCCC

and so on. Given size, the string should have 5*size lines, following the format above. size is a positive integer ≤ 2000.

Note that extra spaces after the C's in any line are incorrect. And the last line should not terminate with "\n".

This kata was inspired by A for Apple, but takes a different approach to generating letters.

*/

#include <stdio.h>

void
repeat(int n)
{
	int i;

	for (i = 0; i < n; i++)
		putchar('C');
	putchar('\n');
}

void
gen(int n)
{
	int i;

	for (i = 0; i < n; i++)
		repeat(5 * n);
	for (i = 0; i < 3 * n; i++)
		repeat(n);
	for (i = 0; i < n; i++)
		repeat(5 * n);
	putchar('\n');
}

int
main()
{
	int i;

	for (i = 1; i <= 4; i++)
		gen(i);
	return 0;
}
