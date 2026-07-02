/*

You are given a string and two characters. You have to print the string between these characters from the string.

Input
Input will first contain a string (not empty or null). In the next line, there will be two characters separated by a space.

Challenge
Return the string between the two characters

Example
Hello! What's your name?
! ?
should result in the output:

" What's your name"

Rules
The string will not be longer than 100 characters and will only contain ASCII characters in range (space) to ~(tilde) (character codes 0x20 to 0x7E, inclusive). See ASCII table for reference.
You must take input from the stdin( or closest alternative ).
The output should be surrounded with quotes(").
You can write a full program, or a function which takes input, and outputs the final string
The two characters will only contain ASCII characters in range (space) to ~(tilde) (character codes 0x20 to 0x7E, inclusive). See ASCII table for reference.
There is no guarantee that both the characters will be in the string.
If any of the characters is not found in the string, print "null".
If any of the characters is found more than one times (unless both the characters are same) in a string, print "null".
If both the characters are the same character, print the string "null".

Test Cases
1)

<HTML>code</HTML>
> <                       --> "null"
2)

What's what?
' '                       --> "null"
3)

abcdefghijklmnopqrstuvwxyz
n k                       --> "lm"
4)

Testing...
e T                       --> ""
5)

Last test-case
  -                       --> "test"
Scoring
This is code golf, so the shortest submission (in bytes) wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swap(size_t *x, size_t *y)
{
	size_t t;

	t = *y;
	*y = *x;
	*x = t;
}

int
match(const char *s, size_t i, char c, size_t *n, int *f, int m)
{
	if (s[i] != c)
		return 0;

	if (*f & m)
		return -1;

	*n = i;
	*f |= m;

	return 1;
}

char *
extract(const char *s, int c0, int c1, char *b)
{
	size_t i, j, k, n;
	int f;

	strcpy(b, "null");

	f = 0;
	for (i = j = k = 0; s[i]; i++) {
		if (match(s, i, c0, &j, &f, 1) < 0)
			return b;

		if (match(s, i, c1, &k, &f, 2) < 0)
			return b;
	}

	if (j > k)
		swap(&j, &k);

	if (j < k) {
		n = k - j - 1;
		memcpy(b, s + j + 1, n);
		b[n] = '\0';
	}

	return b;
}

void
test(const char *s, int c0, int c1, const char *r)
{
	char b[128];

	extract(s, c0, c1, b);
	printf("\"%s\"\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello! What's your name?", '!', '?', " What's your name");
	test("<HTML>code</HTML>", '>', '<', "null");
	test("What's what?", ' ', ' ', "null");
	test("abcdefghijklmnopqrstuvwxyz", 'n', 'k', "lm");
	test("Testing...", 'e', 'T', "");
	test("Last test-case", ' ', '-', "test");

	return 0;
}
