/*

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
 

Constraints:

1 <= n <= 10^5

Hint:
Use dynamic programming to keep track of winning and losing states. Given some number of stones, Alice can win if she can force Bob onto a losing state.

*/

#include <cassert>
#include <vector>

using namespace std;

bool win(unsigned n)
{
	vector<bool> dp(n + 1);
	for (auto i = 1u; i <= n; i++)
	{
		for (auto j = 1u; j * j <= i; j++)
		{
			if (!dp[i - j * j])
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n];
}

int main()
{
	assert(win(1) == true);
	assert(win(2) == false);
	assert(win(4) == true);

	return 0;
}
