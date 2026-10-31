/*

The input for the program is a sequence of integers that concludes with the number 0. Your task is to determine how many of these integers are negative.

Input
A sequence of integers, with each integer on a separate line.

Output
A single integer representing the count of negative numbers in the sequence.

Examples
Input #1
7
-1
4
-6
0

Answer #1
2

*/

#include <cassert>
#include <vector>

using namespace std;

size_t solve(const vector<int> &numbers)
{
	size_t count = 0;
	for (auto number : numbers)
	{
		if (number == 0)
			break;

		if (number < 0)
			count += 1;
	}
	return count;
}

int main()
{
	assert(solve({ 7, -1, 4, -6, 0 }) == 2);

	return 0;
}
