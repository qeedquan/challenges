/*

The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))(("
Notes

Assertion messages may be unclear about what they display in some languages. If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
encode(const char *input, char *output)
{
	size_t count[256];
	size_t index;
	int symbol;

	memset(count, 0, sizeof(count));
	for (index = 0; input[index]; index++) {
		symbol = tolower(input[index]);
		count[symbol] += 1;
	}

	for (index = 0; input[index]; index++) {
		symbol = tolower(input[index]);
		if (count[symbol] < 2)
			output[index] = '(';
		else
			output[index] = ')';
	}
	output[index] = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	encode(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("din", "(((");
	test("recede", "()()()");
	test("Success", ")())())");
	test("(( @", "))((");

	return 0;
}
