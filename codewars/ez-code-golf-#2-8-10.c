/*

You have to write a function f which takes in an octal number in string format and output its decimal representation in less than 15 characters.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long
oct2dec(const char *s)
{
	return strtol(s, NULL, 8);
}

int
main()
{
	assert(oct2dec("010") == 8);
	assert(oct2dec("07") == 7);
	assert(oct2dec("0100") == 64);
	return 0;
}
