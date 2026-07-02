/*

Third day at your new cryptoanalyst job and you come across your toughest assignment yet. Your job is to implement a simple keyword cipher. A keyword cipher is a type of monoalphabetic substitution where two parameters are provided as such (string, keyword). The string is encrypted by taking the keyword, dropping any letters that appear more than once. The rest of the letters of the alphabet that aren't used are then appended to the end of the keyword.

For example, if your string was "hello" and your keyword was "wednesday", your encryption key would be 'wednsaybcfghijklmopqrtuvxz'.

To encrypt 'hello' you'd substitute as follows,

              abcdefghijklmnopqrstuvwxyz
  hello ==>   |||||||||||||||||||||||||| ==> bshhk
              wednsaybcfghijklmopqrtuvxz

hello encrypts into bshhk with the keyword wednesday. This cipher also uses lower case letters only.

Good Luck.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
isletter(int c)
{
	return 'a' <= c && c <= 'z';
}

void
encrypt(const char *src, const char *key, char *dst)
{
	char map[26];
	char seen[26];
	size_t i;
	int c;

	memset(seen, 0, sizeof(seen));

	for (i = 0; *key && i < sizeof(map); key++) {
		if (!isletter(*key))
			continue;

		c = *key - 'a';
		if (!seen[c]) {
			map[i++] = *key;
			seen[c] = 1;
		}
	}

	for (c = 'a'; i < sizeof(map); i++) {
		while (seen[c - 'a'])
			c++;
		map[i] = c++;
	}

	while (*src) {
		if (isletter(*src))
			*dst++ = map[*src++ - 'a'];
		else
			*dst++ = *src++;
	}
	*dst = '\0';
}

void
test(const char *src, const char *key, const char *expected)
{
	char dst[128];

	encrypt(src, key, dst);
	puts(dst);
	assert(!strcmp(dst, expected));
}

int
main()
{
	test("hello", "wednesday", "bshhk");

	return 0;
}
