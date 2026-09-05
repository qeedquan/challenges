/*

Sort the array of integers in non-increasing order.

Input
The first line contains the size of the array n (1≤n≤1000).
The second line contains n integers, each not exceeding 2⋅10^9 in absolute value.

Output
Print the given numbers in non-increasing order.

Examples

Input #1
5
9 2 7 1 2

Answer #1
9 7 2 2 1

*/

#include <algorithm>
#include <print>
#include <vector>

using namespace std;

void solve(vector<int> &&numbers)
{
	sort(numbers.begin(), numbers.end(), greater<int>());
	for (auto number : numbers)
		print("{} ", number);
	println();
}

int main()
{
	solve({ 9, 2, 7, 1, 2 });

	return 0;
}
