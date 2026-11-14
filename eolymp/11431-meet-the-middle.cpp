/*

An array of n integers is given. In how many ways can you choose a subset of its elements such that their sum is equal to s?

Input
The first line contains two integers: n (1≤n≤40) — the size of the array, and s (1≤s≤10^9) — the required sum.

The second line contains n integers: t1,t2,…,tn (1≤ti≤10^9) — the elements of the array.

Output
Print a single integer — the number of ways to choose a subset of the array elements whose sum is equal to s.

Examples

Input #1
4 5
1 2 3 2

Answer #1
3

Input #2
6 7
1 3 2 2 1 4

Answer #2
8

*/

#include <cassert>
#include <vector>

using namespace std;

typedef unsigned long long uvlong;

// https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/#using-space-optimised-dp-ontarget-time-and-otarget-space
uvlong subset_sums(const vector<uvlong> &array, uvlong target)
{
	vector<uvlong> prev(target + 1, 0);
	vector<uvlong> curr(target + 1, 0);
	prev[0] = 1;
	for (size_t i = 1; i <= array.size(); i++)
	{
		curr = prev;
		for (uvlong j = 0; j <= target; j++)
		{
			if (j >= array[i - 1])
				curr[j] += prev[j - array[i - 1]];
		}
		prev = curr;
	}
	return curr[target];
}

int main()
{
	assert(subset_sums({ 1, 2, 3, 2 }, 5) == 3);
	assert(subset_sums({ 1, 3, 2, 2, 1, 4 }, 7) == 8);
	assert(subset_sums({ 1, 2, 3, 2 }, 50) == 0);

	return 0;
}
