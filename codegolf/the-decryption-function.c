/*

You must write a program that takes an encrypted string and decrypt it according to specific rules and then print it out. Decryption will occur by performing two operations.

Sample Input Argument 1 (the encrypted string)

HGJILKBADCFE
Operation 1:

Swap the first half of the string with the second half, which should leave you with:

BADCFEHGJILK
Operation 2:

Swap every two characters with each other such as swapping character 1 with 2, 3 with 4, etc., which should leave you with the decrypted string:

ABCDEFGHIJKL
Guidelines:

Input Argument 1 will contain only uppercase letters

Input Argument 1's length will be between 2 and 100 characters

Input Argument 1's length will always be an even number

Preferably the input will be taken from the command line (like below).

Another Test Case MPORQTSVUXWZYBADCFEHGJILKN is the input, Output is ABCDEFGHIJKLMNOPQRSTUVWXYZ

My Attempt

import sys
_,a=sys.argv
b=len(a)//2
s=a[b:]+a[:b]
print(''.join(x+y for x,y in zip(s[1::2],s[::2])))

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swapc(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

char *
decrypt(const char *s, char *b)
{
	size_t i, n, m;

	n = strlen(s);
	m = n / 2;

	memmove(b, s + m, m);
	memmove(b + m, s, m);
	b[n] = '\0';

	for (i = 1; i < n; i += 2)
		swapc(&b[i], &b[i - 1]);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decrypt(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("HGJILKBADCFE", "ABCDEFGHIJKL");
	test("MPORQTSVUXWZYBADCFEHGJILKN", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	return 0;
}
