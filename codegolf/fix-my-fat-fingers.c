/*

Code Golf Challenge
I have an isdue, my fingrrs are fat and I freqintly jave an isdue of ty[ing one keystrpke to the right on my kryboard.

I'm afraid the isdue is getyng worse anf worsr as time goes on.

Sopn every keystrpke I make wil; be shiftrd pne to the right!

Befpre then I'd like a program (or functipn) to autp shift every keystrpke back to the left one.

I'll make sure to take my tome typong the rest of tjis chal;enge so as not to cause anu confudion!

Objective:
Write a program or function that takes an input of one of the following green keys on a standard QWERTY keyboard and returns the character of the key one to the left of it.

https://i.stack.imgur.com/x4ImR.jpg

Conditions:
•You may assume that the person running this program is using a QWERTY keyboard like the one pictured above.

•Input and Output are both case-insensitive, you may use any case (or a mixture of case combinations) for this challenge and you can also assume all input will be in one case if desired.

•If your language has no way of allowing a user to input the return key for some reason you may ignore that one keystroke for this

•This challenge is just for the default values of the keys, for example if the 4 key is pressed you can assume it will always be 4 and never $

•You can assume only the green keys will ever be pressed.

Example Input -> Output:
S -> a
4 -> 3
= -> -
[ -> p

This is code-golf, so the program with the shortest bytecount wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
leftshift(int c)
{
	static const char sym[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'\nzxcvbnm,./";
	const char *p;
	int i;

	p = strchr(sym, tolower(c));
	if (!p)
		return -1;

	i = (p != sym) ? p - sym : 1;
	return sym[i - 1];
}

int
main(void)
{
	assert(leftshift('S') == 'a');
	assert(leftshift('4') == '3');
	assert(leftshift('=') == '-');
	assert(leftshift('[') == 'p');

	return 0;
}
