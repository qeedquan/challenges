/*

Imagine a book author has hired us to create a function that takes his book as a string as input and finds all instances of a letter that we will call 'x' (case-sensitive) and turns all the letters after 'x' into a capital letter.

For example.

makeEveryLetterAfterXCaps('and larry walked into the park late to chase a squirrel', 'l')

Should return:

"and lArry walKed into the park lAte to chase a squirrel"

If the letter after x is already in caps it should stay in caps.

Note that the swapping occurs considering the modified string, so makeEveryLetterAfterXCaps('aaaa', 'a') will result into "aAaA"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
xcaps(const char *string, int letter, char *output)
{
	while (*string) {
		if (letter == *string) {
			*output++ = *string++;
			if (*string)
				*output++ = toupper(*string++);
		} else
			*output++ = *string++;
	}
	*output = '\0';
}

void
test(const char *string, int letter, const char *expected)
{
	char output[128];

	xcaps(string, letter, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("and larry walked into the park late to chase a squirrel", 'l', "and lArry walKed into the park lAte to chase a squirrel");
	test("aaaa", 'a', "aAaA");

	return 0;
}
