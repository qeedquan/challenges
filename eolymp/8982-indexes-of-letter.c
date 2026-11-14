/*

Print all indexes of the small Latin letter a in the given string, assuming that the first character has index 0.

Input
One line of the text, that consists of Latin letters, punctuation marks and spaces only.

Output
Print all the indexes of the letter a in one line. If letter a is not found in the string, then print −1.

Examples

Input #1
abrakadabra

Answer #1
0 3 5 7 10

Input #2
Hello, world!

Answer #2
-1

*/

#include <stdio.h>

void
solve(const char *s)
{
	size_t i, n;

	for (i = n = 0; s[i]; i++) {
		if (s[i] == 'a') {
			if (n > 0)
				printf(" ");
			printf("%zu", i);
			n += 1;
		}
	}
	if (!n)
		printf("-1");
	printf("\n");
}

int
main()
{
	solve("abrakadabra");
	solve("Hello, world!");

	return 0;
}
