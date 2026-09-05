/*

Complete the method which accepts an array of integers, and returns one of the following:

"yes, ascending" - if the numbers in the array are sorted in an ascending order
"yes, descending" - if the numbers in the array are sorted in a descending order
"no" - otherwise
You can assume the array will always be valid, and there will always be one correct answer.

*/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

string classify(const vector<int> &array)
{
	auto flag = 0x0;
	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i] >= array[i - 1])
			flag |= 0x1;
		else if (array[i] <= array[i - 1])
			flag |= 0x2;
	}
	if (flag == 0x1)
		return "yes, ascending";
	if (flag == 0x2)
		return "yes, descending";
	return "no";
}

int main()
{
	assert(classify({ 1, 2 }) == "yes, ascending");
	assert(classify({ 15, 7, 3, -8 }) == "yes, descending");
	assert(classify({ 4, 2, 30 }) == "no");

	return 0;
}
