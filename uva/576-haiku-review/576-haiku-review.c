#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
isvowel(int c)
{
	return c && strchr("aeiouy", tolower(c));
}

int
sil(const char *s)
{
	size_t i;
	int n;

	n = 0;
	for (i = 0; s[i]; i++) {
		if (!isvowel(s[i]))
			continue;

		n += 1;
		do {
			i += 1;
		} while (isvowel(s[i]));
		i -= 1;
	}
	return n;
}

int
haiku(const char *s1, const char *s2, const char *s3)
{
	if (sil(s1) != 5)
		return 1;
	if (sil(s2) != 7)
		return 2;
	if (sil(s3) != 5)
		return 3;
	return 'Y';
}

int
main()
{
	assert(haiku("happy purple frog", "eating bugs in the marshes", "get indigestion") == 'Y');
	assert(haiku("computer programs", "the bugs try to eat my code", "i will not let them") == 2);
	assert(haiku("a e i o u", "this is seven syllables", "a e i o u y") == 3);

	return 0;
}
