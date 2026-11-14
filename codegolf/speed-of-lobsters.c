/*

From the subreddit r/SpeedOfLobsters:

Edit the text of an image to create a new phrase

This meme format/style is pretty self-explanatory. Simply have a browse through the subreddit if you need more examples. However, when coming up with ideas, it can be quite difficult to decide exactly which letters to keep and which to blank out to create my intended joke.

You are to take a sentence of space separated "words" (i.e. non-empty alphabetical strings) and a target "word" (still a non-empty alphabetical string) and "blank out" characters from the sentence in order to make the target word. For example:

"I do not control the speed at which lobsters die", "code" -> "*********co**************d***************e******"
Note that the order of the target word is maintained, so **do*****c*********e**************************** is not an acceptable output. Earlier occurrences take priority, so "testcase string", "tas" should be t****as******** not t****a***s******

You may input and output in any convenient method. You may use either uppercase or lowercase, so long as it is consistent across all inputs. You may use any character that will not appear in the input (i.e any non-alphabetic character, or characters of the opposite case to the input) to "blank out" characters.

The target word is guaranteed to be fully contained in the sentence (so "abcdef", "xyz" will never be an input) and will always be shorter than the sentence. The sentence will contain a minimum of two words (and therefore one space), each of which will be a minimum of 1 character long.

This is code-golf so the shortest code in bytes wins.

Test cases
sentence
target
output

I do not control the speed at which lobsters die
code
*********co**************d***************e******

testcase string
tas
t****as********

uglhwagp qvyntzmf
ulhwagpqvyntzmf
u*lhwagp*qvyntzmf


qrkacxx wwfja jsyjdffa vwfgxf
qcfvf
q***c*****f************v*f***


z wzsgovhh jopw igcx muxj xmmisxdn t lmb
gcujxlb
*****g************c***u*j*x**********l*b


kxf jgmzejypb ya
e
********e*******


fe oxyk y
ex
*e**x****


o wr fmik
owrfmik
o*wr*fmik


pgezt yozcyqq drxt gcvaj hx l ix xemimmox
e
**e**************************************


kqclk b hkgtrh
k
k*************


sia prcrdfckg otqwvdv wzdqxvqb h xclxmaj xjdwt lzfw
crwqqhxl
******cr*********w*******q**q**h*x*l***************

teatsase
tas
t*a*s***
Thanks to Lyxal for helping me adapt the original idea of this into this version

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
lobsters(const char *s, const char *t, char *b)
{
	for (; *s; s++) {
		if (*s != *t)
			*b++ = '*';
		else
			*b++ = *t++;
	}
	*b = '\0';
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	strcpy(b, s);
	lobsters(s, t, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("I do not control the speed at which lobsters die", "code", "*********co**************d***************e******");
	test("kxf jgmzejypb ya", "e", "********e*******");
	test("fe oxyk y", "ex", "*e**x****");
	test("o wr fmik", "owrfmik", "o*wr*fmik");
	test("pgezt yozcyqq drxt gcvaj hx l ix xemimmox", "e", "**e**************************************");
	test("kqclk b hkgtrh", "k", "k*************");
	test("sia prcrdfckg otqwvdv wzdqxvqb h xclxmaj xjdwt lzfw", "crwqqhxl", "******cr*********w*******q**q**h*x*l***************");
	test("teatsase", "tas", "t*a*s***");

	return 0;
}
