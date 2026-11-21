/*

Intro/Background
I was looking at "You Had One Job" pictures lately, and noticed an old favourite of mine:

https://i.stack.imgur.com/P8PwA.jpg

And I said to myself: "I need a program that can generate text like that". So I devised a set of rules for character swapping and wrote a CGCC challenge!

The Challenge
Given a single string as input, output a string with its inner characters swapped. This can be done by:

Leaving the first letter as is
Swapping each pair of characters thereafter
Leaving the last letter as is. If the string is of an odd length (i.e. the length of the string mod 2 is 1), leave the last two letters as they are.
Example Inputs/Outputs
School -> Shcool
Somebody -> Smobedoy
Character -> Cahartcer
CGCC -> CCGC
Stack Exchange! -> SatkcE cxahgne!
Never gonna give you up -> Nvereg noang vi eoy uup
Walkthrough on swapping

School (Length: 6)
S
 hc
   oo
     l
Shcool


Somebody (Length: 8)
S
 mo
   be
     do
       y
Smobedoy


Character (Length: 9)
C
 ah
   ar
     tc
       er
Cahartcer

Stack Exchange! (Length: 15)
S
 at
   kc
     E
       cx
         ah
           gn
             e!
SatkcE cxahgne!

Rules
Input/output can be taken/given in any convenient format
The input will not contain newlines
Minimum input length is 4
Input will only contain printable ASCII characters

Scoring
This is code-golf, so the answer with the lowest bytes wins.

Sorry about the last test case everyone. It's fixed now

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

char *
swaps(char *b)
{
	size_t i;

	if (!b[0])
		return b;

	for (i = 1; b[i] && b[i + 1] && b[i + 2]; i += 2)
		swapc(b + i, b + i + 1);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	swaps(b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("School", "Shcool");
	test("Somebody", "Smobedoy");
	test("Character", "Cahartcer");
	test("CGCC", "CCGC");
	test("Stack Exchange!", "SatkcE cxahgne!");
	test("Never gonna give you up", "Nvereg noang vi eoy uup");

	return 0;
}
