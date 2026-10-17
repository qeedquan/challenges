/*

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in
their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it. 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 10^4

Hint 1
Simulate the problem. Count the number of 1's in the binary representation of each integer.

Hint 2
Sort by the number of 1's ascending and by the value in case of tie.

*/

#include <cassert>
#include <algorithm>
#include <bit>
#include <vector>

using namespace std;

typedef unsigned int uint;

vector<uint> sortbybits(vector<uint> &array)
{
	sort(begin(array), end(array), [](const auto &a, const auto &b) {
		return make_pair(popcount(a), a) < make_pair(popcount(b), b);
	});
	return array;
}

int main()
{
	vector<uint> array_1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<uint> array_2 = { 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1 };

	vector<uint> expected_1 = { 0, 1, 2, 4, 8, 3, 5, 6, 7 };
	vector<uint> expected_2 = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

	assert(sortbybits(array_1) == expected_1);
	assert(sortbybits(array_2) == expected_2);

	return 0;
}
