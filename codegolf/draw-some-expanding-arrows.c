/*

This challenge is about printing a series of growing ASCII-art arrows. I'll describe the pattern in words, but it might be easier to look at what the start of this series looks like:

>
<
->
<-
-->
<--
--->
<---
---->
<----
----->
<-----
------>
<------
...

An arrow with length n contains an arrowhead (< or >) and n-1 dashes (-). A right-facing arrow has the dashes first, then a >. A left-facing arrow starts with <, and is followed by the dashes. The series consists of a length n right-facing arrow followed by a length n left-facing arrow, with n from 1 to infinity.

To complete the challenge, write a program or function that takes one input, an integer i >= 1, and outputs the first i arrows. Arrows are individual, not in right-left pairs, so for i=3 you should output:

>
<
->

You can return a list of strings, or print them one after the other. If printing, the arrows must be delimited by some consistent delimiter, which doesn't have to be a newline as in the example.

This is code-golf, so fewest bytes wins.

*/

#include <stdio.h>

void
arrows(unsigned n)
{
	unsigned i, j;
	char a, b;

	if (n == 0)
		return;

	if (n == 1) {
		puts(">");
		return;
	}

	if (n == 2) {
		puts("<");
		return;
	}

	j = (n >> 1) - !(n & 1);
	a = (n & 1) ? '-' : '<';
	b = (n & 1) ? '>' : '-';

	putchar(a);
	for (i = 1; i < j; i++)
		putchar('-');
	putchar(b);
	putchar('\n');
}

int
main(void)
{
	unsigned i;

	for (i = 1; i < 15; i++)
		arrows(i);

	return 0;
}
