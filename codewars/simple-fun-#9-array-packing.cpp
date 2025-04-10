/*

Task
You are given an array of up to four non-negative integers, each less than 256.

Your task is to pack these integers into one number M in the following way:

The first element of the array occupies the first 8 bits of M;
The second element occupies next 8 bits, and so on.
Return the obtained integer M as unsigned integer.

Note:
the phrase "first bits of M" refers to the least significant bits of M - the right-most bits of an integer. For further clarification see the following example.

Example
For a = [24, 85, 0], the output should be 21784

An array [24, 85, 0] looks like [00011000, 01010101, 00000000] in binary.

After packing these into one number we get 00000000 01010101 00011000 (spaces are placed for convenience), which equals to 21784.

Input/Output
[input] integer array a
Constraints: 1 ≤ a.length ≤ 4 and 0 ≤ a[i] < 256

[output] an unsigned integer
More Challenge
Are you a One-Liner? Please try to complete the kata in one line(no test for it) ;-)

*/

#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

uint32_t pack(const vector<uint8_t> &values)
{
	uint32_t result = 0;
	for (size_t index = values.size(); index > 0; index--)
		result = (result << 8) | values[index - 1];
	return result;
}

int main()
{
	vector<uint8_t> values_1 = {24, 85, 0};

	assert(pack(values_1) == 21784);
	return 0;
}
