/*

https://xkcd.com/1537/

colors.rgb("blue") yields "#0000FF". colors.rgb("yellowish blue") yields NaN. colors.sort() yields "rainbow"

Using the rules set out in the image and its title text (quoted here), create a program that accepts all the given input and displays the appropriate output.

Input can be taken with stdin or nearest equivalent. There should be a line like [n]> on which to type it, and n increases by 1 each command. It should start at 1.

The result should be displayed using stdout or nearest equivalent. There should be a => on each line of output.

All 13 conditions, plus the 3 in the title (quoted) must work.

This is code golf, so shortest answer wins.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
evaluate(const char *input, char *output)
{
	static const char *keywords[][2] = {
		{ "2+\"2\"", "4" },
		{ "\"2\"+[]", "[2]" },
		{ "(2/0)", "NaN" },
		{ "(2/0)+2", "NaP" },
		{ "\"\"+\"\"", "\"+\"" },
		{ "[1,2,3]+2", "FALSE" },
		{ "[1,2,3]+4", "TRUE" },
		{ "2/(2-(3/2+1/2))", "NaN.000000000000013" },
		{ "RANGE(\" \")", "('\"', \"!\", \" \", \"!\", '\"'" },
		{ "+2", "12" },
		{ "2+2", "DONE" },
		{ "RANGE(1,5)", "(1,2,3,4,5)" },
		{ "FLOOR(10.5)", "|\n|\n|\n|___10.5___" },
		{ "colors.rgb(\"blue\")", "#0000FF" },
		{ "colors.rgb(\"yellowish blue\")", "NaN" },
		{ "colors.sort()", "rainbow" },
	};

	size_t i;

	*output = '\0';
	for (i = 0; i < nelem(keywords); i++) {
		if (!strcmp(input, keywords[i][0])) {
			strcpy(output, keywords[i][1]);
			break;
		}
	}
	return output;
}

int
main()
{
	char output[128];

	puts(evaluate("2+\"2\"", output));
	puts(evaluate("colors.sort()", output));
	puts(evaluate("+2", output));
	puts(evaluate("2+2", output));

	return 0;
}
