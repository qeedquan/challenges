/*

Write a program that, for the numbers 1 through 255, prints out BF code that will produce the given number in some byte of the array, plus a newline.

For example, the first four lines of the output could (and most likely will) be:

+
++
+++
++++
The winner will be the smallest: source code + output (in bytes).

Clarifications & Revisions:

BF programs use wrapping cells.

The output BF program must terminate with the only non-zero cell being the cell containing the number.

Programs must be output in ascending order.

Outputting a program for 0 is optional.

Negative data pointers are not allowed. < at the first pointer will do nothing. (leave a comment if it would be more appropriate to have it throw)

*/

#include <stdio.h>

void
gen(int n)
{
	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++)
			printf("+");
		printf("\n");
	}
}

int
main(void)
{
	gen(255);
	return 0;
}
