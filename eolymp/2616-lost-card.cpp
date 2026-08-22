/*

One card from a deck numbered from 1 to n (where n is a natural number not exceeding 10^6) is missing. Find the number of the lost card.

Input
The first line contains the number n. The next n−1 lines contain the numbers of the remaining cards.

Output
Print the number of the lost card.

Examples
Input #1
5 1 2 3 4 

Answer #1
5

Input #2
4 3 2 4

Answer #2
1

*/

#include <cassert>
#include <vector>

using namespace std;

int triangular(int n)
{
	return n * (n + 1) / 2;
}

int solve(const vector<int> &numbers)
{
	auto result = triangular(numbers.size() + 1);
	for (auto number : numbers)
		result -= number;
	return result;
}

int main()
{
	assert(solve({ 1, 2, 3, 4 }) == 5);
	assert(solve({ 3, 2, 4 }) == 1);

	return 0;
}
