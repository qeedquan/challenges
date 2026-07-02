/*

At the input of the program, we have a sequence of integers ending with the number 0. It is necessary to find the number of odd numbers in this sequence.

Input
A sequence of integers, one number per line.

Output
A single number — the count of odd numbers in the sequence.

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

size_t count(const vector<int> &numbers)
{
	size_t result = 0;
	for (auto number : numbers)
		result += (number & 1);
	return result;
}

int main()
{
	assert(count({ 7, -1, 4, -6 }) == 2);

	return 0;
}
