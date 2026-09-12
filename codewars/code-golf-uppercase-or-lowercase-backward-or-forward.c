/*

Task:
In this Golfing Kata, you will receive a string s either an empty string or contaning only English alphabets.

If s is an empty string, return an empty string.

If s starts with uppercase, return s in backward sequence.

If s starts with lowercase, return s in forward sequence.

Examples:
input --> output

'' --> ''

'AND' --> 'DNA'

'Zero' --> 'oreZ'

'and' --> 'and'

'zERO' --> 'zERO'

Golfing:
The length of your code should be 28 or less.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
swap(char *a, char *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

char *
transform(char *string)
{
	size_t index, length;

	if (!isupper(string[0]))
		return string;

	length = strlen(string);
	for (index = 0; index < length / 2; index++)
		swap(&string[index], &string[length - index - 1]);
	return string;
}

void
test(const char *input, const char *expected)
{
	char string[32];

	strcpy(string, input);
	transform(string);
	puts(string);
	assert(!strcmp(string, expected));
}

int
main()
{
	test("", "");
	test("AND", "DNA");
	test("Zero", "oreZ");
	test("and", "and");
	test("zERO", "zERO");

	return 0;
}
