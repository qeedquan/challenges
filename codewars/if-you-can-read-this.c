/*

Task
You'll have to translate a string to Pilot's alphabet (NATO phonetic alphabet).

Input:

If, you can read?

Output:

India Foxtrot , Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta ?

Note:

There are preloaded dictionary you can use, named NATO
The set of used punctuation is ,.!?.
Punctuation should be kept in your return string, but spaces should not.
Xray should not have a dash within.
Every word and punctuation mark should be seperated by a space ' '.
There should be no trailing whitespace

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
nato(const char *input, char *output)
{
	static const char *map[256] = {
		['A'] = "Alfa",
		['B'] = "Bravo",
		['C'] = "Charlie",
		['D'] = "Delta",
		['E'] = "Echo",
		['F'] = "Foxtrot",
		['G'] = "Golf",
		['H'] = "Hotel",
		['I'] = "India",
		['J'] = "Juliett",
		['K'] = "Kilo",
		['L'] = "Lima",
		['M'] = "Mike",
		['N'] = "November",
		['O'] = "Oscar",
		['P'] = "Papa",
		['Q'] = "Quebec",
		['R'] = "Romeo",
		['S'] = "Sierra",
		['T'] = "Tango",
		['U'] = "Uniform",
		['V'] = "Victor",
		['W'] = "Whiskey",
		['X'] = "Xray",
		['Y'] = "Yankee",
		['Z'] = "Zulu",
		['1'] = "One",
		['2'] = "Two",
		['3'] = "Three",
		['4'] = "Four",
		['5'] = "Five",
		['6'] = "Six",
		['7'] = "Seven",
		['8'] = "Eight",
		['9'] = "Nine",
		['0'] = "Zero",
	};

	char *buffer;
	int symbol;

	*output = '\0';
	for (buffer = output; *input; input++) {
		symbol = toupper(*input);
		if (map[symbol])
			buffer += sprintf(buffer, "%s ", map[symbol]);
		else if (!isspace(symbol))
			buffer += sprintf(buffer, "%c ", symbol);
	}
	if (buffer != output)
		buffer[-1] = '\0';
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	nato(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("If, you can read?", "India Foxtrot , Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta ?");
	return 0;
}
