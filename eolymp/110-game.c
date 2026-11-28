/*

There is a pile with N stones.
Two players take turns. On each turn, a player must split the pile into two parts of unequal sizes and take all the stones from the smaller part.
A player who cannot make a move loses the game.

If you go first and want to guarantee a win, how many stones should you take on your first turn? If there is no winning move, output 0.

Input
The number of stones in the pile N (1≤N≤10000).

Output
Output the number of stones you should take on your first turn to guarantee a win, or 0 if there is no winning move.

Examples
Input #1
7

Answer #1
3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
ispow2(int n)
{
	return n > 0 && !(n & (n - 1));
}

// https://oeis.org/A053645
int
solve(int n)
{
	int i;

	if (n < 1)
		return 0;

	i = n - !(n & 1);
	for (i >>= 1; i >= 1; i--) {
		if (ispow2(n - i))
			return i;
	}
	return 0;
}

int
main()
{
	static const int tab[] = {
		0, 0, 1, 0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
		8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
		12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
		29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		17, 18, 19, 20
	};

	size_t i;

	assert(solve(7) == 3);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
