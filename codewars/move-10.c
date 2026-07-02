/*

Move every letter in the provided string forward 10 letters through the alphabet.

If it goes past 'z', start again at 'a'.

Input will be a string with length > 0.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rot10(const char *input, char *output)
{
	char *buffer;

	for (buffer = output; *input; input++) {
		if ('a' <= *input && *input <= 'z')
			*buffer++ = 'a' + ((*input - 'a' + 10) % 26);
		else if ('A' <= *input && *input <= 'Z')
			*buffer++ = 'A' + ((*input - 'A' + 10) % 26);
		else
			*buffer++ = *input;
	}
	*buffer = '\0';
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	rot10(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("testcase", "docdmkco");
	test("codewars", "mynogkbc");
	test("exampletesthere", "ohkwzvodocdrobo");

	return 0;
}
