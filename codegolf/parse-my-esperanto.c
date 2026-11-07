/*

The famous constructed language Esperanto uses the Latin alphabet (mostly, see the linked wikipedia page for details). However, there are some characters with accents: ĉ, ĝ, ĥ, ĵ, ŝ, and ŭ. (C-circumflex, g-circumflex, h-circumflex, j-circumflex, s-circumflex, and u-breve.) Naturally, these characters are very hard to type. Even for this question, I had to search in the Unicode selector for the characters. Due to this, a convention using the letter "x" has been developed for electronic use. For example, "cxu" is used for "ĉu". (Note: the letter "x" is not used normally in the Esperanto alphabet."

However, I am a language purist! This *air quote* x nonsense is killing me! I need a program to fix this, preferably as short as possible so I can type it into my terminal as fast as possible!

Challenge
Your mission is to take a string of Esperanto using x-convention and convert it to real Esperanto.

In effect, you have to map:

cx: ĉ
gx: ĝ
hx: ĥ
jx: ĵ
sx: ŝ
ux: ŭ
Cx: Ĉ
Gx: Ĝ
Hx: Ĥ
Jx: Ĵ
Sx: Ŝ
Ux: Ŭ
All other printable ASCII characters should be accepted and not changed. Unicode would be nice, but not necessary.

Input and output can be in any format reasonable to your language. Good luck!

Testcases
"input" : "output"
_____________
"gxi estas varma" : "ĝi estas varma"
"Cxu sxi sxatas katojn aux hundojn?" : "Ĉu ŝi ŝatas katojn aŭ hundojn?"
"Uxcxsxabcd(hxSx)efg{};" : "Ŭĉŝabcd(ĥŜ)efg{};"
"qwertyuiop" : "qwertyuiop"
" " : " "
"" : ""
"x" : "x"
"xc" : "xc"
"xcx" : "xĉ"
"cxx" : "ĉx"
Scoring
This is code-golf. Answers are scored by smallest bytecount in the language's default encoding.

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes
where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes
If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes
You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes
Show code snippet

Good luck, have fun, and feel free to suggest improvements!

Clarifications:
You only need to worry about printable ASCII characters.

You only need to output a character that looks like the correct output. Yes, this means you can tack the accent onto the standard character.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <uchar.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
esperanto(const char *s, char *b)
{
	static const struct Sym {
		char from[3];
		char8_t to[4];
	} syms[] = {
	    {"cx", u8"ĉ"},
	    {"gx", u8"ĝ"},
	    {"hx", u8"ĥ"},
	    {"jx", u8"ĵ"},
	    {"sx", u8"ŝ"},
	    {"ux", u8"ŭ"},
	    {"Cx", u8"Ĉ"},
	    {"Gx", u8"Ĝ"},
	    {"Hx", u8"Ĥ"},
	    {"Jx", u8"Ĵ"},
	    {"Sx", u8"Ŝ"},
	    {"Ux", u8"Ŭ"},
	};

	const struct Sym *p;
	size_t i, l, n;

	*b = '\0';
	for (i = l = 0; s[i]; i++) {
		for (n = 0; n < nelem(syms); n++) {
			p = syms + n;
			if (!strncmp(s + i, p->from, sizeof(p->from) - 1)) {
				i += sizeof(p->from) - 2;
				break;
			}
		}

		if (n < nelem(syms))
			l += sprintf(b + l, "%s", p->to);
		else
			l += sprintf(b + l, "%c", s[i]);
	}

	return l;
}

void
test(const char *s, const void *r)
{
	char b[128];

	esperanto(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("gxi estas varma", u8"ĝi estas varma");
	test("Cxu sxi sxatas katojn aux hundojn?", u8"Ĉu ŝi ŝatas katojn aŭ hundojn?");
	test("Uxcxsxabcd(hxSx)efg{};", u8"Ŭĉŝabcd(ĥŜ)efg{};");
	test("qwertyuiop", u8"qwertyuiop");
	test(" ", u8" ");
	test("", u8"");
	test("x", u8"x");
	test("xc", u8"xc");
	test("xcx", u8"xĉ");
	test("cxx", u8"ĉx");

	return 0;
}
