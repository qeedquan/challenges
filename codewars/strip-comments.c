/*

Complete the solution so that it strips all text that follows any of a set of comment markers passed in. Any whitespace at the end of the line should also be stripped out.

Example:

Given an input string of:

apples, pears # and bananas
grapes
bananas !apples
The output expected would be:

apples, pears
grapes
bananas
The code would be called like so:

var result = solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"])
// result should == "apples, pears\ngrapes\nbananas"

*/

#include <stdio.h>
#include <string.h>

void
strip_comments(const char *input, const char *markers, char *output)
{
	bool comment[256];
	char *buffer;
	int symbol;

	memset(comment, 0, sizeof(comment));
	for (; *markers; markers++) {
		symbol = *markers & 0xff;
		comment[symbol] = true;
	}

	buffer = output;
	for (;;) {
		symbol = *input & 0xff;
		if (comment[symbol]) {
			while (*input && *input != '\n')
				input++;

			while (buffer > output && strchr(" \t", buffer[-1]))
				buffer--;
		}
		if (!*input)
			break;

		*buffer++ = *input++;
	}
	*buffer = '\0';
}

void
test(const char *input, const char *markers)
{
	char output[128];

	strip_comments(input, markers, output);
	puts(output);
}

int
main()
{
	const char *input1 = "apples, pears # and bananas\n"
	                     "grapes\n"
	                     "bananas !apples";

	test(input1, "#!");
	return 0;
}
