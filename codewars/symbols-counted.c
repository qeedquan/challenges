/*

In this kata you will have to transform each string so that it contains count for every symbol it contains, starting from 2. The order of symbols should be preserved.

Example: abbreviation => a2b2revi2ton

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
transform(const char *input, char *output)
{
	size_t count[256];
	size_t index;
	char *buffer;
	int symbol;

	memset(count, 0, sizeof(count));
	for (index = 0; input[index]; index++) {
		symbol = input[index] & 0xff;
		count[symbol] += 1;
	}

	buffer = output;
	for (index = 0; input[index]; index++) {
		symbol = input[index] & 0xff;
		if (!count[symbol])
			continue;

		buffer += sprintf(buffer, "%c", input[index]);
		if (count[symbol] >= 2)
			buffer += sprintf(buffer, "%zu", count[symbol]);
		count[symbol] = 0;
	}
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	transform(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("abbreviation", "a2b2revi2ton");
	return 0;
}
