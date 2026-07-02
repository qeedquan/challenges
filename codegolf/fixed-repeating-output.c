/*

Challenge
A program that solves the challenge has to do these steps in order:

Reads a decimal integer x from any sort of input (e.g.: STDIN, file)
Then, print 1 for x times to any sort of output (e.g.: STDOUT, file)
Then, print 0 to any sort of output (e.g.: STDOUT, file)
For example, if the input is 5, then:

1
1
1
1
1
0
and

111110
are both valid outputs, but

101111
is not a valid output.

A program doesn't have to output the 1's and the 0 to the same destination, but it still has to print the 1's first, then the 0. The behavior when x is nagative is undefined.

This is code-golf, so shorter program wins.

*/

#include <stdio.h>

void
fixedout(unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i++)
		puts("1");
	puts("0");
}

int
main(void)
{
	fixedout(5);
	return 0;
}
