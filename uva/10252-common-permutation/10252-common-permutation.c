#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
solve(const char *s1, const char *s2)
{
	size_t c1[256];
	size_t c2[256];
	size_t j;
	int i;

	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));

	for (; *s1; s1++)
		c1[*s1 & 0xff] += 1;

	for (; *s2; s2++)
		c2[*s2 & 0xff] += 1;

	for (i = 0; i < 256; i++) {
		for (j = 0; j < c1[i] && j < c2[i]; j++)
			printf("%c", i);
	}
	printf("\n");
}

int
main()
{
	solve("pretty", "women");
	solve("walking", "down");
	solve("the", "street");

	return 0;
}
