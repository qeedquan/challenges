/*

Task
In this task, you need to restore a string from a list of its copies.

You will receive an array of strings. All of them are supposed to be the same as the original but, unfortunately, they were corrupted which means some of the characters were replaced with asterisks ("*").

You have to restore the original string based on non-corrupted information you have. If in some cases it is not possible to determine what the original character was, use "#" character as a special marker for that.

If the array is empty, then return an empty string.

Examples:
input = [
  "a*cde",
  "*bcde",
  "abc*e"
]
result = "abcde"


input = [
  "a*c**",
  "**cd*",
  "a*cd*"
]
result = "a#cd#"

*/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

string assemble(const vector<string> &strings)
{
	string result = "";
	if (strings.size() == 0)
		return result;
	
	for (size_t i = 0; i < strings[0].size(); i++)
	{
		char symbol = '#';
		for (size_t j = 0; j < strings.size(); j++)
		{
			if (strings[j][i] != '*')
				symbol = strings[j][i];
		}
		result += symbol;
	}

	return result;
}

int main()
{
	const vector<string> strings1 = { "a*cde", "*bcde", "abc*e" };
	const vector<string> strings2 = { "a*c**", "**cd*", "a*cd*" };

	assert(assemble(strings1) == "abcde");
	assert(assemble(strings2) == "a#cd#");

	return 0;
}
