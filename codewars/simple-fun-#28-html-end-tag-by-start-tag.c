/*

Task
You are implementing your own HTML editor. To make it more comfortable for developers you would like to add an auto-completion feature to it.

Given the starting HTML tag, find the appropriate end tag which your editor should propose.

Example
For startTag = "<button type='button' disabled>", the output should be "</button>";

For startTag = "<i>", the output should be "</i>".

Input/Output
[input] string startTag/start_tag

[output] a string

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
endtag(const char *input, char *output)
{
	char *start, *end;

	start = strchr(input, '<');
	if (!start)
		return -1;

	for (end = start + 1; !isspace(*end) && *end != '>'; end++) {
		if (!*end)
			return -1;
	}

	output += sprintf(output, "</");
	memcpy(output, start + 1, end - start - 1);
	output += end - start - 1;
	output += sprintf(output, ">");
	return 0;
}

void
test(const char *input, const char *expected)
{
	char output[64];

	assert(endtag(input, output) >= 0);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("<button type='button' disabled>", "</button>");
	test("<i>", "</i>");
	test("<p font=\"delulu\">", "</p>");

	return 0;
}
