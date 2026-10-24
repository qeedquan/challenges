/*

Your task: write a program/function that when given a string containing only ASCII characters, outputs/returns the string in reverse-ish.

Example:

1) Input

Hello, World!
2) Number unique characters in input. (Input string separated by pipes (|) for readability)

H|e|l|l|o|,| |W|o|r|l|d|!
1 2 3   4 5 6 7   8   9 10
3) For duplicate characters, find the first occurrence of that character and number the duplicate character with the same number as the first.

H|e|l|l|o|,| |W|o|r|l|d|!
1 2 3 3 4 5 6 7 4 8 3 9 10
4) Reverse the string, but not the numbers.

!|d|l|r|o|W| |,|o|l|l|e|H
1 2 3 3 4 5 6 7 4 8 3 9 10
5) Delete the characters above repeat numbers. (Deleted characters represented with an asterisk.)

!|d|l|*|o|W| |,|*|l|*|e|H
1 2 3 3 4 5 6 7 4 8 3 9 10
6) Replace the deleted characters with the character that appears over the first occurrence of the number that the deleted character is over.

!|d|l|l|o|W| |,|o|l|l|e|H
1 2 3 3 4 5 6 7 4 8 3 9 10
7) Output

!dlloW ,olleH
Test cases:

Input -> Output
"Hello, World!" -> "!dlloW ,olleH"
"18464399" -> "99343488"
"Code Golf" -> "floG eloC"
"abcdefgABCDEFG" -> "GFEDCBAgfedcba"
"Mmm, marshmallows" -> "swwllwmhsrwm  mms"
"15147" -> "74751"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
revish(char *s)
{
	size_t i, n;
	char h[256];

	n = strlen(s);
	for (i = n; i > 0; i--)
		h[s[i - 1] & 0xff] = s[n - i];
	for (; i < n; i++)
		s[i] = h[s[i] & 0xff];
	return s;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	revish(b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Hello, World!", "!dlloW ,olleH");
	test("18464399", "99343488");
	test("Code Golf", "floG eloC");
	test("abcdefgABCDEFG", "GFEDCBAgfedcba");
	test("Mmm, marshmallows", "swwllwmhsrwm  mms");
	test("15147", "74751");

	return 0;
}
