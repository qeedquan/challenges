/*

You have to write a function/program that takes input via the stdin/command-line arguments/function arguments, mixes up characters in a string, and then output the final string via the stdout.

Input will first contain a string (not empty or null), a space, and then an even number of non-negative numbers all separated by spaces. If input is taken via function arguments, the string will be the one of the arguments while the integers, which are seperated by a space, will be the other. You must swap the characters of the string at the indices corresponding to consecutive pairs of numbers.

For instance:

Hello_world! 0 6
must result in

wello_Horld!
Assumptions
You may choose between 0-based and 1-based indexing, and may assume that the given indexes will always be in range.
The string will not be longer than 100 characters and will only contain ASCII characters in range ! to ~ (character codes 0x21 to 0x7E, inclusive). See ASCII table for reference.
The two indices in a pair may be identical (in which case, nothing is swapped in that step).
Scoring
This is code golf, so the shortest submission (in bytes) wins.

Test Cases
Hello_world! 0 6 => wello_Horld!
First 1 2 1 0 0 4 => tFisr
(Second!$$) 8 7 10 1 => ()econd$!$S
~Third~ 0 0 6 6 0 6 6 0 => ~Third~

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swapc(char *a, char *b)
{
	char t;

	t = *b;
	*b = *a;
	*a = t;
}

char *
mix(const char *s, size_t a[][2], size_t n, char *b)
{
	size_t i;

	strcpy(b, s);
	for (i = 0; i < n; i++)
		swapc(&b[a[i][0]], &b[a[i][1]]);
	return b;
}

void
test(const char *s, size_t a[][2], size_t n, const char *r)
{
	char b[128];

	mix(s, a, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	size_t a1[][2] = {{0, 6}};
	size_t a2[][2] = {{1, 2}, {1, 0}, {0, 4}};
	size_t a3[][2] = {{8, 7}, {10, 1}};
	size_t a4[][2] = {{0, 0}, {6, 6}, {0, 6}, {6, 0}};

	test("Hello_world!", a1, nelem(a1), "wello_Horld!");
	test("First", a2, nelem(a2), "tFisr");
	test("(Second!$$)", a3, nelem(a3), "()econd$!$S");
	test("~Third~", a4, nelem(a4), "~Third~");

	return 0;
}
