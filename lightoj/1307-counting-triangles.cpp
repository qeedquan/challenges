/*

You are given N sticks having distinct lengths; you have to form some triangles using the sticks. A triangle is valid if its area is positive. Your task is to find the number of ways you can form a valid triangle using the sticks.

Input
Input starts with an integer T (≤ 10), denoting the number of test cases.

Each case starts with a line containing an integer N (3 ≤ N ≤ 2000). The next line contains N integers denoting the lengths of the sticks. You can assume that the lengths are distinct and each length lies in the range [1, 10^9].

Output
For each case, print the case number and the total number of ways a valid triangle can be formed.

Sample
Input	Output
3
5
3 12 5 4 9
6
1 2 3 4 5 6
4
100 211 212 121

Case 1: 3
Case 2: 7
Case 3: 4

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

size_t solve(vector<int> &&lengths)
{
	sort(lengths.begin(), lengths.end());

	size_t result = 0;
	for (size_t i = 0; i < lengths.size(); i++)
	{
		for (size_t j = i + 1; j < lengths.size(); j++)
		{
			size_t k = upper_bound(lengths.begin(), lengths.end(), lengths[i] + lengths[j] - 1) - lengths.begin();
			if (k)
				k -= 1;
			if (k > j)
				result += k - j;
		}
	}
	return result;
}

int main()
{
	assert(solve({ 3, 12, 5, 4, 9 }) == 3);
	assert(solve({ 1, 2, 3, 4, 5, 6 }) == 7);
	assert(solve({ 100, 211, 212, 121 }) == 4);

	return 0;
}
