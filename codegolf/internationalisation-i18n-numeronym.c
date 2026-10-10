/*

Write the shortest program or function that accepts a sequence of three or more letters and returns its I18n-style numeronym, preserving the original letter case.
The I18n-style numeronym is formed by the first letter, the count of interior letters (the total number of letters minus 2), and the last letter.

Test Cases
Internationalization    I18n
accessibility   a11y
KUDOS   K3S
API A1I
CODE C2E
Rules
Minimum input length is 3, maximum 1024
The output must consist of the first letter, the count of intermediate letters, and the last letter.
Case must be preserved (e.g., 'Internationalization' yields 'I18n', not 'i18n').
Standard code-golf rules apply: shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
i18n(const char *input, char *output)
{
	size_t length;

	*output = '\0';
	length = strlen(input);
	if (length >= 2)
		sprintf(output, "%c%zu%c", input[0], length - 2, input[length - 1]);
}

void
test(const char *input, const char *expected)
{
	char output[128];

	i18n(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Internationalization", "I18n");
	test("accessibility", "a11y");
	test("KUDOS", "K3S");
	test("API", "A1I");
	test("CODE", "C2E");

	return 0;
}
