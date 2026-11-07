/*

We want to convert numbers in a given string to specific characters according to ASCII code with some manipulation on it. This statement 'str8ng is he17e' should converted to 'string is here', its just converting these numbers to ASCII code then to a char according to it.

So you should understand how ASCII code of chars are sorted, and if its begin with 'a' as 0, next one is 'b' which is 1 in someway.

each word contains just one character to convert the number to it.

Example: if given string is '0pple' that will return 'apple'.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void
refactor(const char *input, char *output)
{
	char *endptr;

	while (*input) {
		if (isdigit(*input)) {
			*output++ = 'a' + strtol(input, &endptr, 10);
			input = endptr;
		} else
			*output++ = *input++;
	}
	*output = '\0';
}

void
test(const char *input, const char *expected)
{
	char output[128];

	refactor(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("str8ng is he17e", "string is here");
	test("0pple", "apple");

	return 0;
}
