/*

In a season, each player has three statistics: runs, wickets, and catches.
Given the season stats of two players A and B, denoted by R, W, and C respectively, the person who is better than the other in the most statistics is regarded as the better overall player.
Tell who is better amongst A and B. It is known that in each statistic, the players have different values.

Input Format

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains three integers R1, W1, C1, the stats for player A.
The second line contains three integers R2, W2, C2, the stats for player B.

Output Format

For each test case, output in a single line "A" (without quotes) if player A is better than player B and "B" (without quotes) otherwise.

Constraints

1≤T≤1000
0≤R1,R2≤500
0≤W1,W2≤20
0≤C1,C2≤20
R1≠R2
W1≠W2
C1≠C2

*/

#include <assert.h>

int
player(int r1, int w1, int c1, int r2, int w2, int c2)
{
	int a, b;

	a = b = 0;
	(r1 > r2) ? a++ : b++;
	(w1 > w2) ? a++ : b++;
	(c1 > c2) ? a++ : b++;
	return (a > b) ? 'A' : 'B';
}

int
main(void)
{
	assert(player(0, 1, 2, 2, 3, 4) == 'B');
	assert(player(10, 10, 10, 8, 8, 8) == 'A');
	assert(player(10, 0, 10, 0, 10, 0) == 'A');

	return 0;
}
