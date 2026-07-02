/*

Create a function that takes a string and returns that string with the first half lowercased and the last half uppercased.

eg: foobar == fooBAR

If it is an odd number then 'round' it up to find which letters to uppercase. See example below.

sillycase("brian")
//         --^-- midpoint
//         bri    first half (lower-cased)
//            AN second half (upper-cased)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
sillycase(const char *s, char *b)
{
	size_t i, j, n;

	n = strlen(s);
	j = (n / 2) + (n & 1);
	for (i = 0; s[i]; i++) {
		if (i < j)
			b[i] = tolower(s[i]);
		else
			b[i] = toupper(s[i]);
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	sillycase(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("foobar", "fooBAR");
	test("brian", "briAN");
	test("Xy", "xY");

	return 0;
}
