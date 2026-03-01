/*

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 10^7

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/solutions-451-500/486-predict-the-winner.html
bool
predict(int *a, size_t n)
{
	int **p, *q;
	size_t i, k;
	bool r;

	if (n == 0)
		return false;

	r = false;
	p = calloc(n, sizeof(*p));
	q = calloc(n * n, sizeof(*q));
	if (!p || !q)
		goto out;

	for (i = 0; i < n; i++)
		p[i] = &q[i * n];

	for (k = 0; k < n; k++) {
		for (i = 0; i + k < n; i++) {
			if (k == 0)
				p[i][i + k] = a[i];
			else if (k == 1)
				p[i][i + k] = abs(a[i] - a[i + k]);
			else
				p[i][i + k] = max(p[i][i] - p[i + 1][i + k], p[i + k][i + k] - p[i][i + k - 1]);
		}
	}
	r = p[0][n - 1] >= 0;

out:
	free(p);
	free(q);
	return r;
}

int
main(void)
{
	int a1[] = {1, 5, 2};
	int a2[] = {1, 5, 233, 7};

	assert(predict(a1, nelem(a1)) == false);
	assert(predict(a2, nelem(a2)) == true);

	return 0;
}
