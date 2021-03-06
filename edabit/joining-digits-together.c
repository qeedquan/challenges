/*

Create a function which takes in a number n as input and returns all numbers up to and including n joined together in a string.
Separate each digit from each other with the character "-".

Examples

joinDigits(4) ➞ "1-2-3-4"

joinDigits(11) ➞ "1-2-3-4-5-6-7-8-9-1-0-1-1"

joinDigits(15) ➞ "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5"

Notes

Remember to start at 1 and include n as the last number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
joindigits(unsigned n, char *b)
{
	char p[sizeof(n) * 16];
	size_t j, k;
	unsigned i;

	j = 0;
	for (i = 1; i <= n; i++) {
		snprintf(p, sizeof(p), "%u", i);
		for (k = 0; p[k]; k++) {
			b[j++] = p[k];
			if (p[k + 1])
				b[j++] = '-';
		}
		if (i < n)
			b[j++] = '-';
	}
	b[j] = '\0';

	return b;
}

void
test(unsigned n, const char *r)
{
	char b[256];

	joindigits(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "1");
	test(2, "1-2");
	test(3, "1-2-3");
	test(4, "1-2-3-4");
	test(5, "1-2-3-4-5");
	test(6, "1-2-3-4-5-6");
	test(7, "1-2-3-4-5-6-7");
	test(8, "1-2-3-4-5-6-7-8");
	test(9, "1-2-3-4-5-6-7-8-9");
	test(10, "1-2-3-4-5-6-7-8-9-1-0");
	test(11, "1-2-3-4-5-6-7-8-9-1-0-1-1");
	test(12, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2");
	test(13, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3");
	test(14, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4");
	test(15, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5");
	test(16, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6");
	test(17, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7");
	test(18, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8");
	test(19, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9");
	test(20, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0");
	test(21, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1");
	test(22, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2");
	test(23, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3");
	test(24, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4");
	test(25, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5");
	test(26, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6");
	test(27, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7");
	test(28, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8");
	test(29, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9");
	test(30, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0");
	test(31, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1");
	test(32, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2");
	test(33, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3");
	test(34, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4");
	test(35, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5");
	test(36, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6");
	test(37, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7");
	test(38, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8");
	test(39, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9");
	test(40, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0");
	test(41, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1");
	test(42, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2");
	test(43, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3");
	test(44, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4");
	test(45, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5");
	test(46, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5-4-6");
	test(47, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5-4-6-4-7");
	test(48, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5-4-6-4-7-4-8");
	test(49, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5-4-6-4-7-4-8-4-9");
	test(50, "1-2-3-4-5-6-7-8-9-1-0-1-1-1-2-1-3-1-4-1-5-1-6-1-7-1-8-1-9-2-0-2-1-2-2-2-3-2-4-2-5-2-6-2-7-2-8-2-9-3-0-3-1-3-2-3-3-3-4-3-5-3-6-3-7-3-8-3-9-4-0-4-1-4-2-4-3-4-4-4-5-4-6-4-7-4-8-4-9-5-0");

	return 0;
}
