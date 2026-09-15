/*

You are given a secret message you need to decipher. Here are the things you need to know to decipher it:

For each word:

the second and the last letter is switched (e.g. Hello becomes Holle)
the first letter is replaced by its character code (e.g. H becomes 72)
Note: there are no special characters used, only letters and spaces

Examples

decipherThis('72olle 103doo 100ya'); // 'Hello good day'
decipherThis('82yade 115te 103o'); // 'Ready set go'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void
swapc(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void
decipher(const char *input, char *output)
{
	char *saveptr;

	while (*input) {
		while (isspace(*input))
			*output++ = *input++;

		if (isdigit(*input)) {
			*output++ = strtol(input, &saveptr, 10);
			input = saveptr;
		}

		saveptr = output;
		while (*input && !isspace(*input))
			*output++ = *input++;
		if (output != saveptr)
			swapc(output - 1, saveptr);
	}
	*output = '\0';
}

void
test(const char *input, const char *expected)
{
	char output[128];

	decipher(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("72olle 103doo 100ya", "Hello good day");
	test("82yade 115te 103o", "Ready set go");
	test("72eva 97 103o 97t 116sih 97dn 115ee 104wo 121uo 100o", "Have a go at this and see how you do");
	test("65 119esi 111dl 111lw 108dvei 105n 97n 111ka", "A wise old owl lived in an oak");
	test("84eh 109ero 104e 115wa 116eh 108sse 104e 115eokp", "The more he saw the less he spoke");
	test("84eh 108sse 104e 115eokp 116eh 109ero 104e 104dare", "The less he spoke the more he heard");
	test("87yh 99na 119e 110to 97ll 98e 108eki 116tah 119esi 111dl 98dri", "Why can we not all be like that wise old bird");
	test("84kanh 121uo 80roti 102ro 97ll 121ruo 104ple", "Thank you Piotr for all your help");
	test("", "");

	return 0;
}
