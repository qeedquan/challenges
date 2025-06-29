/*

Challenge is to write a function/program which outputs a truthy or falsey value alternately each time you call it. No input.

It can start with either true or false.

*/

#include <stdio.h>

bool
funny()
{
	static bool x;

	x = !x;
	return x;
}

int
main()
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%d\n", funny());

	return 0;
}
