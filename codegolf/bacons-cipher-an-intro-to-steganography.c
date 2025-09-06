/*

This little piggy went to market, this little piggy wrote some code...

Ah wait, we're not talking about that bacon, we're talking about Sir Francis Bacon! Specifically, the cipher Bacon devised in the late 1500s, as a method of hiding a message within another message, a method of steganography.

The cipher works by concealing the message in the presentation of text, rather than its content. First, the letters of your message are encoded into binary (from 0 to 25) as follows:

Note: Please use the following encoding in your code and do not worry about numbers, spaces, or other symbols in the input, though I may devise some bonus for those who include these characters in their encoding. If you do include other symbols, the letters must still occupy spaces 0-25 in the encoding.

Letter  Encoding
A       AAAAA
B       AAAAB
C       AAABA
D       AAABB
E       AABAA
F       AABAB
G       AABBA
H       AABBB
I       ABAAA
J       ABAAB
K       ABABA
L       ABABB
M       ABBAA
N       ABBAB
O       ABBBA
P       ABBBB
Q       BAAAA
R       BAAAB
S       BAABA
T       BAABB
U       BABAA
V       BABAB
W       BABBA
X       BABBB
Y       BBAAA
Z       BBAAB
Having encoded all of the letters in your message into the As and Bs above, you must now select two typefaces for your code. For this example, I will use normal text for typeface A and bold text for typeface B.

So the message

HELLOWORLD
is encoded to

AABBB AABAA ABABB ABABB ABBBA BABBA ABBBA BAAAB ABABB AAABB
And now we conceal this binary with a carrier text.

The quick brown fox jumps over the lazy dogs, gamboling in the fields where the shepherds keep watch.

It is alright if the carrier message is longer than the actual encoded message, though it cannot be shorter. Now we turn the carrier text into bold according to where the Bs are in the encoded message,

The quick brown fox jumps over the lazy dogs, gamboling in the fields where the shepherds keeps watch.

Which without Markdown reads as

Th**e** **qu**ic**k** bro**w**n **fo**x **j**u**mp**s **ove**r **t**h**e** **l**az**y**
**do**g**s**, gam**b**o**l**i**ng** in t**he** fields where the shepherds keeps watch.
Note that I did not use the punctuation in the carrier message to encode the message, but whether the punctuation is encoded or not is up to you/.

Rules

Your input will be the message you to be encoded and a carrier message. If the carrier message is too short, return some sort of error message.

You must select two typefaces for encoding A and B, such as UPPERCASE, lowercase, italic, bold, bold italic, strikethrough, in code format and so on. You must use Stack Exchange's form of Markdown to encode these typefaces, i.e.

UPPERCASE, lowercase, *italic*, **bold**,
***bold italic***, <s>strikethrough</s>, `in code format`
Your output must be your now-encoded carrier message, either shown with Markdown or shown without, as seen in the above example.

You are only required to make an encoding algorithm. Any decoding algorithms you wish to provide are welcome, but at time of writing will not help or hinder your score.

Your code must be a program or a function.

This is code golf, so the smallest number of bytes wins.

As always, if the problem is unclear, please let me know. Good luck and good golfing!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
bacon(const char *s, const char *p, char *b)
{
	char *h;
	int m;

	m = 16;
	strcpy(b, p);
	for (h = b; *b; b++) {
		if (isalpha(*b)) {
			*b |= 32;
			*b -= ((*s - 1) & m) ? 32 : 0;
			m >>= 1;
			if (!m) {
				m = 16;
				s += !!*s;
			}
		}
	}

	return h;
}

void
test(const char *s, const char *p, const char *r)
{
	char b[128];

	bacon(s, p, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("HELLOWORLD", "The quick brown fox jumps over the lazy dogs, gamboling in the fields where the shepherds keep watch.", "thE QUicK broWn FOx JuMPs OVEr ThE LazY DOgS, gamBoLiNG in tHE FIELDS WHERE THE SHEPHERDS KEEP WATCH.");

	return 0;
}
