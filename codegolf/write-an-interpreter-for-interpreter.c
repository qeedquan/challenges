/*

I just created a language on the spot, and it's called "interpreter". Called as such because the only valid word is "interpreter"! A sample program in "interpreter" looks like this:

interpreter interpreterinterpreter interpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter
It may look meaningless, but the language works like:

interpreter initializes the accumulator to zero.
interpreterinterpreter adds one to the accumulator.
interpreterinterpreterinterpreter subtracts one from the accumulator.
interpreterinterpreterinterpreterinterpreter multiplies the accumulator by 2.
interpreterinterpreterinterpreterinterpreterinterpreter divides the accumulator by 2.
interpreterinterpreterinterpreterinterpreterinterpreterinterpreter outputs the accumulator.

Rules
Standard loopholes are forbidden.
Shortest program in bytes wins.
Your program should work for all test cases.
You may assume that all code entered is valid.
The first command will always be interpreter.
There will always be a single space between each command.
Floating point division, not integer division.
Trailing newlines are allowed.

Testcases
interpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter -> 1
interpreter interpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter -> 3
interpreter interpreterinterpreterinterpreterinterpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter -> 1
interpreter interpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter interpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter -> outputs 2, then outputs 1, then outputs 1

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
interpret(const char *s)
{
	static const char *ins[] = {
	    "interpreterinterpreterinterpreterinterpreterinterpreterinterpreter",
	    "interpreterinterpreterinterpreterinterpreterinterpreter",
	    "interpreterinterpreterinterpreterinterpreter",
	    "interpreterinterpreterinterpreter",
	    "interpreterinterpreter",
	    "interpreter",
	};
	static const size_t inslen[] = {66, 55, 44, 33, 22, 11};

	size_t op, oplen;
	size_t i;
	int ac;

	ac = 0;
	for (i = 0; s[i]; i++) {
		while (isspace(s[i]))
			i++;

		for (op = 0; op < nelem(ins); op++) {
			oplen = inslen[op];
			if (!strncmp(s + i, ins[op], oplen))
				break;
		}

		switch (op) {
		case 0:
			printf("%d\n", ac);
			break;
		case 1:
			ac /= 2;
			break;
		case 2:
			ac *= 2;
			break;
		case 3:
			ac -= 1;
			break;
		case 4:
			ac += 1;
			break;
		case 5:
			ac = 0;
			break;
		default:
			continue;
		}
		i += oplen - 1;
	}
}

int
main(void)
{
	interpret("interpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter");
	interpret("interpreter interpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter");
	interpret("interpreter interpreterinterpreterinterpreterinterpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter");
	interpret("interpreter interpreterinterpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter interpreterinterpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter interpreter interpreterinterpreter interpreterinterpreterinterpreterinterpreterinterpreterinterpreter");

	return 0;
}
