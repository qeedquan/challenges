/*

Your goal is to create a function to format a number given a template; if the number is not present, use the digits 1234567890 to fill in the spaces.

A few rules:

the template might consist of other numbers, special characters or the like: you need to replace only alphabetical characters (both lower- and uppercase);
if the given or default string representing the number is shorter than the template, just repeat it to fill all the spaces.
A few examples:

numericFormatter("xxx xxxxx xx","5465253289") === "546 52532 89"
numericFormatter("xxx xxxxx xx") === "123 45678 90"
numericFormatter("+555 aaaa bbbb", "18031978") === "+555 1803 1978"
numericFormatter("+555 aaaa bbbb") === "+555 1234 5678"
numericFormatter("xxxx yyyy zzzz") === "1234 5678 9012"

*/

#include <cassert>
#include <string>

using namespace std;

string numeric_formatter(const string &format, const string &number = "1234567890")
{
	string result = "";
	if (number.size() == 0)
		return result;

	size_t index = 0;
	for (auto symbol : format)
	{
		if ('a' <= symbol && symbol <= 'z')
		{
			result += number[index % number.size()];
			index += 1;
		}
		else
			result += symbol;
	}
	return result;
}

int main()
{
	assert(numeric_formatter("xxx xxxxx xx", "5465253289") == "546 52532 89");
	assert(numeric_formatter("xxx xxxxx xx") == "123 45678 90");
	assert(numeric_formatter("+555 aaaa bbbb", "18031978") == "+555 1803 1978");
	assert(numeric_formatter("xxx xxxxx xx", "5465253289") == "546 52532 89");
	assert(numeric_formatter("+555 aaaa bbbb") == "+555 1234 5678");
	assert(numeric_formatter("xxxx yyyy zzzz") == "1234 5678 9012");

	return 0;
}
