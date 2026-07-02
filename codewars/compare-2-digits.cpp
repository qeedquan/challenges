/*

You are given 2 two-digit numbers. You should check if they are similar by comparing their numbers, and return the result in %.

Example:

compare(13,14)=50%;
compare(23,22)=50%;
compare(15,51)=100%;
compare(12,34)=0%.

*/

#include <cassert>
#include <string>
#include <format>

using namespace std;

string compare(int number0, int number1)
{
	int digits0[] = { number0 % 10, number0 / 10 };
	int digits1[] = { number1 % 10, number1 / 10 };

	auto seen = 0;
	auto count = 0;
	for (auto index0 = 0; index0 < 2; index0++)
	{
		for (auto index1 = 0; index1 < 2; index1++)
		{
			auto mask = (1 << index0) | (1 << (2 + index1));
			if (seen & mask)
				continue;

			if (digits0[index0] == digits1[index1])
			{
				seen |= mask;
				count += 2;
			}
		}
	}
	return format("{}%", count * 25);
}

int main()
{
	assert(compare(13, 14) == "50%");
	assert(compare(23, 22) == "50%");
	assert(compare(15, 51) == "100%");
	assert(compare(12, 34) == "0%");
	return 0;
}
