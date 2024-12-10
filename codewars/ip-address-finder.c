/*

You are given a string representing a website's address. To calculate the IP4 address you must convert all the characters into ASCII code, then calculate the sum of the values.

the first part of the IP number will be the result mod 256
the second part of the IP number will be the double of the sum mod 256
the third will be the triple of the sum mod 256
the fourth will be the quadruple of the sum mod 256
Input
A string representing the website address

Output
An array containing the four parts of the IP value

Examples
"www.codewars.com"  --->  [88, 176, 8, 96]
"www.starwiki.com"  --->  [110, 220, 74, 184]
Restrictions
Code length <= 77 characters
require is forbidden

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
ipf(const char *s, unsigned r[4])
{
	size_t i;
	unsigned v;

	v = 0;
	for (i = 0; s[i]; i++)
		v += s[i] & 0xff;

	for (i = 0; i < 4; i++)
		r[i] = (v * (i + 1)) & 0xff;
}

void
test(const char *s, unsigned r[4])
{
	unsigned p[4];

	ipf(s, p);
	printf("%u %u %u %u\n", p[0], p[1], p[2], p[3]);
	assert(!memcmp(p, r, sizeof(p)));
}

int
main()
{
	unsigned r1[] = {88, 176, 8, 96};
	unsigned r2[] = {110, 220, 74, 184};

	test("www.codewars.com", r1);
	test("www.starwiki.com", r2);

	return 0;
}
