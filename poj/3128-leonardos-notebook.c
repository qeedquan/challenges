/*

Description

— I just bought Leonardo's secret notebook! Rare object collector Stan Ucker was really agitated but his friend, special investigator Sarah Kepticwas unimpressed.
— How do you know it is genuine?
— Oh, it must be, at that price. And it is written in the da Vinci code. Sarah browsed a few of the pages. It was obvious to her that the code was a substitution cipher, where each letter of the alphabet had been substituted by another letter.
— Leonardo would have written the plain-text and left it to his assistant to encrypt, she said. And he must have supplied the substitution alphabet to be used. If we are lucky, we can find it on the back cover! She turned up the last page and, lo and behold, there was a single line of all 26 letters of the alphabet:
QWERTYUIOPASDFGHJKLZXCVBNM
— This may be Leonardo's instructions meaning that each A in the plain-text was to be replaced by Q, each B withW, etcetera. Let us see... To their disappointment, they soon saw that this could not be the substitution that was used in the book. Suddenly, Stan brightened.
— Maybe Leonardo really wrote the substitution alphabet on the last page, and by mistake his assistant coded that line as he had coded the rest of the book. So the line we have here is the result of applying some permutation TWICE to the ordinary alphabet! Sarah took out her laptop computer and coded fiercely for a few minutes. Then she turned to Stan with a sympathetic expression.
— No, that couldn't be it. I am afraid that you have been duped again, my friend. In all probability, the book is a fake.

Write a program that takes a permutation of the English alphabet as input and decides if it may be the result of performing some permutation twice.

http://poj.org/images/3128_1.jpg

Input

The input begins with a positive number on a line of its own telling the number of test cases (at most 500). Then for each test case there is one line containing a permutation of the 26 capital letters of the English alphabet.

Output

For each test case, output one line containing Yes if the given permutation can result from applying some permutation twice on the original alphabet string ABC...XYZ, otherwise output No.

Sample Input

2
QWERTYUIOPASDFGHJKLZXCVBNM
ABCDEFGHIJKLMNOPQRSTUVWXYZ

Sample Output

No
Yes

Source

Northwestern Europe 2006

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
permutable2(const char *s)
{
	char c0[256], c1[256];
	size_t c, i, n;

	memset(c0, 0, sizeof(c0));
	memset(c1, 0, sizeof(c1));
	for (n = 0; s[n]; n++) {
		if (c0[n])
			continue;

		c = 0;
		for (i = n; i < nelem(c0) && !c0[i]; c++) {
			c0[i] = 1;
			if (i <= 'A')
				i = s[i] - 'A';
		}
		c1[c] += 1;
	}

	for (i = 1; i <= n; i++) {
		if (!(i & 1) && (c1[i] & 1))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(permutable2("QWERTYUIOPASDFGHJKLZXCVBNM") == false);
	assert(permutable2("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == true);

	return 0;
}
