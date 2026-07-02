/*

Find the number of sentences in the text. Consider a sentence ending with one of the characters '.' (point), '!' (exclamation point) or '?' (question mark),
but there are no character sets like "...", "!!!" and "?!" in the text.

Input
One line of text that consists of Latin characters, punctuation marks and spaces. Line contains no more than 200 symbols.

Output
Print the number of sentences in the text.

Examples

Input #1
Hello, world!

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>

size_t
count(const char *s)
{
	size_t c;

	for (c = 0; *s; s++) {
		switch (*s) {
		case '.':
		case '!':
		case '?':
			c += 1;
			break;
		}
	}
	return c;
}

int
main()
{
	assert(count("Hello, world!") == 1);

	return 0;
}
