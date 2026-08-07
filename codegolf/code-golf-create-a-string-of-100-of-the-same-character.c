/*

The problem is to create a string of the same character repeated 100 times.

One potential solution in JavaScript is:

var i = 100,
    s = '';

while(i--) s += "Z";
Shortest code wins.

*/

#include <stdio.h>
#include <string.h>

int
main(void)
{
	char s[100];
	int n;

	n = sizeof(s);
	memset(s, 'Z', n);
	printf("%.*s\n", n, s);

	return 0;
}
