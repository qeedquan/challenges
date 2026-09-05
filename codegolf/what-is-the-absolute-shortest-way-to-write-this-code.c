/*

So I got kinda bored and was wondering if it was possible to make this code shorter without modifying anything except a file named coin.py...

from random import*;c=['heads','tails'];print('u win'if choice(c)==input(' / '.join(c)+': ')else'u lose')
The program asks the user for either "heads" or "tails", if the result from random.choice(c) matches the user's input, print "you win" to the console. Otherwise print "you lose" to the console.

Example:

heads / tails: tails
u win


heads / tails: tails
u lose
(no loop needed btw, just run once)

Maintaining all its functionality & having the EXACT same output

Have fun, stack exchage :)

Update: Security practices don't matter for this question

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *
trim(char *s)
{
	char *p;

	p = strchr(s, '\n');
	if (p)
		*p = '\0';
	return s;
}

int
main(void)
{
	static const char *tab[] = {"heads", "tails"};

	char b[128];

	srand(time(NULL));
	printf("heads / tails: ");
	if (!fgets(b, sizeof(b), stdin)) {
		printf("\n");
		return 0;
	}

	if (!strcmp(trim(b), tab[rand() & 1]))
		printf("u win\n");
	else
		printf("u lose\n");

	return 0;
}
