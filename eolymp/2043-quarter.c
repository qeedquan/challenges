/*

Given an integer N (1≤N≤4), which represents the number of a quarter of the year (January, February, March are the first quarter).
For the given N, output the list of months in this quarter.

Input
A single integer — the number of the quarter.

Output
Print the names of the months in English that correspond to the specified quarter, one per line.

Examples
Input #1
1

Answer #1
January
February
March

*/

#include <stdio.h>

void
solve(int n)
{
	switch (n) {
	case 1:
		puts("January");
		puts("February");
		puts("March");
		break;

	case 2:
		puts("April");
		puts("May");
		puts("June");
		break;

	case 3:
		puts("July");
		puts("August");
		puts("September");
		break;

	case 4:
		puts("October");
		puts("November");
		puts("December");
		break;
	}
}

int
main()
{
	solve(1);

	return 0;
}
