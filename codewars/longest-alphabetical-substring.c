/*

Find the longest substring in alphabetical order.

Example: the longest alphabetical substring in "asdfaaaabbbbcttavvfffffdf" is "aaaabbbbctt".

There are tests with strings up to 10 000 characters long so your code will need to be efficient.

The input will only consist of lowercase characters and will be at least one letter long.

If there are multiple solutions, return the one that appears first.

Good luck :)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
longest(const char *s, char *b)
{
	const char *t;
	size_t i, j;
	size_t m, n;

	t = s;
	for (i = m = 0; s[i]; i = j) {
		j = i + 1;
		while (s[j] && s[j] >= s[j - 1])
			j++;

		n = j - i;
		if (n > m) {
			t = s + i;
			m = n;
		}
	}

	memmove(b, t, m);
	b[m] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	longest(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("asd", "as");
	test("nab", "ab");
	test("abcdeapbcdef", "abcde");
	test("asdfaaaabbbbcttavvfffffdf", "aaaabbbbctt");
	test("asdfbyfgiklag", "fgikl");
	test("z", "z");
	test("zyba", "z");
	test("", "");

	return 0;
}
