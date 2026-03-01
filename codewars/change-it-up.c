/*

Create a function that takes a string as a parameter and does the following, in this order:

Replaces every letter with the letter following it in the alphabet (see note below)
Makes any vowels capital
Makes any consonants lower case
Note: the alphabet should wrap around, so Z becomes A

So, for example the string "Cat30" would return "dbU30" (Cat30 --> Dbu30 --> dbU30)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
change(const char *in, char *out)
{
	int ch;

	for (; *in; in++) {
		ch = tolower(*in);
		if (!('a' <= ch && ch <= 'z'))
			*out++ = *in;
		else {
			*out = 'a' + ((ch - 'a' + 1) % 26);
			if (strchr("aeiou", *out))
				*out = toupper(*out);
			out++;
		}
	}
	*out = '\0';
}

void
test(const char *in, const char *res)
{
	char out[128];

	change(in, out);
	puts(out);
	assert(!strcmp(out, res));
}

int
main()
{
	test("Cat30", "dbU30");
	return 0;
}
