/*

In this kata, you need to write a function that takes a string and a letter as input and then returns the index of the second occurrence of that letter in the string. If there is no such letter in the string, then the function should return -1. If the letter occurs only once in the string, then -1 should also be returned.

Examples:

secondSymbol('Hello world!!!','l')  --> 3
secondSymbol('Hello world!!!', 'A') --> -1

Good luck ;) And don't forget to rate this Kata if you liked it.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

ssize_t
secondsymbol(const char *s, int c)
{
	char *p;

	p = strchr(s, c);
	if (p)
		p = strchr(p + 1, c);
	return (p) ? p - s : -1;
}

int
main()
{
	assert(secondsymbol("Hello world!!!", 'l') == 3);
	assert(secondsymbol("Hello world!!!", 'A') == -1);

	return 0;
}
