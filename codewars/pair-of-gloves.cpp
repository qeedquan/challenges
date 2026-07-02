/*

Pair of gloves
Winter is coming, you must prepare your ski holidays. The objective of this kata is to determine the number of pair of gloves you can constitute from the gloves you have in your drawer.

Given an array describing the color of each glove, return the number of pairs you can constitute, assuming that only gloves of the same color can form pairs.

Examples:
input = ["red", "green", "red", "blue", "blue"]
result = 2 (1 red pair + 1 blue pair)

input = ["red", "red", "red", "red", "red", "red"]
result = 3 (3 red pairs)

*/

#include <cassert>
#include <vector>
#include <string>
#include <map>

using namespace std;

size_t pairs(const vector<string> &colors)
{
	size_t count = 0;
	map<string, size_t> seen;
	for (auto &color : colors)
	{
		seen[color] += 1;
		if (!(seen[color] & 1))
			count += 1;
	}
	return count;
}

int main()
{
	assert(pairs({ "red", "green", "red", "blue", "blue" }) == 2);
	assert(pairs({ "red", "red", "red", "red", "red", "red" }) == 3);
	return 0;
}
