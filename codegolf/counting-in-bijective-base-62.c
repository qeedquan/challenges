/*

The task is to generate all the strings from 'a' to '999' including upper case characters like so:

'a', 'b', 'c' ... 'y', 'z', 'A', 'B', 'C' ... 'Y', 'Z', '0', '1', 2' ...
'8', '9', 'aa', 'ab', 'ac' ... 'az', 'aA', 'aB' ... 'aZ', 'a0' ... 'a9', 'ba'
and so on (filling in the gaps), optionally starting with the empty string.

Input:

The amount of consecutive characters the program has to print up to.
Output:

An array containing each string OR one string per line
Clarifications:

The order doesn't matter, you can print uppercase or lowercase letters first if you want.

The output can return any type of enumerable, doesn't have to be an array specifically, although I doubt printing all the combinations won't be the easiest way to go.

An input of 3 would print all the string from 'a' (or '') to '999'‚ an input of 5 up to '99999' and so on.

*/

#include <stdio.h>
#include <string.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *x;
	*x = *y;
	*y = t;
}

void
rev(char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n / 2; i++)
		swapc(&s[i], &s[n - i - 1]);
}

void
output(void)
{
	static const char sym[] = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	static const size_t nsym = sizeof(sym) - 1;

	size_t i, j, k;
	char s[4];

	for (i = 0; i < nsym; i++) {
		for (j = 0; j < nsym; j++) {
			for (k = 0; k < nsym; k++) {
				sprintf(s, "%c%c%c", sym[k], sym[j], sym[i]);
				rev(s, strlen(s));
				if (*s)
					printf("%s\n", s);
			}
		}
	}
}

int
main(void)
{
	output();
	return 0;
}
