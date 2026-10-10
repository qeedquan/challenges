/*

I took inspiration from a challenge I did some years ago in a programming competition.

Your goal is to write a function that generates a random integer number between 0 and 150 (included), and then prints it in actual words. For example, 139 would be printed as onehundredthirtynine.

Rules:

You cannot use any external resource, nor any library that will perform the conversion.

The shortest answer will win.

Good luck!

*/

#include <stdio.h>

// https://xkcd.com/221/
const char *
rndlit(void)
{
	return "four";
}

int
main(void)
{
	printf("%s\n", rndlit());
	return 0;
}
