/*

Write a function that receives two strings and returns n, where n is equal to the number of characters we should shift the first string forward to match the second. The check should be case sensitive.

For instance, take the strings "fatigue" and "tiguefa". In this case, the first string has been rotated 5 characters forward to produce the second string, so 5 would be returned.

If the second string isn't a valid rotation of the first string, the method returns -1.
Examples:
"coffee", "eecoff" => 2
"eecoff", "coffee" => 4
"moose", "Moose" => -1
"isn't", "'tisn" => 2
"Esham", "Esham" => 0
"dog", "god" => -1

*/

#include <cassert>
#include <string>

using namespace std;

ssize_t shifted_diff(const string &first, const string &second)
{
	if (first.size() != second.size())
		return -1;
	
	auto haystack = second + second;
	auto location = haystack.find(first);
	if (location == string::npos)
		return -1;

	return location;
}

int main()
{
	assert(shifted_diff("fatigue", "tiguefa") == 5);
	assert(shifted_diff("coffee", "eecoff") == 2);
	assert(shifted_diff("eecoff", "coffee") == 4);
	assert(shifted_diff("moose", "Moose") == -1);
	assert(shifted_diff("isn't", "'tisn") == 2);
	assert(shifted_diff("Esham", "Esham") == 0);
	assert(shifted_diff("dog", "god") == -1);

	return 0;
}
