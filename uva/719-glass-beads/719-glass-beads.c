#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void
swap(size_t *a, size_t *b)
{
	size_t t;

	t = *a;
	*a = *b;
	*b = t;
}

int
minexp(const char *s, size_t n)
{
	size_t i, j, k, x, y;

	i = 0;
	j = 1;
	k = 0;
	while (i < n && j < n && k < n) {
		x = i + k;
		y = j + k;

		if (x >= n)
			x -= n;
		if (y >= n)
			y -= n;

		if (s[x] == s[y])
			k += 1;
		else if (s[x] > s[y]) {
			i = max(j + 1, i + k + 1);
			k = 0;
			swap(&i, &j);
		} else {
			j = max(i + 1, j + k + 1);
			k = 0;
		}
	}
	return i;
}

int
solve(const char *s)
{
	return minexp(s, strlen(s)) + 1;
}

int
main()
{
	assert(solve("helloworld") == 10);
	assert(solve("amandamanda") == 11);
	assert(solve("dontcallmebfu") == 6);
	assert(solve("aaabaaa") == 5);

	return 0;
}
