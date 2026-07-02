/*

Introduction
Every number can be represented as ASCII. For example, 0 comes in ASCII is 48, 1 is 49, and so on.
Using this method of translating numbers to other numbers, it is possible to infinitely expand a number, by replacing all its digits with their ASCII values and doing the same for the result.
For example, if you started with 0, you would expand to 48, then to 5256, and so on.

Challenge
You will be given a single digit and a number as input. You can assume the digit will be in the range 0−9, or 48−57 in ASCII.
You can assume the digit will always be of length 1, and will be a string.
The number will always be a positive integer, greater than -1.
If it is 0, you do not expand at all. Other than that, there are no guarantees about its value.
If, and only if your language has no method of input, you may store the input in two variables or in a list.
You must output the ASCII expansion of the digit if you expand it n times, n being the number that was the input. If your language has no method of output, you may store it in a variable.

Example I/O
Digit = 0, N = 3

Output = 53505354

Digit = 2, N = 2

Output = 5348

Digit = 5, N = 0

Output = 5

Rules
This is code-golf, so shortest answer (in bytes) wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
asciiexpand(unsigned x, unsigned n, char *b)
{
	unsigned i;
	size_t j, k;
	char *p;

	j = sprintf(b, "%u", x);
	for (i = 0; i < n; i++) {
		p = b + j + 1;
		k = 0;
		for (j = 0; b[j]; j++)
			k += sprintf(p + k, "%u", b[j]);

		memmove(b, p, k + 1);
		j = k;
	}

	return b;
}

void
test(unsigned x, unsigned n, const char *r)
{
	char b[128];

	asciiexpand(x, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, 3, "53505354");
	test(2, 2, "5348");
	test(5, 0, "5");

	return 0;
}
