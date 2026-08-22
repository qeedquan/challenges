/*

Businesses use keypad letters in creative ways to spell out a phone number and make it more memorable. Example: http://en.wikipedia.org/wiki/File:Telephone-keypad2.svg

Create a mapping for your dialer as given in the above link. Constraints:

letters are all uppercase
digits 0, 1 are mapped to 0, 1 respectively

Write a function that takes four digits of a phone number, and returns a list of all of the words that can be written with that number. (You should return all permutations, not only English words.)

*/

#include <stdio.h>
#include <ctype.h>

int
telephone(const char s[5])
{
	static const char *key[] = {
		"0",
		"1",
		"ABC",
		"DEF",
		"GHI",
		"JKL",
		"MNO",
		"PQRS",
		"TUV",
		"WXYZ",
	};

	const char *c0, *c1, *c2, *c3;
	const char *k0, *k1, *k2, *k3;
	int i;

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return -1;
	}

	k0 = key[s[0] - '0'];
	k1 = key[s[1] - '0'];
	k2 = key[s[2] - '0'];
	k3 = key[s[3] - '0'];
	for (c0 = k0; *c0; c0++) {
		for (c1 = k1; *c1; c1++) {
			for (c2 = k2; *c2; c2++) {
				for (c3 = k3; *c3; c3++)
					printf("%c%c%c%c\n", *c0, *c1, *c2, *c3);
			}
		}
	}
	printf("\n");

	return 0;
}

int
main()
{
	telephone("0002");
	telephone("1123");
	telephone("1234");

	return 0;
}
