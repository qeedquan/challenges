/*

Stan and Ollie play the game of multiplication by multiplying an integer p by one of the numbers 2 to
9. Stan always starts with p = 1, does his multiplication, then Ollie multiplies the number, then Stan
and so on. Before a game starts, they draw an integer 1 < n < 4294967295 and the winner is who first
reaches p ≥ n.

Input and Output
Each line of input contains one integer number n. For each line of input output one line either
Stan wins.
or
Ollie wins.
assuming that both of them play perfectly.

Sample input
162
17
34012226

Sample Output
Stan wins.
Ollie wins.
Stan wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

Pptimal strategy:
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
