/*

Description

FJ and his cows enjoy playing a mental game. They write down the numbers from 1 to N (1 <= N <= 10) in a certain order and then sum adjacent numbers to produce a new list with one fewer number. They repeat this until only a single number is left. For example, one instance of the game (when N=4) might go like this:

    3   1   2   4

      4   3   6

        7   9

         16
Behind FJ's back, the cows have started playing a more difficult game, in which they try to determine the starting sequence from only the final total and the number N. Unfortunately, the game is a bit above FJ's mental arithmetic capabilities.

Write a program to help FJ play the game and keep up with the cows.

Input

Line 1: Two space-separated integers: N and the final sum.

Output

Line 1: An ordering of the integers 1..N that leads to the given sum. If there are multiple solutions, choose the one that is lexicographically least, i.e., that puts smaller numbers first.

Sample Input

4 16
Sample Output

3 1 2 4

Hint

Explanation of the sample:

There are other possible sequences, such as 3 2 1 4, but 3 1 2 4 is the lexicographically smallest.
Source

USACO 2006 February Gold & Silver

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int binomial(int n, int k)
{
	int i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

vector<int> backward(int N, int S)
{
	vector<int> x(N);
	for (auto i = 0; i < N; i++)
		x[i] = i + 1;

	do
	{
		auto s = 0;
		for (auto i = 0; i < N; i++)
			s += binomial(N - 1, i) * x[i];

		if (s == S)
			break;
	} while (next_permutation(x.begin(), x.end()));

	x.erase(remove(x.begin(), x.end(), 0), x.end());
	return x;
}

int main()
{
	vector<int> x1 = { 3, 1, 2, 4 };

	assert(backward(4, 16) == x1);
	return 0;
}
