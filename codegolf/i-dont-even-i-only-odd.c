/*

Your task is simple: write a program that receives an integer as input and outputs it if it was odd, and does nothing otherwise (not halting is allowed). The challenge is, that you can only use odd bytes.

You can optionally append a trailing newline to the output.

This is code-golf, shortest answer in (odd) bytes wins.

Standard loopholes are forbidden. Furthermore, you cannot use versions of languages, which are newer than the posting of this challenge.

Example input > output:

13 > 13

42 >

*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int i, n;

	for (i = 1; i < argc; i++) {
		n = atoi(argv[i]);
		if (n & 1)
			printf("%d\n", n);
	}
	return 0;
}
