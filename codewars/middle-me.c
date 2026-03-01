/*

Write a function that will take a key of X and place it in the middle of Y repeated N times.

Extra challege (not tested): You can complete this with under 70 characters without using regex. Challenge yourself to do this. It wont be best practices but it will work.

Rules:

If X cannot be placed in the middle, return X.

N will always be > 0.

Example:

X = 'A';

Y = '*';

N = 10;

Y repeated N times = '**********';

X in the middle of Y repeated N times = '*****A*****';

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
middleme(size_t n, char x, char y, char *b)
{
	size_t i;
	char *p;

	if (n & 1)
		sprintf(b, "%c", x);
	else {
		p = b;
		for (i = 0; i < n / 2; i++)
			p += sprintf(p, "%c", y);
		p += sprintf(p, "%c", x);
		for (i = 0; i < n / 2; i++)
			p += sprintf(p, "%c", y);
	}

	return b;
}

void
test(size_t n, char x, char y, const char *r)
{
	char b[128];

	middleme(n, x, y, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(10, 'A', '*', "*****A*****");
	test(18, 'z', '#', "#########z#########");
	test(19, 'z', '#', "z");

	return 0;
}
