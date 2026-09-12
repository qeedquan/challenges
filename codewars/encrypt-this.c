/*

Description:
Encrypt this!

You want to create secret messages which can be deciphered by the Decipher this! kata. Here are the conditions:

Your message is a string containing space separated words.
You need to encrypt each word in the message using the following rules:
The first letter must be converted to its ASCII code.
The second letter must be switched with the last letter
Keepin' it simple: There are no special characters in the input.
Examples:
encryptThis("Hello") === "72olle"
encryptThis("good") === "103doo"
encryptThis("hello world") === "104olle 119drlo"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
encrypt(const char *input, char *output)
{
	size_t index;
	size_t length;
	char *buffer;

	buffer = output;

	while (isspace(*input))
		input++;

	for (;;) {
		for (length = 0; isspace(*input); length++)
			input++;
		if (length)
			*buffer++ = ' ';

		if (!*input)
			break;

		length = 0;
		while (input[length] && !isspace(input[length]))
			length++;

		buffer += sprintf(buffer, "%d", input[0]);
		if (length > 1)
			*buffer++ = input[length - 1];
		if (length > 2) {
			for (index = 2; index < length - 1; index++)
				*buffer++ = input[index];
			*buffer++ = input[1];
		}
		input += length;
	}

	while (buffer > output && buffer[-1] == ' ')
		buffer--;
	*buffer = '\0';

	return buffer;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	encrypt(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Hello", "72olle");
	test("good", "103doo");
	test("hello world", "104olle 119drlo");
	test("", "");
	test("A", "65");
	test("Ab", "65b");
	test("Abcd", "65dcb");
	test("  Abcd   Abcd", "65dcb 65dcb");
	test("Abcd Aahhhhhhhhhhhhhhhhz", "65dcb 65zhhhhhhhhhhhhhhhha");
	test(" Hello world ", "72olle 119drlo");
	test("A", "65");
	test("A wise old owl lived in an oak", "65 119esi 111dl 111lw 108dvei 105n 97n 111ka");
	test("The more he saw the less he spoke", "84eh 109ero 104e 115wa 116eh 108sse 104e 115eokp");
	test("The less he spoke the more he heard", "84eh 108sse 104e 115eokp 116eh 109ero 104e 104dare");
	test("Why can we not all be like that wise old bird", "87yh 99na 119e 110to 97ll 98e 108eki 116tah 119esi 111dl 98dri");
	test("Thank you Piotr for all your help", "84kanh 121uo 80roti 102ro 97ll 121ruo 104ple");

	return 0;
}
