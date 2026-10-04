/*

This challenge courtesy of user nagasgura

In this challenge, we read in a string from standard input and output the translation to or from morse code on standard output.

When translating to Morse code, one space should be used to separate morse code letters, and two spaces should be used to separate morse code words. When translating to English, there should only be one space in between words, and no spaces in between letters.

Here's a chart of the morse code symbols: [1] http://www.w1wc.com/pdf_files/international_morse_code.pdf

Example input and output: 'sos' -> '... --- ...' '... --- ...' -> 'sos'

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char letters[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
	'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	',', '.', ' '
};

const char *code[] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
	".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
	"--..", ".----", "..---", "...--", "....-", ".....", "-....",
	"--...", "---..", "----.", "-----", ".-.-.-", "--..--", ""
};

void
reads(char *buf, size_t size)
{
	size_t i;
	int c;

	i = 0;
	while (!feof(stdin)) {
		c = getchar();
		if (isspace(c))
			break;
		if (i + 1 >= size)
			break;
		buf[i++] = c;
	}
	buf[i] = '\0';
}

void
encode()
{
	size_t i;
	int c;

	while (!feof(stdin)) {
		c = tolower(getchar());
		for (i = 0; i < nelem(letters); i++) {
			if (c == letters[i]) {
				printf("%s ", code[i]);
				break;
			}
		}
	}
	putchar('\n');
}

void
decode()
{
	char buf[8];
	size_t i;

	while (!feof(stdin)) {
		reads(buf, sizeof(buf));
		for (i = 0; i < nelem(code); i++) {
			if (!strcmp(buf, code[i])) {
				putchar(letters[i]);
				break;
			}
		}
	}
	putchar('\n');
}

int
main(int argc, char **argv)
{
	if (argc > 1 && !strcmp(argv[1], "-d"))
		decode();
	else
		encode();

	return 0;
}
