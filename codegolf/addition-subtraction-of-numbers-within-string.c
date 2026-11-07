/*

Take a string as an input, and perform addition/subtraction of all the digits in the string and output the sum of those operations as the result.

Rules
The digits in the string are read from left to right
If a digit (n) is odd, perform addition with the next digit (n + n1)
If a digit (n) is even, perform subtraction with the next digit (n - n1)
If you've reached the last digit in the string, perform the operation with the first digit in the string
Output will be the sum of all the resulting values
If there is only one digit in the string, perform the operation with itself (n+n or n-n)
If there are no digits in the string, output is 0

Example
Input: r5e6o9mm!/3708dvc
Process: (5+6) + (6-9) + (9+3) + (3+7) + (7+0) + (0-8) + (8-5)
Output: 32

Notes
Either function or full program is accepted
Maximum input length would depend on your language's limit for a string input
No restrictions on character input, but only half-width digits count towards the output
Fewest bytes wins

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
addsub(int x, int y)
{
	return (x & 1) ? x + y : x - y;
}

int
arith(const char *s)
{
	int x, y, z;
	int r, t;
	size_t i;

	r = t = x = y = z = 0;
	for (i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
			continue;

		if (t == 0) {
			x = y = z = s[i] - '0';
			t = 1;
		} else {
			x = y;
			y = s[i] - '0';
			r += addsub(x, y);
		}
	}
	r += addsub(y, z);

	return r;
}

int
main(void)
{
	assert(arith("r5e6o9mm!/3708dvc") == 32);
	return 0;
}
