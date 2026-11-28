/*

The input for the program is a sequence of integers that concludes with the number 0.
Your task is to determine the length of this sequence, not counting the final zero.

Input
A sequence of integers, with each number on a separate line.

Output
A single integer representing the length of the sequence.

Examples

Input #1
7
-1
4
-6
0

Answer #1
4

*/

#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

size_t length(const vector<int> &numbers)
{
	size_t count = 0;
	for (auto number : numbers)
	{
		if (number == 0)
			break;
		count += 1;
	}
	return count;
}

int main()
{
	assert(length({ 7, -1, 4, -6, 0 }) == 4);

	return 0;
}
