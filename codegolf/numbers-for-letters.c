/*

There exists a very simple cipher that replaces a letter with it's position in the alphabet. For example, abc would become 1 2 3 in this cipher.

This challenge is an alternative take on this cipher.

The Challenge
Create a program that takes an input of ASCII characters, and outputs a space-separated string of:

integers -26 through 26

letters a through j

The output should come through STDOUT or your language's closest alternative.

Specifications
Capital letters should be negated. A capital D for example would be -4, while a lowercase d would be 4.

Digits should be changed to their alpha counterparts. 1 being a, and so on. Any zeroes in the input will be j.

All non-alphanumeric characters (except spaces) should be ignored.

Spaces are 0.

Adjacent spaces in the output should be reduced to a single space.

Input: You + Me
Correct Output: -25 15 21 0 -13 5
Incorrect Output: -25 15 21 0 0 0 -13 5
A single trailing space or newline is allowed.

Examples
Input: programming puzzles
Output: 16 18 15 7 18 1 13 13 9 14 7 0 16 21 26 26 12 5 19

Input: Code Golf
Output: -3 15 4 5 0 -7 15 12 6

Input: Programming Puzzles & Code Golf
Output: -16 18 15 7 18 1 13 13 9 14 7 0 -16 21 26 26 12 5 19 0 -3 15 4 5 0 -7 15 12 6

Input: C0d3 G0lf
Output: -3 j 4 c 0 -7 j 12 6

Input: abc_ABC
Output: 1 2 3 -1 -2 -3

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
nfl(const char *s, int *r)
{
	size_t i, n;

	for (i = n = 0; s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			r[n++] = -(s[i] - 'A' + 1);
		else if ('a' <= s[i] && s[i] <= 'z')
			r[n++] = s[i] - 'a' + 1;
		else if (s[i] == '0')
			r[n++] = 'j';
		else if ('1' <= s[i] && s[i] <= '9')
			r[n++] = s[i] - '1' + 'a';
		else if (s[i] == ' ') {
			if (n == 0 || r[n - 1])
				r[n++] = 0;
		}
	}
	return n;
}

void
test(const char *s, int *r, size_t nr)
{
	int p[32];
	size_t np;

	np = nfl(s, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	const char s1[] = "You + Me";
	const char s2[] = "programming puzzles";
	const char s3[] = "Code Golf";
	const char s4[] = "Programming Puzzles & Code Golf";
	const char s5[] = "C0d3 G0lf";
	const char s6[] = "abc_ABC";

	int r1[] = {-25, 15, 21, 0, -13, 5};
	int r2[] = {16, 18, 15, 7, 18, 1, 13, 13, 9, 14, 7, 0, 16, 21, 26, 26, 12, 5, 19};
	int r3[] = {-3, 15, 4, 5, 0, -7, 15, 12, 6};
	int r4[] = {-16, 18, 15, 7, 18, 1, 13, 13, 9, 14, 7, 0, -16, 21, 26, 26, 12, 5, 19, 0, -3, 15, 4, 5, 0, -7, 15, 12, 6};
	int r5[] = {-3, 'j', 4, 'c', 0, -7, 'j', 12, 6};
	int r6[] = {1, 2, 3, -1, -2, -3};

	test(s1, r1, nelem(r1));
	test(s2, r2, nelem(r2));
	test(s3, r3, nelem(r3));
	test(s4, r4, nelem(r4));
	test(s5, r5, nelem(r5));
	test(s6, r6, nelem(r6));

	return 0;
}
