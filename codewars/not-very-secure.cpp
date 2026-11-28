/*

In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None, so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces / underscore

*/

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

bool alphanumeric(const string &input)
{
	if (input.size() < 1)
		return false;

	for (auto ch : input)
	{
		if (!isalnum(ch))
			return false;
	}
	return true;
}

int main()
{
	assert(alphanumeric("") == false);
	assert(alphanumeric("hello world_") == false);
	assert(alphanumeric("HELLOworld123") == true);
	return 0;
}
