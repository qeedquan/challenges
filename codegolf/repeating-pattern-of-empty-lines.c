/*

Write the shortest program or function that takes some text as input, and outputs either it or an empty line in a repeating pattern:

some text
some text

some text
some text

some text
some text

...
This must continue indefinitely, or until some unpreventable limitation occurs (stack size, memory, etc.). It must be newline separated, and you can assume the inputted text is made up of non-newline printable ASCII characters. Note that it doesn't have to follow the pattern text-text-empty, and text-empty-text would be equally valid.

The ratio of text lines and empty lines will also be specified by input. There are various ways you can do this (though you only need to support one):

A fraction represented as a floating point number (this can represent the fraction which do OR do not have text in them, but it must be consistent)
A ratio of lines with text to lines without (represented as two integer inputs)
A fraction of lines which do OR do not have text in them (represented as an integer numerator and denominator)
Example:

Text: Hello, world!
Ratio: 2:3

Hello, world!
Hello, world!



Hello, world!
Hello, world!



...
Text: fraction
Fraction: 1/3

fraction


fraction


fraction


...
Text: decimal decimal decimal
Input: 0.6

decimal decimal decimal
decimal decimal decimal
decimal decimal decimal


decimal decimal decimal
decimal decimal decimal
decimal decimal decimal


...
Text: example with a different pattern Fraction: 2/5

example with a different pattern

example with a different pattern


example with a different pattern

example with a different pattern


...
This is code golf, so the shortest answer in bytes, per language, wins.

*/

#include <stdio.h>

void
pattern(const char *s, int a, int b)
{
	int i;

	for (;;) {
		for (i = 0; i < a; i++)
			puts(s);
		for (i = 0; i < b; i++)
			puts("");
	}
}

int
main()
{
	pattern("Hello, world!", 2, 3);
	return 0;
}
