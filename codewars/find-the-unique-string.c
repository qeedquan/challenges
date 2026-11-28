/*

There is an array of strings. All strings contains similar letters except one. Try to find it!

findUniq([ "Aa", "aaa", "aaaaa", "BbBb", "Aaaa", "AaAaAa", "a" ]) === "BbBb"
findUniq([ "abc", "acb", "bac", "foo", "bca", "cab", "cba" ]) === "foo"
Strings may contain spaces. Spaces are not significant, only non-spaces symbols matters. E.g. string that contains only spaces is like empty string.

It’s guaranteed that array contains more than 2 strings.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
mark(const char *string, uint64_t seen[4])
{
	int symbol;

	memset(seen, 0, sizeof(*seen) * 4);
	for (; *string; string++) {
		symbol = tolower(*string) & 0xff;
		seen[symbol >> 6] |= 1 << (symbol & 0x3f);
	}
}

const char *
uniq(const char **strings, size_t length)
{
	uint64_t seen0[4], seen1[4];
	size_t index0, index1;
	size_t count;

	if (length < 3)
		return NULL;

	count = 0;
	mark(strings[0], seen0);
	for (index0 = 1; index0 < length; index0++) {
		mark(strings[index0], seen1);
		if (!memcmp(seen0, seen1, sizeof(seen0)))
			count += 1;
		else
			index1 = index0;
	}

	if (!count)
		return strings[0];
	return strings[index1];
}

void
test(const char **strings, size_t length, const char *expected)
{
	const char *result;

	result = uniq(strings, length);
	assert(result);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	const char *strings1[] = { "Aa", "aaa", "aaaaa", "BbBb", "Aaaa", "AaAaAa", "a" };
	const char *strings2[] = { "abc", "acb", "bac", "foo", "bca", "cab", "cba" };
	const char *strings3[] = { "silvia", "vasili", "victor" };
	const char *strings4[] = { "Tom Marvolo Riddle", "I am Lord Voldemort", "Harry Potter" };
	const char *strings5[] = { "    ", "a", " " };
	const char *strings6[] = { "x", "yy", "yy" };

	test(strings1, nelem(strings1), "BbBb");
	test(strings2, nelem(strings2), "foo");
	test(strings3, nelem(strings3), "victor");
	test(strings4, nelem(strings4), "Harry Potter");
	test(strings5, nelem(strings5), "a");
	test(strings6, nelem(strings6), "x");

	return 0;
}
