/*

Display a sequence of numbers. We assume that n is the number of the variant.

n = 1: 1 4 9 16 25 36 49 64 81 100

n = 2: 2 5 10 17 26 37 50 65 82 101

n = 3: 2 6 12 20 30 42 56 72 90 110

n = 4: 2 4 8 16 32 64 128 256 512 1024

n = 5: 1 8 27 64 125 216 343 512 729 1000

n = 6: 1 2 6 24 120 720 5040 40320 362880 3628800

Input
One number n, 1≤n≤6.

Output
Print the numbers of the sequence

Examples

Input #1
1

Answer #1
1 4 9 16 25 36 49 64 81 100

*/

#include <stdio.h>

void
solve(int n)
{
	static const char *tab[] = {
		"1 4 9 16 25 36 49 64 81 100",
		"2 5 10 17 26 37 50 65 82 101",
		"2 6 12 20 30 42 56 72 90 110",
		"2 4 8 16 32 64 128 256 512 1024",
		"1 8 27 64 125 216 343 512 729 1000",
		"1 2 6 24 120 720 5040 40320 362880 3628800",
	};

	if (1 <= n && n <= 6)
		puts(tab[n - 1]);
}

int
main()
{
	int i;

	for (i = 1; i <= 6; i++)
		solve(i);

	return 0;
}
