/*

Input
A string that contains at most one of each of the letters A, B, and C. They may be in any order. The empty string is valid input.

Note: A previous version of this challenge used the letters LEJ instead of ABC and they may still be used if desired.

Output
A string of the A, B, C letters that were not present in the input. They may be in any order.

If the output would be the empty string then simply giving no output is valid, if that makes sense for your implementation. (e.g. you don't need to actually call print on an empty string.)

Examples
If the input is B then the output should either be CA or AC since A and C are not present in the input.
If the input is the empty string then the output should be ABC or any permutation since none of the three letters are present in the input.
If the input is CAB then the output should be the empty string because all three letters are present in the input.
Test Cases
There are so few input cases that we can enumerate all of them:

in -> out1 | out2 | out3 | ...
ABC -> ""
ACB -> ""
BCA -> ""
BAC -> ""
CAB -> ""
CBA -> ""
AB -> C
AC -> B
BC -> A
BA -> C
CA -> B
CB -> A
A -> BC | CB
B -> CA | AC
C -> AB | BA
"" -> ABC | ACB | BCA | BAC | CAB | CBA
All valid outputs for each input are given, separated by |'s. "" represents the empty string

Scoring
The shortest code in bytes wins. But keep in mind that you may get more recognition for solving the challenge in a unique way rather than in a short way ;)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
letters(const char *s, char *b)
{
	size_t h[256];
	size_t i;
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; (c = s[i] & 0xff); i++)
		h[c]++;

	i = 0;
	for (c = 'A'; c <= 'C'; c++) {
		if (!h[c])
			b[i++] = c;
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[4];

	letters(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("ABC", "");
	test("ACB", "");
	test("BCA", "");
	test("BAC", "");
	test("CAB", "");
	test("CBA", "");
	test("AB", "C");
	test("AC", "B");
	test("BC", "A");
	test("BA", "C");
	test("CA", "B");
	test("CB", "A");
	test("A", "BC");
	test("B", "AC");
	test("C", "AB");
	test("", "ABC");

	return 0;
}
