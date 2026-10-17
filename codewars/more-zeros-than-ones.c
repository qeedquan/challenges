/*

Create a moreZeros function which will receive a string for input, and return an array (or null terminated string in C) containing only the characters from that string whose binary representation of its ASCII value consists of more zeros than ones.

You should remove any duplicate characters, keeping the first occurence of any such duplicates, so they are in the same order in the final array as they first appeared in the input string.

Examples

'abcde' === ["1100001", "1100010", "1100011", "1100100", "1100101"]
               True       True       False      True       False

        --> ['a','b','d']

'DIGEST'--> ['D','I','E','T']
All input will be valid strings of length > 0. Leading zeros in binary should not be counted.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbit.h>
#include <stdint.h>

char *
morezeros(const char *s, char *b)
{
	char *p;
	uint8_t u;

	for (p = b; *s; s++) {
		u = *s & 0xff;
		if (stdc_count_zeros(u) > stdc_count_ones(u))
			*p++ = *s;
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	morezeros(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("abcde", "abd");
	test("DIGEST", "DIET");

	return 0;
}
