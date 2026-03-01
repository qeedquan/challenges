/*

Here's a nice easy challenge:

Given a string that represents a number in an unknown base, determine the lowest possible base that number might be in. The string will only contain 0-9, a-z. If you like, you may choose to take uppercase letters instead of lowercase, but please specify this. You must output this lowest possible base in decimal.

Here is a more concrete example. If the input string was "01234", it is impossible for this number to be in binary, since 2, 3, and 4 are all undefined in binary. Similarly, this number cannot be in base 3, or base 4. Therefore, this number must be in base-5, or a higher base, so you should output '5'.

Your code must work for any base between base 1 (unary, all '0's) and base 36 ('0-9' and 'a-z').

You may take input and provide output in any reasonable format. Base-conversion builtins are allowed. As usual, standard loopholes apply, and the shortest answer in bytes is the winner!

Test IO:
#Input          #Output
00000       --> 1
123456      --> 7
ff          --> 16
4815162342  --> 9
42          --> 5
codegolf    --> 25
0123456789abcdefghijklmnopqrstuvwxyz    --> 36

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
base(const char *s)
{
	int c, r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('0' <= c && c <= '9')
			c = c - '0';
		else if ('a' <= c && c <= 'z')
			c = c - 'a' + 10;
		else
			return -1;

		r = max(r, c);
	}
	return r + 1;
}

int
main(void)
{
	assert(base("00000") == 1);
	assert(base("123456") == 7);
	assert(base("ff") == 16);
	assert(base("4815162342") == 9);
	assert(base("42") == 5);
	assert(base("codegolf") == 25);
	assert(base("0123456789abcdefghijklmnopqrstuvwxyz") == 36);

	return 0;
}
