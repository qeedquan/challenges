/*

This was inspired by a function I recently added to my language Add++. Therefore I will submit an short answer in Add++ but I won't accept it if it wins (it wouldn't be fair)

Don't you hate it when you can multiply numbers but not strings? So you should correct that, right?

You are to write a function or full program that takes two non-empty strings as input and output their multiplied version.

How do you multiply strings? I'll tell you!

To multiply two strings, you take two strings and compare each character. The character with the highest code point is then added to the output. If they are equal, simply add the character to the output.

Strings are not guaranteed to be equal in length. If the lengths are different, the length of the final string is the length of the shortest string. The input will always be lowercase and may contain any character in the printable ASCII range (0x20 - 0x7E), excluding uppercase letters.

You may output in any reasonable format, such as string, list etc. Be sensible, integers aren't a sensible way to output in this challenge.

With inputs of hello, and world!, this is how it works

hello,
world!

w > h so "w" is added ("w")
o > e so "o" is added ("wo")
r > l so "r" is added ("wor")
l = l so "l" is added ("worl")
d < o so "o" is added ("worlo")
! < , so "," is added ("worlo,")
So the final output for hello, and world! would be worlo,.

More test cases
(without steps)

input1
input2 => output

programming puzzles & code golf!?
not yet graduated, needs a rehaul => prtgyetmirgduuzzlesneedsde rolful

king
object => oing

blended
bold => boln

lab0ur win.
the "super bowl" => the0usuwir.

donald j.
trumfefe! => trumlefj.
This is a code-golf so shortest code wins! Luok!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char *
strmul(const char *s, const char *t, char *b)
{
	size_t i;

	for (i = 0; s[i] && t[i]; i++)
		b[i] = max(s[i], t[i]);
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	strmul(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("hello,", "world!", "worlo,");
	test("programming puzzles & code golf!?", "not yet graduated, needs a rehaul", "prtgyetmirgduuzzlesneedsde rolful");
	test("king", "object", "oing");
	test("blended", "bold", "boln");
	test("lab0ur win.", "the \"super bowl\"", "the0usuwir.");
	test("donald j.", "trumfefe!", "trumlefj.");

	return 0;
}
