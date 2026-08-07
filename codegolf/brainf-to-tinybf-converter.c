/*

You don't need to know these languages to participate. All necessary information has been provided in this question.

You should write a program or function which given a brainfuck (BF) code as input outputs its tinyBF equivalent.

BF has 8 instructions characters: +-><[],. and tinyBF has 4: =+>|. Converting works the following way: starting from the beginning of the BF code each symbol is replaced by on of its two tinyBF counterparts based on the number of = signs in the tinyBF code until that point (i.e. = behaves like a toggle switch).

The converter table (with columns: Brainfuck symbol; tinyBF symbol(s) when ther are even ='s before; tinyBF symbol(s) when ther are odd ='s before):

BF   even    odd

+      +      =+
-     =+       +
>      >      =>
<     =>       >
[      |      =|
]     =|       |
.     ==      ==
,    |=|    =|=|
(This creates an almost unique tinyBF code. The only conflict occurs if the BF code contains a [] which is generally unused as it creates an infinite void loop.)

Input
An at least 1 byte long valid brainfuck program containing only the characters +-><[],.
Guaranteed not to contain the string []
Trailing newline is optional.
Output
A tinyBF program.
Trailing newline is optional.
Examples
You can convert any BF program to tinyBF with this (1440 byte long) converter (see the Edit section for a small deviation).

Format is Input into Output

++-  into  ++=+
,[.,]  into  |=||==|=|=| or |=|=|==|=|| (both is acceptable check the Edit section)
>++.--.[<]+-,  into  >++===++===|=>|=+=+=|=|
>++-+++++++[<+++++++++>-]<.  into  >++=+=+++++++|=>=+++++++++>=+|>==

Edit
As @Jakube pointed out in the official tinyBF converter in the equivalents of the , BF instruction (|=| and =|=|) the last = signs aren't counted towards the toggle state. Both the official and mine interpretations are acceptable but you have to choose one.

This is code-golf so the shortest entry wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
bf2tinybf(const char *s, char *b)
{
	static const struct Conv {
		const char *even;
		const char *odd;
	} tab[256] = {
	    ['+'] = {"+", "=+"},
	    ['-'] = {"=+", "+"},
	    ['>'] = {">", "=>"},
	    ['<'] = {"=>", ">"},
	    ['['] = {"|", "=|"},
	    [']'] = {"=|", "|"},
	    ['.'] = {"==", "=="},
	    [','] = {"|=|", "=|=|"},
	};

	const struct Conv *c;
	const char *p;
	size_t i, j, k;
	int t;

	t = 0;
	for (i = j = 0; s[i]; i++) {
		c = tab + (s[i] & 0xff);
		p = (t & 1) ? c->odd : c->even;
		if (!p)
			continue;

		for (k = 0; p[k]; k++) {
			b[j++] = p[k];
			if (p[k] == '=')
				t ^= 1;
		}
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	bf2tinybf(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("++-", "++=+");
	test(",[.,]", "|=|=|==|=||");
	test(">++.--.[<]+-,", ">++===++===|=>|=+=+=|=|");
	test(">++-+++++++[<+++++++++>-]<.", ">++=+=+++++++|=>=+++++++++>=+|>==");

	return 0;
}
