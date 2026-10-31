/*

Write a function that takes a string s and an integer n, and returns whether or not the string s contains at most n different characters.

For example, ncset("aacaabbabccc", 4) would return true, because it contains only 3 different characters, 'a', 'b', and 'c', and 3 ≤ 4.

For how many English words (yes, it's time for this dictionary again!) does ncset(word, 4) hold?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef long long vlong;

bool
ncset(const char *str, size_t maxdiff)
{
	char seen[256];
	size_t diff;
	int sym;

	memset(seen, 0, sizeof(seen));
	for (diff = 0; *str; str++) {
		sym = *str & 0xff;
		if (!seen[sym]) {
			seen[sym] = 1;
			diff += 1;
		}
	}
	return diff <= maxdiff;
}

vlong
ncsetfile(const char *name, size_t maxdiff)
{
	FILE *fp;
	char line[128];
	size_t len;
	vlong diff;

	fp = fopen(name, "r");
	if (!fp)
		return -errno;

	diff = 0;
	while (fgets(line, sizeof(line), fp)) {
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';

		if (ncset(line, maxdiff))
			diff += 1;
	}

	fclose(fp);
	return diff;
}

int
main()
{
	assert(ncset("aacaabbabccc", 4) == true);
	assert(ncsetfile("enable1.txt", 4) == 10442);
	return 0;
}
