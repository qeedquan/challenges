/*

Description

Password security is a tricky thing. Users prefer simple passwords that are easy to remember (like buddy), but such passwords are often insecure. Some sites use random computer-generated passwords (like xvtpzyo), but users have a hard time remembering them and sometimes leave them written on notes stuck to their computer. One potential solution is to generate "pronounceable" passwords that are relatively secure but still easy to remember.

FnordCom is developing such a password generator. You work in the quality control department, and it's your job to test the generator and make sure that the passwords are acceptable. To be acceptable, a password must satisfy these three rules:

It must contain at least one vowel.

It cannot contain three consecutive vowels or three consecutive consonants.

It cannot contain two consecutive occurrences of the same letter, except for 'ee' or 'oo'.

(For the purposes of this problem, the vowels are 'a', 'e', 'i', 'o', and 'u'; all other letters are consonants.) Note that these rules are not perfect; there are many common/pronounceable words that are not acceptable.

Input

The input consists of one or more potential passwords, one per line, followed by a line containing only the word 'end' that signals the end of the file. Each password is at least one and at most twenty letters long and consists only of lowercase letters.

Output

For each password, output whether or not it is acceptable, using the precise format shown in the example.

Sample Input

a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end

Sample Output

<a> is acceptable.
<tv> is not acceptable.
<ptoui> is not acceptable.
<bontres> is not acceptable.
<zoggax> is not acceptable.
<wiinq> is not acceptable.
<eep> is acceptable.
<houctuh> is acceptable.

Source

Mid-Central USA 2000

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

int
valid2(const char *s)
{
	if (!s[0] || !s[1] || s[0] != s[1])
		return 1;
	return (s[0] == 'e' || s[1] == 'o');
}

int
valid3(const char *s)
{
	int c;

	if (!s[0] || !s[1] || !s[2])
		return 1;

	c = isvowel(s[0]);
	c += isvowel(s[1]);
	c += isvowel(s[2]);
	return (c != 0 && c != 3);
}

char *
acceptable(const char *s, char *b)
{
	size_t i;
	int f;

	f = 0;
	for (i = 0; s[i]; i++) {
		f |= isvowel(s[i]);
		if (!valid2(s + i) || !valid3(s + i)) {
			f = 0;
			break;
		}
	}

	if (f == 0)
		sprintf(b, "<%s> is not acceptable.", s);
	else
		sprintf(b, "<%s> is acceptable.", s);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	acceptable(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("a", "<a> is acceptable.");
	test("tv", "<tv> is not acceptable.");
	test("ptoui", "<ptoui> is not acceptable.");
	test("bontres", "<bontres> is not acceptable.");
	test("zoggax", "<zoggax> is not acceptable.");
	test("wiinq", "<wiinq> is not acceptable.");
	test("eep", "<eep> is acceptable.");
	test("houctuh", "<houctuh> is acceptable.");

	return 0;
}
