/*

The aim of this Kata is to write a function which will reverse the case of all consecutive duplicate letters in a string. That is, any letters that occur one after the other and are identical.

If the duplicate letters are lowercase then they must be set to uppercase, and if they are uppercase then they need to be changed to lowercase.

Examples:

reverseCase("puzzles")    Expected Result: "puZZles"
reverseCase("massive")    Expected Result: "maSSive"
reverseCase("LITTLE")     Expected Result: "LIttLE"
reverseCase("shhh")       Expected Result: "sHHH"

Arguments passed will include only alphabetical letters A–Z or a–z.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
revcase(const char *s, char *b)
{
	size_t i, j, n;
	char *p;
	int c;

	p = b;
	for (i = 0; s[i]; i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		n = j - i;
		c = s[i];
		if (n > 1)
			c = islower(c) ? toupper(c) : tolower(c);

		memset(p, c, n);
		p += n;
	}
	*p = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	revcase(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("puzzles", "puZZles");
	test("massive", "maSSive");
	test("LITTLE", "LIttLE");
	test("shhh", "sHHH");
	test("", "");
	test("l", "l");

	return 0;
}
