/*

In this Kata, you will be given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:

make as few changes as possible.
if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
For example:

solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
More examples in test cases. Good luck!

Please also try:

Simple time difference

Simple remove duplicates

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
fixcase(const char *input, char *output)
{
	int (*convert)(int);
	size_t lower, upper;
	size_t index;

	lower = upper = 0;
	for (index = 0; input[index]; index++) {
		if (isupper(input[index]))
			upper++;
		else
			lower++;
	}

	convert = (lower >= upper) ? tolower : toupper;
	for (index = 0; input[index]; index++)
		output[index] = convert(input[index]);
	output[index] = '\0';
}

void
test(const char *input, const char *expected)
{
	char output[64];

	fixcase(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("coDe", "code");
	test("CODe", "CODE");
	test("coDE", "code");
	return 0;
}
