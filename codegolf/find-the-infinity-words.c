/*

(Note: This is a spin-off of my previous challenge Find the Swirling Words!)

Definition of Infinity Word:
If you connect with curves all the characters of an Infinity Word on the alphabet (A-Z) you obtain the infinity symbol ∞ like in the diagrams below.
All the even connection must be down, all the odd connections must be up.
You can ignore upper/lowercase or consider/convert all to upper case or all to lower case.
The input words are only characters in the alphabet range of A-Z, no spaces, no punctuation, or symbols.
Each word must be exactly 5 characters. Words > 5 or < 5 are not valid.
If a word has double consecutive characters, the word is not valid, like "FLOOD" or "QUEEN".
All the Infinity Words start and end with the same character.

Here there are some examples:
https://i.stack.imgur.com/IAeGj.gif

Task:
Write a full program or function that will take a word from standard input and will output if is an Infinity Word or not. The output can be true/false, 1/0, 1/Null, etc.

Test cases:

Infinity Words:
ALPHA, EAGLE, HARSH, NINON, PINUP, RULER, THEFT, WIDOW

NOT Infinity Words:
CUBIC, ERASE, FLUFF, LABEL, MODEM, RADAR, RIVER, SWISS, TRUST,
KNEES, QUEEN, GROOVE, ONLY, CHARACTER, OFF, IT, ORTHO

Rules:
Shortest code wins.
Optional Task:
Find, as a list, as many Infinity Words as you can in an English dictionary. You can take for example as reference the complete list of English words here.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sign(int x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

/*

@Jonathan Allan

How?
An infinity word has:

the same first and last letter;
length 5;
no equal letters next to each other;
sum of its four alphabet deltas equal to zero;
sum of its four alphabet deltas signs equal to zero;
two positive alphabet deltas or two negative alphabet deltas in a row.
All but (1) and (equivalently) (4) may be boiled down to a condition that the alphabet delta signs are some rotation of [1,1,-1,-1] (where the sign of 0 is 0)

fireflame241 noted that this is then equivalent to the deltas of the deltas of the alphabet delta signs being in [[2,2],[2,-2],[-2,2],[-2,-2]] which may be tested by the absolute values being equal to [2,2]!

*/

bool
infword(const char *s)
{
	static const int sig[] = {1, 1, -1, -1};

	size_t i, j, n;
	int d[4], v;

	n = nelem(d);
	v = 0;
	for (i = 0; s[i] && s[i + 1]; i++) {
		if (i >= n)
			return false;

		d[i] = sign(s[i + 1] - s[i]);
		v += s[i + 1] - s[i];
	}

	if (i != n || s[0] != s[n] || v)
		return false;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (d[(i + j) % n] != sig[j])
				break;
		}
		if (j == n)
			return true;
	}

	return false;
}

int
main(void)
{
	static const char *truthy[] = {"ALPHA", "EAGLE", "HARSH", "NINON", "PINUP", "RULER", "THEFT", "WIDOW"};
	static const char *falsy[] = {"CUBIC", "ERASE", "FLUFF", "LABEL", "MODEM", "RADAR", "RIVER", "SWISS", "TRUST", "KNEES", "QUEEN", "GROOVE", "ONLY", "CHARACTER", "OFF", "IT", "ORTHO"};

	size_t i;

	for (i = 0; i < nelem(truthy); i++)
		assert(infword(truthy[i]) == true);

	for (i = 0; i < nelem(falsy); i++)
		assert(infword(falsy[i]) == false);

	return 0;
}
