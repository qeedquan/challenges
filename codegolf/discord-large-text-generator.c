/*

Input:

The input will be a string of any characters.

Output:

the output will be an emojified (discord emojis) version of the input string. The way it will work is as so:

Letters: a-z (case insensitive) will become ':regional_indicator_lowercase letter here:'

e.g 'A' will become ':regional_indicator_a:'

Digits: any digits (0-9) will become the word version of the digit like so ':digit:'

e.g '0' will become ':zero:'

Whitespace: any whitespace character that's matched with the regex: /\s/ will become ':white_large_square:'

e.g ' ' will become ':white_large_square:'

Important notes:

The ':' surrounding the emoji's are necessary or else it won't display correctly in discord.

Each emoji needs to be separated by 1 space or else it won't display correctly in discord.

Trailing whitespace is allowed in the final output.

Any other characters that it comes across should not be in the final output and will be ignored.

Examples:

#1: Input:

this is a test string 0123456789
output:

:regional_indicator_t: :regional_indicator_h: :regional_indicator_i: :regional_indicator_s: :white_large_square: :regional_indicator_i: :regional_indicator_s: :white_large_square: :regional_indicator_a: :white_large_square: :regional_indicator_t: :regional_indicator_e: :regional_indicator_s: :regional_indicator_t: :white_large_square: :regional_indicator_s: :regional_indicator_t: :regional_indicator_r: :regional_indicator_i: :regional_indicator_n: :regional_indicator_g: :white_large_square: :zero: :one: :two: :three: :four: :five: :six: :seven: :eight: :nine:
#2: input:

!?#$YAY 1234
output:

:regional_indicator_y: :regional_indicator_a: :regional_indicator_y: :white_large_square: :one: :two: :three: :four:
#3: input:

lots         of         spaces
output:

:regional_indicator_l: :regional_indicator_o: :regional_indicator_t: :regional_indicator_s: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :regional_indicator_o: :regional_indicator_f: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :regional_indicator_s: :regional_indicator_p: :regional_indicator_a: :regional_indicator_c: :regional_indicator_e: :regional_indicator_s:

Examples as shown in discord:

https://i.sstatic.net/f8JX7.png

This is codegolf so the shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
discord(const char *s, char *b)
{
	static const char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	size_t i, l;
	int c;

	*b = '\0';
	for (i = l = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z')
			l += sprintf(b + l, ":regional_indicator_%c:", c);
		else if ('0' <= c && c <= '9')
			l += sprintf(b + l, ":%s:", digits[c - '0']);
		else if (isspace(c))
			l += sprintf(b + l, ":white_large_square:");
		else
			continue;

		if (s[i + 1])
			l += sprintf(b + l, " ");
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[1024];

	discord(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("this is a test string 0123456789", ":regional_indicator_t: :regional_indicator_h: :regional_indicator_i: :regional_indicator_s: :white_large_square: :regional_indicator_i: :regional_indicator_s: :white_large_square: :regional_indicator_a: :white_large_square: :regional_indicator_t: :regional_indicator_e: :regional_indicator_s: :regional_indicator_t: :white_large_square: :regional_indicator_s: :regional_indicator_t: :regional_indicator_r: :regional_indicator_i: :regional_indicator_n: :regional_indicator_g: :white_large_square: :zero: :one: :two: :three: :four: :five: :six: :seven: :eight: :nine:");
	test("!?#$YAY 1234", ":regional_indicator_y: :regional_indicator_a: :regional_indicator_y: :white_large_square: :one: :two: :three: :four:");
	test("lots         of         spaces", ":regional_indicator_l: :regional_indicator_o: :regional_indicator_t: :regional_indicator_s: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :regional_indicator_o: :regional_indicator_f: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :white_large_square: :regional_indicator_s: :regional_indicator_p: :regional_indicator_a: :regional_indicator_c: :regional_indicator_e: :regional_indicator_s:");

	return 0;
}
