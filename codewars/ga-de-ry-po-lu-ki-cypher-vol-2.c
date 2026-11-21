/*

Introduction
The GADERYPOLUKI is a simple substitution cypher used in scouting to encrypt messages. The encryption is based on short, easy to remember key. The key is written as paired letters, which are in the cipher simple replacement.

The most frequently used key is "GA-DE-RY-PO-LU-KI".

 G => A
 g => a
 a => g
 A => G
 D => E
  etc.
The letters, which are not on the list of substitutes, stays in the encrypted text without changes.

Other keys often used by Scouts:

PO-LI-TY-KA-RE-NU
KA-CE-MI-NU-TO-WY
KO-NI-EC-MA-TU-RY
ZA-RE-WY-BU-HO-KI
BA-WO-LE-TY-KI-JU
RE-GU-LA-MI-NO-WY
Task
Your task is to help scouts to encrypt and decrypt thier messages. Write the Encode and Decode functions.

Input/Output
The function should have two parameters.
The message input string consists of lowercase and uperrcase characters and whitespace character.
The key input string consists of only lowercase characters.
The substitution has to be case-sensitive.

Example
 encode("ABCD", "agedyropulik");             // => GBCE
 encode("Ala has a cat", "gaderypoluki");    // => Gug hgs g cgt
 decode("Dkucr pu yhr ykbir","politykarenu") // => Dance on the table
 decode("Hmdr nge brres","regulaminowy")  // => Hide our beers

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
makemap(const char *key, char map[256])
{
	int c0, c1, c2, c3;

	for (c0 = 0; c0 < 256; c0++)
		map[c0] = c0 & 0xff;

	for (; key[0] && key[1]; key += 2) {
		c0 = tolower(key[0]);
		c1 = tolower(key[1]);
		c2 = toupper(c0);
		c3 = toupper(c1);

		map[c0] = c1;
		map[c1] = c0;
		map[c2] = c3;
		map[c3] = c2;
	}
}

char *
recode(const char *src, const char *key, char *dst)
{
	char map[256];
	char *ptr;

	makemap(key, map);
	for (ptr = dst; *src; src++)
		*ptr++ = map[*src & 0xff];
	*ptr = '\0';
	return dst;
}

void
test(const char *src, const char *key, const char *res)
{
	char dst[128];

	recode(src, key, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("ABCD", "agedyropulik", "GBCE");
	test("Ala has a cat", "gaderypoluki", "Gug hgs g cgt");
	test("Dkucr pu yhr ykbir", "politykarenu", "Dance on the table");
	test("Hmdr nge brres", "regulaminowy", "Hide our beers");

	return 0;
}
