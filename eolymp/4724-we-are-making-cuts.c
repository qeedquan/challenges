/*

You are given a string.

First, print the third character of the string.

On the second line, print the second-to-last character of the string.

On the third line, print the first five characters of the string.

On the fourth line, print the entire string except for the last two characters.

On the fifth line, print all characters at even indices (indexing starts from 0, so begin with the first character).

On the sixth line, print all characters at odd indices, starting with the second character of the string.

On the seventh line, print all characters in reverse order.

On the eighth line, print every other character in reverse order, starting with the last character.

On the ninth line, print the length of the string.

Phew... That seems to be everything... :)

Input
(see example)

Output
(see example)

Examples

Input #1
Abrakadabra

Answer #1
r
r
Abrak
Abrakadab
Arkdba
baaar
arbadakarbA
abdkrA
11

*/

#include <stdio.h>
#include <string.h>

void
solve(const char *s)
{
	size_t i, n, m;

	n = strlen(s);
	if (n >= 3)
		putchar(s[2]);
	printf("\n");

	if (n >= 2)
		putchar(s[n - 2]);
	printf("\n");

	for (i = 0; s[i] && i < 5; i++)
		putchar(s[i]);
	printf("\n");

	m = (n < 2) ? n : n - 2;
	for (i = 0; i < m; i++)
		putchar(s[i]);
	printf("\n");

	for (i = 0; i < n; i += 2)
		putchar(s[i]);
	printf("\n");

	for (i = 1; i < n; i += 2)
		putchar(s[i]);
	printf("\n");

	for (i = n; i > 0; i--)
		putchar(s[i - 1]);
	printf("\n");

	for (i = n; i > 0;) {
		putchar(s[i - 1]);
		i -= (i >= 2) ? 2 : 1;
	}
	printf("\n");

	printf("%zu\n", n);
}

int
main()
{
	solve("Abrakadabra");

	return 0;
}
