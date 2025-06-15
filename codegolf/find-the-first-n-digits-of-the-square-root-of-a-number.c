/*

Given two integers m and n, return the first m digits of sqrt(n), with the decimal point. They will be given with a space in between.

You only have to produce m digits: so if m=5, n=500, then the output will be 22.360, not 22.36067.

Do not use anything that will increase the precision of any operation.

Test Cases:
20 99 -> 9.9498743710661995473
15 12345678 -> 3513.64170057221
16 256 -> 16.00000000000000
2 10000 -> 10

Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>

char *
mpsqrt(long m, long n, char *b)
{
	mpf_t x;
	char *p;
	long i;

	if (m < 0 || n < 0) {
		sprintf(b, "NAN");
		return b;
	}

	mpf_init_set_si(x, n);
	mpf_set_prec(x, m);
	mpf_sqrt(x, x);
	gmp_sprintf(b, "%.*Ff\n", m, x);
	mpf_clear(x);

	i = 0;
	for (p = b; *p; p++) {
		if (*p != '.' && ++i > m)
			break;
	}

	if (p != b && p[-1] == '.')
		p--;
	*p = '\0';

	return b;
}

void
test(long m, long n, const char *r)
{
	char b[80];

	mpsqrt(m, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(5, 500, "22.360");
	test(20, 99, "9.9498743710661995473");
	test(15, 12345678L, "3513.64170057221");
	test(16, 256, "16.00000000000000");
	test(2, 10000L, "10");
	test(1, 4, "2");
	test(1, 0, "0");
	test(0, 2, "");

	return 0;
}
