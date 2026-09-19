/*

Find the indices of the first and last space character in a given string. The indexing of characters starts at 0.

Input
The input consists of a single string containing only Latin letters, punctuation marks, and spaces.

Output
Print two numbers: the index of the first space and the index of the last space in the string. If there are no spaces in the string, print −1.

Examples

Input #1
I am programming on Python.

Answer #1
1 19

Input #2
abrakadabra

Answer #2
-1

*/

#include <stdio.h>
#include <ctype.h>

void
solve(const char *s)
{
	size_t i, j, f;
	const char *p;

	f = 0;
	for (p = s; *p; p++) {
		if (!isspace(*p))
			continue;
		if (!f) {
			i = p - s;
			f = 1;
		}
		j = p - s;
	}
	if (f)
		printf("%zu %zu\n", i, j);
	else
		printf("-1\n");
}

int
main()
{
	solve("I am programming on Python.");
	solve("abrakadabra");

	return 0;
}
