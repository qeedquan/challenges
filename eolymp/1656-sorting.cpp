/*

Given a sequence of 32-bit signed integers, sort the sequence and remove all duplicate elements, i.e., keep only one occurrence of each number in the sequence.

Input
The first line contains the number of elements n (1≤n≤65536) in the sequence. The next n lines each contain one integer.

Output
Output no more than n numbers: sort them in descending order if n is even, and in ascending order if n is odd. Each number should appear at most once.

Examples
Input #1
6
8
8
7
3
7
7

Answer #1
8
7
3

*/

#include <cassert>
#include <algorithm>
#include <vector>
#include <print>

using namespace std;

vector<int> &&solve(vector<int> &&values)
{
	auto size = values.size();
	if (size & 1)
		sort(values.begin(), values.end());
	else
		sort(values.begin(), values.end(), greater<int>());

	size_t length = 0;
	size_t index2 = 0;
	for (size_t index = 0; index < size; index = index2)
	{
		index2 = index;
		while (index2 < size && values[index] == values[index2])
			index2++;
		values[length++] = values[index];
	}
	values.resize(length);

	return values;
}

void test(vector<int> &&values, const vector<int> &expected)
{
	solve(move(values));
	println("{}", values);
	assert(values == expected);
}

int main()
{
	test({ 8, 8, 7, 3, 7, 7 }, { 8, 7, 3 });

	return 0;
}
