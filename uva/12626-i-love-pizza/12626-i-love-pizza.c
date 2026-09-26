#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
solve(const char *s)
{
	size_t c[256];
	size_t r;

	memset(c, 0, sizeof(c));
	for (; *s; s++)
		c[*s & 0xff] += 1;

	r = SIZE_MAX;
	r = min(r, c['M'] / 1);
	r = min(r, c['A'] / 3);
	r = min(r, c['R'] / 2);
	r = min(r, c['G'] / 1);
	r = min(r, c['T'] / 1);
	r = min(r, c['I'] / 1);
	return r;
}

int
main()
{
	assert(solve("MARGARITA") == 1);
	assert(solve("AAAAAAMMRRTITIGGRRRRRRRR") == 2);
	assert(solve("AMARGITA") == 0);
	assert(solve("BOLOGNESACAPRICHOSATOMATERA") == 1);
	assert(solve("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);

	return 0;
}
