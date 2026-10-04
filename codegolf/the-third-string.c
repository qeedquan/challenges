/*

Given two strings, output a third string that is not equal to either of the two inputs, but has the same length (in characters) as either of the inputs. There is guaranteed to be at least one valid output.

Test Cases
Test cases are quoted to show they are strings. Outputs are one of many possible.

input, input -> output

"test", "test" -> "tttt"
"do", "don't" -> "dnut_"
"ye s", "yes" -> "fals"
"yes", "yes" -> "noo"
"maybe", "mayue" -> "false"
"false", "false" -> "truee"
"false", "true" -> "fatr"
"1", "" -> "0"
"", "t" -> "s"
"", "abcabc" -> "testst"
"abcdefghijklmnopqrstuvwxyz", "aaaaaaaaaaaaaaaaaaaaaaaaaa" -> "zbcdefghijklmnopqrstuvwxya"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" -> "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"
Rules
You may chose your input domain, but it must be composed of at least printable ASCII, and your output domain must be the same as your input domain.
The input lengths may be the same or different.
The output must be valid with probability 1; that is, you may generate random strings until one is valid (and theoretically you might infinite loop), but you can't just output a random string and hope it's valid. Note that this means you output does not need to be deterministic.
Automatic trailing newlines allowed, but they do not count towards the length of the output.
Due to questions regarding Memory Errors, it must work within 60 seconds up to input lengths of 6. An answer that works for that and theoretically works for longer strings is OK, but something that Memory Errors on modern computer for input length 4 is not valid.
This is code-golf, so shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char *
third(const char *s, const char *t, char *b)
{
	size_t i, j, k;

	for (i = j = k = 0; s[i] || t[j]; k++) {
		do {
			b[k] = rand() & 0xff;
		} while (!isprint(b[k]) || b[k] == s[i] || b[k] == t[j]);

		if (s[i])
			i++;
		if (t[j])
			j++;
	}
	b[k] = '\0';

	return b;
}

void
test(const char *s, const char *t)
{
	char b[512];

	third(s, t, b);
	printf("%s\n", b);
	assert(strcmp(b, s));
	assert(strcmp(b, t));
}

int
main()
{
	srand(time(NULL));

	test("test", "test");
	test("do", "don't");
	test("ye s", "yes");
	test("yes", "yes");
	test("maybe", "mayue");
	test("false", "false");
	test("false", "true");
	test("1", "");
	test("", "t");
	test("", "abcabc");
	test("abcdefghijklmnopqrstuvwxyz", "aaaaaaaaaaaaaaaaaaaaaaaaaa");
	test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");

	return 0;
}
