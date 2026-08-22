/*

You are given an input string.

For each symbol in the string if it's the first character occurrence, replace it with a '1', else replace it with the amount of times you've already seen it.

Examples:
input   =  "Hello, World!"
result  =  "1112111121311"

input   =  "aaaaaaaaaaaa"
result  =  "123456789101112"
There might be some non-ascii characters in the string.

Take note of performance

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
numericals(const char *input, char *output)
{
	size_t count[256];
	int symbol;
	char *buffer;

	memset(count, 0, sizeof(count));
	for (buffer = output; *input; input++) {
		symbol = *input & 0xff;
		count[symbol] += 1;
		buffer += sprintf(buffer, "%zu", count[symbol]);
	}
	*buffer = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	numericals(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Hello, World!", "1112111121311");
	test("aaaaaaaaaaaa", "123456789101112");

	return 0;
}
