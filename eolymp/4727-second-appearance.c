/*

Given a string of letters. Find the second appearance of the letter f and print its index (indexes are numbered starting from 0).

If the letter f appears only once, print number −1. If letter f is not found in the given string, print number −2.

Input
One string of letters.

Output
Print the answer depending on how many times the letter f appears in the given string.

Examples

Input #1
comfort

Answer #1
-1

Input #2
coffee

Answer #2
3

Input #3
qwerty

Answer #3
-2

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

ssize_t
solve(const char *s)
{
	ssize_t c, i;

	for (c = i = 0; s[i] && c < 2; i++)
		c += (s[i] == 'f');

	if (c == 0)
		return -2;
	if (c == 1)
		return -1;
	return i - 1;
}

int
main()
{
	assert(solve("comfort") == -1);
	assert(solve("coffee") == 3);
	assert(solve("qwerty") == -2);

	return 0;
}
