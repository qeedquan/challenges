/*

Description
Oh, how cursed we are to have but 10 digits upon our fingers. Imagine the possibilities were we able to count to numbers beyond! But halt! With 10 digits upon our two appendages, 1024 unique combinations appear! But alas, counting in this manner is cumbersome, and counting to such a number beyond reason. Surely being able to count up to 100 would suffice!

You will be given inputs which correspond to the 10 digits of a pair of hands in the following format, where 1 means the finger is raised, and 0 means the finger is down.

Example:

**LP** | **LR** | **LM** | **LI** | **LT** |  **RT** | **RI** | **RM** | **RR** | **RP**
---------|-----------|-----------|----------|-----------|-----------|----------|------------|-----------|----------
0 | 1 | 1 | 1 | 0 | 1 | 1| 1| 0| 0

L = Left, R = Right, P = Pinky, R = Ring Finger, M = Middle Finger, I = Index Finger, T = Thumb
Your challenge is to take these inputs, and:

Determine if it is valid based on this counting scheme.

If it is, then decode the inputs into the number represented by the digits on the hand.

Formal Inputs and Outputs
0111011100 -> 37
1010010000 -> Invalid
0011101110 -> 73
0000110000 -> 55
1111110001 -> Invalid

Credit
This challenge was submitted by u/abyssalheaven. Thank you! If you have any challenge ideas, please share them in r/dailyprogrammer_ideas and there's a good chance we'll use them.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
count(const char *input, char *output)
{
	static const char left[] = "0516  27      38              49";
	static const char right[] = "0       1   2 345       6   7 89";

	unsigned hand, handl, handr;
	int digits;
	int ch;
	size_t index;
	char *buf;

	buf = output;
	hand = 0;
	digits = 0;
	for (index = 0; input[index]; index++) {
		ch = input[index];
		if (ch != '0' && ch != '1')
			continue;

		hand = (hand << 1) | (ch - '0');
		if (++digits == 10) {
			handl = left[(hand >> 5) & 0x1f];
			handr = right[hand & 0x1f];
			if (handl == ' ' || handr == ' ')
				return strcpy(output, "Invalid");

			*buf++ = handl;
			*buf++ = handr;
			digits = 0;
		}
	}
	*buf = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	count(input, output);
	printf("%s\n", output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("0111011100", "37");
	test("1010010000", "Invalid");
	test("0011101110", "73");
	test("0000110000", "55");
	test("1111110001", "Invalid");

	return 0;
}
