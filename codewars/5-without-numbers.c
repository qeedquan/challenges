/*

Write a function that always returns 5

Sounds easy right? Just bear in mind that you can't use any of the following characters: 0123456789*+-/

Good luck :)

*/

#include <stdio.h>

int
five()
{
	return sizeof("five");
}

int
main()
{
	printf("%d\n", five());
	return 0;
}
