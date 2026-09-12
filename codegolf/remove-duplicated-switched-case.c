/*

Goal
The goal of this challenge is: given a string as input, remove duplicate pairs of letters, if the second item in the pair is of opposite capitalization. (i.e. uppercase becomes lowercase and vice-versa).

Pairs should be replaced from left to right. For example, aAa should become aa and not aA.

https://i.sstatic.net/8NhxA.png

Inputs & outputs:
Input:         Output:
bBaAdD         bad
NniIcCeE       Nice
Tt eE Ss tT    T e S t
sS Ee tT       s E t
1!1!1sStT!     1!1!1st!
nN00bB         n00b
(eE.gG.)       (e.g.)
Hh3lL|@!       H3l|@!
Aaa            Aa
aaaaa          aaaaa
aaAaa          aaaa
The input consists of printable ASCII symbols.

You shouldn't remove duplicated digits or other non-letter characters.

Acknowledgement
This challenge is the opposite of @nicael 's "Duplicate & switch case". Can you reverse it?

Thank you for all contributors from the sandbox!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
rdsc(char *buf)
{
	char *ptr;

	for (ptr = buf; *buf; buf++) {
		if (tolower(buf[0]) != tolower(buf[1]) || buf[0] == buf[1])
			*ptr++ = *buf;
		else
			*ptr++ = *buf++;
	}
	*ptr = '\0';
}

void
test(const char *str, const char *res)
{
	char buf[128];

	strcpy(buf, str);
	rdsc(buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test("bBaAdD", "bad");
	test("NniIcCeE", "Nice");
	test("Tt eE Ss tT", "T e S t");
	test("sS Ee tT", "s E t");
	test("1!1!1sStT!", "1!1!1st!");
	test("nN00bB", "n00b");
	test("(eE.gG.)", "(e.g.)");
	test("Hh3lL|@!", "H3l|@!");
	test("Aaa", "Aa");
	test("aaaaa", "aaaaa");
	test("aaAaa", "aaaa");

	return 0;
}
