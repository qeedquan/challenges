/*

Description

It's Halloween! Farmer John is taking the cows to a costume party, but unfortunately he only has one costume. The costume fits precisely two cows with a length of S (1 ≤ S ≤ 1,000,000). FJ has N cows (2 ≤ N ≤ 20,000) conveniently numbered 1..N; cow i has length Li (1 ≤ Li ≤ 1,000,000). Two cows can fit into the costume if the sum of their lengths is no greater than the length of the costume. FJ wants to know how many pairs of two distinct cows will fit into the costume.

Input

* Line 1: Two space-separated integers: N and S
* Lines 2..N+1: Line i+1 contains a single integer: Li

Output

* Line 1: A single integer representing the number of pairs of cows FJ can choose. Note that the order of the two cows does not matter.

Sample Input

4 6
3
5
2
1

Sample Output

4

Source

USACO 2008 January Bronze

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int pairs(vector<int> &&cows, int length)
{
	auto start = cows.begin();
	auto end = cows.end();
	sort(start, end);

	auto size = cows.size();
	auto sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		auto val = upper_bound(start + i + 1, start + size, length - cows[i]) - start - i - 1;
		if (val == 0)
			break;
		sum += val;
	}
	return sum;
}

int main()
{
	assert(pairs({3, 5, 2, 1}, 6) == 4);
	return 0;
}
