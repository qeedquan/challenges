/*

Sean is trying to save a large file to a USB flash drive. He has n USB flash drives with capacities equal to a1, a2, ..., an megabytes. The file size is equal to m megabytes.

Find the minimum number of USB flash drives needed to write Sean's file, if he can split the file between drives.

Input
The first line contains positive integer n (1 ≤ n ≤ 100) — the number of USB flash drives.

The second line contains positive integer m (1 ≤ m ≤ 105) — the size of Sean's file.

Each of the next n lines contains positive integer ai (1 ≤ ai ≤ 1000) — the sizes of USB flash drives in megabytes.

It is guaranteed that the answer exists, i. e. the sum of all ai is not less than m.

Output
Print the minimum number of USB flash drives to write Sean's file, if he can split the file between drives.

Examples
input
3
5
2
1
3
output
2

input
3
6
2
3
2
output
3

input
2
5
5
10
output
1

Note
In the first example Sean needs only two USB flash drives — the first and the third.

In the second example Sean needs all three USB flash drives.

In the third example Sean needs only one USB flash drive and he can use any available USB flash drive — the first or the second.

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int fits(int size, vector<int> &&drives)
{
	sort(drives.begin(), drives.end(), greater<int>());

	auto count = 0;
	auto index = 0u;
	while (size > 0)
	{
		if (index >= drives.size())
			return -1;

		if (drives[index] < 0)
			continue;

		size -= drives[index++];
		count += 1;
	}
	return count;
}

int main()
{
	assert(fits(5, {2, 1, 3}) == 2);
	assert(fits(6, {2, 3, 2}) == 3);
	assert(fits(5, {5, 10}) == 1);

	return 0;
}
