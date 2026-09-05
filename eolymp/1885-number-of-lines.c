/*

Renowned programmer Petryk is embarking on the creation of a groundbreaking computer game, set to be unlike anything envisioned by top game development companies.
Petryk is confident that the revolutionary features he plans to incorporate will swiftly capture the market, earning him global recognition and substantial profits.

One standout feature will be a unique system for displaying scores on a leaderboard.
Each score is represented as a number in the decimal system, but the digits and any minus sign will be shown using a series of lines:

https://static.e-olymp.com/content/8f/8fd50d690dc63676fbe4641d141ba9db754d1db4.jpg

Your task is to assist Petryk by determining how many lines his program will need to draw when a player achieves a certain score.

Input
The input consists of a single line containing an integer X (-109≤X≤10^9), representing the player's score.

Output
Output a single number on one line: the total number of lines required to display the score.

Examples

Input #1
85

Answer #1
12

*/

#include <assert.h>

int
solve(const char *s)
{
	static const int lut[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	int r;

	for (r = 0; *s; s++) {
		if ('0' <= *s && *s <= '9')
			r += lut[*s - '0'];
	}
	return r;
}

int
main()
{
	assert(solve("85") == 12);

	return 0;
}
