/*

Description
Your crazy uncle has found a new hobby - he will occasionally scream out random words of the same length. Since he was a renowned Computer Scientist, you think he must have some pattern to this craziness. The words seem to always have a few letters in the same place, so maybe if you find his pattern his new amusement will stop annoying you.

Your task then, is to design a function letter_pattern that takes in a list of strings (all lowercase, and only including letters). It should return a string with every letter that is always there in place.

Example
['war', 'rad', 'dad'] should return "*a*", since only the second place stays constant

['general', 'admiral', 'piglets', 'secrets'] should return "*******"

['family'] should return "family"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
pattern(const char **s, size_t n, char *b)
{
	size_t i, j;

	*b = '\0';
	if (n == 0)
		return;

	for (i = 0; s[0][i]; i++) {
		for (j = 0; j + 1 < n; j++) {
			if (s[j][i] != s[j + 1][i])
				break;
		}

		if (j + 1 != n)
			b[i] = '*';
		else
			b[i] = s[0][i];
	}
	b[i] = '\0';
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	pattern(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	const char *s1[] = {"war", "rad", "dad"};
	const char *s2[] = {"general", "admiral", "piglets", "secrets"};
	const char *s3[] = {"family"};

	test(s1, nelem(s1), "*a*");
	test(s2, nelem(s2), "*******");
	test(s3, nelem(s3), "family");

	return 0;
}
