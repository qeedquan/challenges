/*

Display the sequence of numbers based on the given variant number n.

n=1: 1 2 3 4 5 6 7 8 9 10

n=2: 0 1 2 3 4 5 6 7 8 9

n=3: 1 3 5 7 9 11 13 15 17 19

n=4: 2 4 6 8 10 12 14 16 18 20

n=5: 9 8 7 6 5 4 3 2 1 0

n=6: 5 10 15 20 25 30 35 40 45 50

Input
A single integer n, where 1≤n≤6

Output
Print the sequence of numbers corresponding to the given n.

Examples

Input #1
1

Answer #1
1 2 3 4 5 6 7 8 9 10

*/

#include <stdio.h>

void
solve(int n)
{
	if (n == 1)
		printf("1 2 3 4 5 6 7 8 9 10");
	else if (n == 2)
		printf("0 1 2 3 4 5 6 7 8 9");
	else if (n == 3)
		printf("1 3 5 7 9 11 13 15 17 19");
	else if (n == 4)
		printf("2 4 6 8 10 12 14 16 18 20");
	else if (n == 5)
		printf("9 8 7 6 5 4 3 2 1 0");
	else if (n == 6)
		printf("5 10 15 20 25 30 35 40 45 50");
	puts("");
}

int
main()
{
	solve(1);

	return 0;
}
