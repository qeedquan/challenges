/*

GNCHE-1 is a sophisticated electronic device that outputs, every second, the next number in the sequence 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, ….
Due to the high cost of electronic components, you are tasked with developing an emulator for this device.

Input
You are given the number of seconds n (1≤n≤1000000) the generator has been running after being switched on.

Output
Output the result of the generator for the given second.

Examples
Input #1
2

Answer #1
1 2

*/

#include <stdio.h>
#include <math.h>

// https://oeis.org/A002024
int
seq(int n)
{
	return (sqrt(8 * n) + 1) / 2;
}

void
solve(int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d ", seq(i));
	printf("\n");
}

int
main()
{
	int i;

	for (i = 0; i <= 16; i++)
		solve(i);

	return 0;
}
