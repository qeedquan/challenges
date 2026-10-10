/*

I can't think of a better name. This is similar to this challenge, but a lot easier.
https://codegolf.stackexchange.com/questions/241532/crack-the-caesar-cipher

Read three strings which contain only uppercase letters. The length of the first and second strings are the same. The second string and the third string are encrypted using Caesar cipher using the same key. The original string of the second string is the first string. You have to decrypt the third string. Obviously, there is exactly one possible original string of the third string.

Examples
AAA BBB CCC -> BBB
I U TQXXAIADXP -> HELLOWORLD
HELLO FCJJM QRPGLE -> STRING

Rule
This is code-golf, so code in the fewest bytes.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
findkey(const char *txt, const char *enc)
{
	int ch, key;
	size_t i;

	for (key = 0; key < 26; key++) {
		for (i = 0; txt[i] && enc[i]; i++) {
			ch = 'A' + ((txt[i] - 'A' + key) % 26);
			if (ch != enc[i])
				break;
		}
		if (txt[i] == '\0' && enc[i] == '\0')
			return key;
	}
	return -1;
}

void
recover(const char *enc, int key, char *buf)
{
	size_t i;

	for (i = 0; enc[i]; i++)
		buf[i] = 'A' + mod(enc[i] - 'A' - key, 26);
	buf[i] = '\0';
}

int
solve(const char *txt, const char *enc0, const char *enc1, char *buf)
{
	int key;

	key = findkey(txt, enc0);
	if (key < 0)
		return -1;

	recover(enc1, key, buf);
	return 0;
}

void
test(const char *txt, const char *enc0, const char *enc1, const char *expected)
{
	char buf[128];

	assert(solve(txt, enc0, enc1, buf) >= 0);
	printf("%s\n", buf);
	assert(!strcmp(buf, expected));
}

int
main(void)
{
	test("AAA", "BBB", "CCC", "BBB");
	test("I", "U", "TQXXAIADXP", "HELLOWORLD");
	test("HELLO", "FCJJM", "QRPGLE", "STRING");

	return 0;
}
