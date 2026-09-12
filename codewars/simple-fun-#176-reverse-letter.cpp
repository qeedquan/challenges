/*

Task
Given a string str, reverse it omitting all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".

Input/Output
[input] string str
A string consists of lowercase latin letters, digits and symbols.

[output] a string

*/

#include <cassert>
#include <string>

using namespace std;

string reverse_letter(const string &input)
{
	string output = "";
	for (auto i = input.size(); i > 0; i--)
	{
		if (isalpha(input[i - 1]))
			output += input[i - 1];
	}
	return output;
}

int main()
{
	assert(reverse_letter("krishan") == "nahsirk");
	assert(reverse_letter("ultr53o?n") == "nortlu");
	return 0;
}
