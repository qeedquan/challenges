/*

Your job is to simulate a couple of keystrokes that a user types in.

Input

A string array or string with a delimiter of your choice (outside the range 32-126) containing at least one 'keystroke'.

This array will only contain two types of string: passive keystrokes (single chars) and commands (chars within brackets [ ]).

Passive keystrokes
ASCII character codes [32-126]
Commands:
[B] : backspace (remove last character added if there is one)
[C] : copy all of what has already been written
[D] : delete all of what has been written
[P] : paste what has been copied
Output

The string produced by the keystrokes.

Examples

['H', 'e', 'l', 'l', 'o'] -> 'Hello'
['H', 'e', 'l', 'l', 'o', ' ', '[C]', '[P]'] -> 'Hello Hello '
['[D]', 'D', '[B]'] -> ''
['H', '[C]', 'i', '[P]', '[C]', '[P]'] -> 'HiHHiH'
['e', '[C]', '[B]', 'I', ' ', 'l', 'i', 'k', '[P]', ' ', 'b', '[P]', '[P]', 's', '!'] -> I like bees!
['N', '[P]'] -> 'N'
['#', '5', '0', 'K', '0', '0', '1', '[D]', '#', 'n', 'o', 't'] -> '#not'
['H', 'o', 'w', ' ', '[D]', 'H', 'e', 'y'] -> 'Hey'
['s', 'u', 'd', '[B]', 'p', '[C]', '[D]', 'I', ' ' , 'h', 'a', 'v', 'e', ' ', '[P]', 'p', 'e', 'r', '!'] -> 'I have supper!'

This is code-golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
keystrokes(const char *s, char *b, char *t)
{
	size_t i, j, n;

	for (i = j = n = 0; s[i];) {
		if (!strncmp(s + i, "[B]", 3)) {
			if (j > 0)
				j--;
		} else if (!strncmp(s + i, "[C]", 3)) {
			memcpy(t, b, j);
			n = j;
		} else if (!strncmp(s + i, "[D]", 3)) {
			j = 0;
		} else if (!strncmp(s + i, "[P]", 3)) {
			memcpy(b + j, t, n);
			j += n;
		} else {
			b[j++] = s[i++];
			continue;
		}

		i += 3;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], t[128];

	keystrokes(s, b, t);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello", "Hello");
	test("Hello [C][P]", "Hello Hello ");
	test("[D]D[B]", "");
	test("H[C]i[P][C][P]", "HiHHiH");
	test("e[C][B]I lik[P] b[P][P]s!", "I like bees!");
	test("N[P]", "N");
	test("#50K001[D]#not", "#not");
	test("How [D]Hey", "Hey");
	test("sud[B]p[C][D]I have [P]per!", "I have supper!");
	test("AA[C][P][C][P][C][P]", "AAAAAAAAAAAAAAAA");
	test("KZLKF", "KZLKF");

	return 0;
}
