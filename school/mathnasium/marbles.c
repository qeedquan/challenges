/*

A bag contains 3 different colors of marbles
1/2 of the total number of marbles are red
1/3 of the total number of marbles are green
The remaining 6 marbles is blue

What is the total number of marbles?

(1/2)*x + (1/3)*x + 6 = x
(5/6)*x + 6 = x
6 = (1/6)*x
x = 36

What is the probability of a given marble not being blue?
36 - 6 = 30
30/36 = 5/6

*/

#include <stdio.h>
#include <limits.h>

void
solve()
{
	int r, g, b;
	int x, l;

	b = 6;
	l = INT_MAX - (INT_MAX % b);
	for (x = b; x < l; x += b) {
		r = x / 2;
		g = x / 3;
		if (r + g + b == x) {
			printf("Total number of marbles: %d\n", x);
			printf("Probability of marble not being blue: %d/%d\n", x - b, x);
			return;
		}
	}
	printf("No solution found\n");
}

int
main()
{
	solve();
	return 0;
}
