/*

Find the most common letter (not space) in the string(always lowercase and 2 < words) and replace it with the letter.

If such letters are two or more, choose the one that appears in the string( earlier.

For example:

('my mom loves me as never did', 't') => 'ty tot loves te as never did'

('real talk bro', 'n') => 'neal talk bno'

('great job go ahead', 'k') => 'grekt job go khekd'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
replace_common(const char *input, int letter, char *output)
{
	size_t count[256];
	size_t position[256];
	size_t index;
	size_t maximum;
	int symbol;
	int common;

	memset(count, 0, sizeof(count));
	memset(position, 0, sizeof(position));
	maximum = 0;
	common = ' ';
	for (index = 0; input[index]; index++) {
		symbol = input[index] & 0xff;
		if (!count[symbol])
			position[symbol] = index;
		count[symbol] += 1;

		if (isspace(symbol))
			continue;

		if (count[symbol] > maximum || (count[symbol] == maximum && position[symbol] < position[common])) {
			maximum = count[symbol];
			common = symbol;
		}
	}

	for (index = 0; input[index]; index++) {
		symbol = input[index];
		if (symbol == common && !isspace(symbol))
			symbol = letter;
		*output++ = symbol;
	}
	*output = '\0';
}

void
test(const char *input, int letter, const char *expected)
{
	char output[128];

	replace_common(input, letter, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("my mom loves me as never did", 't', "ty tot loves te as never did");
	test("real talk bro", 'n', "neal talk bno");
	test("great job go ahead", 'k', "grekt job go khekd");
	test("yyyaaa twwww ttt uuu ccca", 'p', "yyyppp twwww ttt uuu cccp");

	return 0;
}
