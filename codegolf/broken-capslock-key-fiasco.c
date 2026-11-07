/*

Some of your employees have broken capslock keys and you're too cheap to replace them. Help them out by creating the shortest program possible to correct their work! Simply convert each character in a given string from uppercase to lowercase and vice-versa... but there's a twist!

You're also very excited for Christmas! So you're going to leave in a tiny "bug" that doesn't correct letters which are within sequences of Christmas (case-insensitive).

Input
For input you will use one single string (or array of bytes) that may contain newlines and ascii between 0x20 and 0x7e ( - ~). You don't need to worry about carriage returns or any other characters being in the string.

Output
The output should contain only the provided string with the upper and lowercase characters swapped (and the Christmas bug of course!). It can contain up to one extra trailing whitespace.

Christmas Bug
Let's explain this with an example:

Input: i CAN HARDLY WORK LIKE THIS please GET ME A NEW KEYBOARD FOR cHRISTMAS
Output: I Can HaRdly work lIke thiS PLEASE geT Me A new keyboard for ChriStmas
can contains "c" which is the first letter of Christmas, so that isn't changed. The next letter in Christmas is "h", which is in hardly (which also contains the "r"), so that isn't changed, etc. Christmas itself only has one letter unchanged because by the time the code reaches there, it's actually looking for "s", not "c".

Once the sequence is found, it should start all over again at "c", and begin iterating through Christmas once more. So ChristmasChristmas would be left unchanged.

Test Cases
Input: Hello World!
Output: hELLO wORLD!

Input: I like pie :)
Output: i LIKE PIE :)

Input: hELP my KeYboarD
       iS BROKEN
Output: Help MY kEyBOARd
        Is broken

Input: cHRISTMAS IS COMING REALLY SOON!
Output: cHRISTMAS is Coming really soon!

Input: C is the first letter in cHRISTMAS
Output: C IS ThE FIrST LETTER iN ChriSTMAS

Winner
This is code-golf so the shortest answer wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
flipflop(const char *s, char *b)
{
	static const char ign[] = "christmas";

	size_t i, j;
	int c;

	for (i = j = 0; s[i]; i++) {
		c = s[i];
		if (tolower(c) == ign[j])
			j = (j + 1) % (sizeof(ign) - 1);
		else
			c = (isupper(c)) ? tolower(c) : toupper(c);

		b[i] = c;
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	flipflop(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("i CAN HARDLY WORK LIKE THIS please GET ME A NEW KEYBOARD FOR cHRISTMAS", "I Can HaRdly work lIke thiS PLEASE geT Me A new keyboard for ChriStmas");
	test("Hello World!", "hELLO wORLD!");
	test("I like pie :)", "i LIKE PIE :)");
	test("hELP my KeYboarD\n       iS BROKEN", "Help MY kEyBOARd\n       Is broken");
	test("cHRISTMAS IS COMING REALLY SOON!", "cHRISTMAS is Coming really soon!");
	test("C is the first letter in cHRISTMAS", "C IS ThE FIrST LETTER iN ChriSTMAS");

	return 0;
}
