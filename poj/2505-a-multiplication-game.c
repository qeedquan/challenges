/*

Description

Stan and Ollie play the game of multiplication by multiplying an integer p by one of the numbers 2 to 9. Stan always starts with p = 1, does his multiplication, then Ollie multiplies the number, then Stan and so on. Before a game starts, they draw an integer 1 < n < 4294967295 and the winner is who first reaches p >= n.

Input

Each line of input contains one integer number n.

Output

For each line of input output one line either
Stan wins.
or
Ollie wins.
assuming that both of them play perfectly.

Sample Input

162
17
34012226

Sample Output

Stan wins.
Ollie wins.
Stan wins.

Source

Waterloo local 2001.09.22

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

const char *
winner(vlong n)
{
	while (n > 18)
		n = (n + 17) / 18;
	return (n <= 9) ? "Stan" : "Ollie";
}

void
test(vlong n, const char *r)
{
	const char *p;

	p = winner(n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(162, "Stan");
	test(17, "Ollie");
	test(34012226LL, "Stan");

	return 0;
}
