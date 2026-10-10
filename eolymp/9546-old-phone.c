/*

Typing an SMS on an old mobile phone can be quite cumbersome, as each button corresponds to multiple letters.
For instance, to type the word "DOOL," you would press the number 3 once, the number 6 three times, the number 6 three more times,
and finally the number 5 three times, resulting in the sequence: 3 666 666 555.
To insert a space, you press the number 0 once.
Your task is to output the sequence of phone keys required to type the given input text.

https://static.e-olymp.com/content/e0/e07111fdf1e1f6cd56342caee81c745107e9e4b8.jpg

Input
The input consists of text written in Latin uppercase letters.

Output
Provide a sequence of numbers, separated by spaces, representing the keys to be pressed.

Examples

Input #1
TEXT

Answer #1
8 33 99 8

*/

#include <stdio.h>

void
solve(const char *s)
{
	static const int lut[256] = {
		['A'] = 2,
		['B'] = 22,
		['C'] = 222,
		['D'] = 3,
		['E'] = 33,
		['F'] = 333,
		['G'] = 4,
		['H'] = 44,
		['I'] = 444,
		['J'] = 5,
		['K'] = 55,
		['L'] = 555,
		['M'] = 6,
		['N'] = 66,
		['O'] = 666,
		['P'] = 7,
		['Q'] = 77,
		['R'] = 777,
		['S'] = 7777,
		['T'] = 8,
		['U'] = 88,
		['V'] = 888,
		['W'] = 9,
		['X'] = 99,
		['Y'] = 999,
		['Z'] = 9999,
		[' '] = 0,
	};

	for (; *s; s++)
		printf("%d ", lut[*s & 0xff]);
	printf("\n");
}

int
main()
{
	solve("TEXT");
	return 0;
}
