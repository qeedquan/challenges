/*

Task
Given a positive integer as input, return the output as a string in the following format:

Each element, corresponding to a digit of the number, multiplied by a power of 10 in such a way that with the sum of these elements you can obtain the original number.

Examples
Input   Output
0       ""
56      "5*10+6"
60      "6*10"
999     "9*100+9*10+9"
10004   "1*10000+4"
Note: input >= 0

*/

#include <cassert>
#include <format>
#include <iostream>
#include <string>

using namespace std;

string simplify(unsigned number)
{
	string output = "";
	for (auto exponent = 1u; number > 0; number /= 10)
	{
		auto digit = number % 10;
		if (digit)
		{
			auto temporary = format("{}", digit);
			if (exponent > 1)
				temporary += format("*{}+", exponent);
			output = temporary + output;
		}
		exponent *= 10;
	}
	if (output.ends_with("+"))
		output = output.substr(0, output.size() - 1);
	return output;
}

int main()
{
	assert(simplify(0) == "");
	assert(simplify(56) == "5*10+6");
	assert(simplify(60) == "6*10");
	assert(simplify(999) == "9*100+9*10+9");
	assert(simplify(10004) == "1*10000+4");
	
	return 0;
}
