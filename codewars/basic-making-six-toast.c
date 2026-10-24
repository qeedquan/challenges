/*

## Problem:

You forgot to count the number of toast you put into there, you don't know if you put exactly six pieces of toast into the toasters.

Define a function that counts how many more (or less) pieces of toast you need in the toasters. Even though you need more or less, the
number will still be positive, not negative.

## Examples:

You must return the number of toast you need to put in (or to take out). In case of 5 you can still put 1 toast in:
5 --> 1


And in case of 12 you need 6 toasts less (but not -6):
12 --> 6

*/

#include <assert.h>
#include <stdlib.h>

int
sixtoast(int n)
{
	return abs(6 - n);
}

int
main()
{
	assert(sixtoast(15) == 9);
	assert(sixtoast(6) == 0);
	assert(sixtoast(3) == 3);

	return 0;
}
