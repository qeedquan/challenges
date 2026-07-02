/*

Create a cat program, a.k.a a program that takes an input and prints it.

...Except, the program will randomly take characters away from your input and print that instead.

Each character in the input should have generally equal odds to be removed with the program, though, as it is hard to make that, the odds for each character can vary by 10% at most.

Your program should take the input, then randomly remove characters from the input, then print that version again. (You can print with trailing newlines or other characters in case your language has to print newlines.)

If the input was BOOOWL, it shouldn't remove all Os with an equal chance: each character (not unique) should be considered, so instead of every O combined having a 1/5 chance (for example), each O should have a 1/5 chance, so, instead of there being a 1/5 chance of BWL, there should be a 1/5 chance of BOWL, BOOWL.

Input is restricted to STDIN or closest equivalent.

Each character must have a minimum of 10% and a maximum of 30% chance to be removed.

Each character's odds should be calculated individually.

You can use any component of your language supporting random actions, be it functions or something other.

Output must be through STDOUT or the closest equivalent. If your language does have STDOUT, do not output in any other way. If your language cannot output strings as text, use closest equivalent (C's character array output's OK here).

This is code golf. Shortest program wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
catdrop(FILE *in, FILE *out)
{
	int c;

	while ((c = fgetc(in)) != EOF) {
		if (drand48() >= 0.2)
			fputc(c, out);
	}
}

int
main()
{
	srand48(time(NULL));
	catdrop(stdin, stdout);
	return 0;
}
