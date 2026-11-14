/*

You are given two strings a and b such that length(a)≤50000 and length(b)≤5000.

Your task is to determine the first position i in string a such that the substring starting at position i is equal to b.

Input
The input consists of two lines: the first line contains string a, and the second line contains string b.

Output
Output a single line containing the position i.

Examples

Input #1
eeeabcabcabcdfff
abcabcd

Answer #1
7

*/

#include <cassert>
#include <string>
#include <print>

using namespace std;

size_t solve(const string &strings, const string &substring)
{
	auto index = strings.find(substring);
	if (index == string::npos)
		return index;
	return index + 1;
}

int main()
{
	assert(solve("eeeabcabcabcdfff", "abcabcd") == 7);

	return 0;
}
