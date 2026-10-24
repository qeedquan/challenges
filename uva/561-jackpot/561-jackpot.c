#include <stdio.h>
#include <string.h>

void
count(const char *s, size_t c[256])
{
	memset(c, 0, sizeof(*c) * 256);
	for (; *s; s++)
		c[*s & 0xff] += 1;
}

double
solve(int w1, int w2, int w3, const char *s1, const char *s2, const char *s3)
{
	size_t c1[256];
	size_t c2[256];
	size_t c3[256];
	size_t i;
	double r;

	count(s1, c1);
	count(s2, c2);
	count(s3, c3);

	r = 0;
	for (i = 0; i < 256; i++) {
		r += (c1[i] * c2[i] * c3[i]) * 14.0 / (w1 * w2 * w3);
		r += (c1[i] * c2[i] * c3[i]) * 10.0 / (w1 * w2 * w3);
		r += (c1[i] * c2[i] * c3[i]) * 10.0 / (w1 * w2 * w3);
	}
	return r;
}

int
main()
{
	printf("%f\n", solve(3, 4, 6, "AAB", "BABA", "BBAAAB"));
	printf("%f\n", solve(12, 15, 18, "CCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCCCCC"));

	return 0;
}
