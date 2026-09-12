/*

Complete the method which returns the number which is most frequent in the given input array. If there is a tie for most frequent number, return the largest number among them.

Note: no empty arrays will be given.

Examples
[12, 10, 8, 12, 7, 6, 4, 10, 12]              -->  12
[12, 10, 8, 12, 7, 6, 4, 10, 12, 10]          -->  12
[12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10]  -->   3

*/

#include <cassert>
#include <vector>
#include <map>

using namespace std;

int highest_rank(const vector<int> &array)
{
	size_t count = 0;
	int maximum = 0;
	map<int, size_t> seen;
	for (auto value : array)
	{
		seen[value] += 1;
		if (seen[value] > count || (seen[value] == count && value > maximum))
		{
			count = seen[value];
			maximum = value;
		}
	}
	return maximum;
}

int main()
{
	assert(highest_rank({ 12, 10, 8, 12, 7, 6, 4, 10, 12 }) == 12);
	assert(highest_rank({ 12, 10, 8, 12, 7, 6, 4, 10, 12, 10 }) == 12);
	assert(highest_rank({ 12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10 }) == 3);

	return 0;
}
