/*

Queen of the Forest needs a function that will add a specified quantity of leading zeros to any given number.

For example, if a 5-digit number is needed, and we pass in 11, the returned value would be 00011. There are many ways to achieve this. Additionally, if the size passed is less than the length of number, just return the number as a string. Let's have one that would be both useful and good performance-wise.

NOTES:

Numbers passed only - no strings, objects, functions, etc.

Whole positives only - negatives converted, decimals dropped (provided in solution setup)

*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string zerofill(int number, size_t size)
{
	auto result = format("{}", abs(number));
	if (size > result.size())
		result = string(size - result.size(), '0') + result;
	return result;
}

int main()
{
	assert(zerofill(11, 5) == "00011");
	return 0;
}
