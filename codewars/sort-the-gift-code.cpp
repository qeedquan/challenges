/*

Happy Holidays fellow Code Warriors!
Santa's senior gift organizer Elf developed a way to represent up to 26 gifts by assigning a unique alphabetical character to each gift. After each gift was assigned a character, the gift organizer Elf then joined the characters to form the gift ordering code.

Santa asked his organizer to order the characters in alphabetical order, but the Elf fell asleep from consuming too much hot chocolate and candy canes! Can you help him out?

Sort the Gift Code
Write a function called sortGiftCode/sort_gift_code/SortGiftCode that accepts a string containing up to 26 unique alphabetical characters, and returns a string containing the same characters in alphabetical order.

Examples (Input -- => Output):
"abcdef"                      -- => "abcdef"
"pqksuvy"                     -- => "kpqsuvy"
"zyxwvutsrqponmlkjihgfedcba"  -- => "abcdefghijklmnopqrstuvwxyz"

*/

#include <cassert>
#include <string>

using namespace std;

string sort_giftcode(const string &input)
{
	size_t count[256] = {};
	for (auto symbol : input)
		count[symbol & 0xff] += 1;

	string output;
	for (auto symbol = 0; symbol < 256; symbol++)
	{
		if (count[symbol])
			output += symbol;
	}
	return output;
}

int main()
{
	assert(sort_giftcode("abcdef") == "abcdef");
	assert(sort_giftcode("pqksuvy") == "kpqsuvy");
	assert(sort_giftcode("zyxwvutsrqponmlkjihgfedcba") == "abcdefghijklmnopqrstuvwxyz");

	return 0;
}
