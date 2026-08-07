#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

Optimal strategy:
Stan always choose 9
Ollie always choose 2

*/

const char *
winner(long n)
{
	long v, t;

	t = 1;
	for (v = 1; v < n; t = !t) {
		if (t)
			v *= 9;
		else
			v *= 2;
	}
	if (t)
		return "Ollie";
	return "Stan";
}

int
main()
{
	assert(!strcmp(winner(162), "Stan"));
	assert(!strcmp(winner(17), "Ollie"));
	assert(!strcmp(winner(34012226), "Stan"));

	return 0;
}
