/*

Description
Most everyone who programs using general purpose languages is familiar with regular expressions, which enable you to match inputs using patterns. Today, we'll do the inverse: given a regular expression, can you generate a pattern that will match?

For this challenge we'll use a subset of regular expression syntax:

character literals, like the letter A

* meaning zero or more of the previous thing (a character or an entity)


meaning one or more of the previous thing

. meaning any single literal

[a-z] meaning a range of characters from a to z inclusive

To tackle this you'll probably want to consider using a finite state machine and traversing it using a random walk.

Example Input
You'll be given a list of patterns, one per line. Example:

a+b
abc*d
Example Output
Your program should emit strings that match these patterns. From our examples:

aab
abd
Note that abcccccd would also match the second one, and ab would match the first one. There is no single solution, but there are wrong ones.

Challenge Input
[A-Za-z0-9$.+!*'(){},~:;=@#%_\-]*
ab[c-l]+jkm9*10+
iqb[beoqob-q]872+0qbq*

Challenge Output
While multiple strings can match, here are some examples.

g~*t@C308*-sK.eSlM_#-EMg*9Jp_1W!7tB+SY@jRHD+-'QlWh=~k'}X$=08phGW1iS0+:G
abhclikjijfiifhdjjgllkheggccfkdfdiccifjccekhcijdfejgldkfeejkecgdfhcihdhilcjigchdhdljdjkm9999910000
iqbe87222222222222222222222222222222222222222220qbqqqqqqqqqqqqqqqqqqqqqqqqq

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
next(const char **input, char *symbol)
{
	*symbol = **input;
	*input += 1;
	return *symbol != '\0';
}

void
append(char **output, char symbol)
{
	if (symbol) {
		**output = symbol;
		*output += 1;
	}
}

/*

ported from @Garth5689 solution

Iterate through each letter, tracking if it's followed by a special character or not.
This will make the minimum string possible, only taking 1 character if followed by a + and 0 if followed by a *.
When a [ is encountered, iterate through the entire brackets, taking only the last character contained in them.
Assuming valid regexes, it can't end with a - unless it's escaped.
I haven't tested it exhaustively, so if you find cases where it fails, please let me know!

*/

void
reverse_regex(const char *input, char *output)
{
	static const char ONE_OR_MORE = '+';
	static const char ZERO_OR_MORE = '*';
	static const char OPEN_BRACKET = '[';
	static const char CLOSE_BRACKET = ']';

	static const char SPECIAL_CHARACTERS[] = {
		ONE_OR_MORE,
		ZERO_OR_MORE,
		OPEN_BRACKET,
		CLOSE_BRACKET,
		0,
	};

	char symbol;
	char previous;

	previous = 0;
	for (;;) {
		if (!next(&input, &symbol))
			goto out;

		if (!strchr(SPECIAL_CHARACTERS, symbol)) {
			append(&output, previous);
			previous = symbol;
		} else if (symbol == ONE_OR_MORE) {
			append(&output, previous);
			previous = 0;
		} else if (symbol == ZERO_OR_MORE) {
			previous = 0;
		} else if (symbol == OPEN_BRACKET) {
			append(&output, previous);
			while (symbol != CLOSE_BRACKET) {
				if (!strchr(SPECIAL_CHARACTERS, symbol))
					previous = symbol;

				if (!next(&input, &symbol))
					goto out;
			}
		}
	}

out:
	if (!strchr(SPECIAL_CHARACTERS, previous))
		append(&output, previous);
	*output = '\0';
}

void
test(const char *input, const char *expected)
{
	char output[128];

	reverse_regex(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("a+b", "ab");
	test("a+b+", "ab");
	test("abcd", "abcd");
	test("abc*d", "abd");
	test("[az]b", "zb");
	test("[c-z]b", "zb");
	test("[c-z]+b", "zb");
	test("[c-zA-Z]*b+", "b");
	test("[A-Za-z0-9$.+!*\"test(){},~:;=@#%_\\-]*", "");
	test("ab[c-l]+jkm9*10+", "abljkm10");
	test("iqb[beoqob-q]872+0qbq*", "iqbq8720qb");

	return 0;
}
