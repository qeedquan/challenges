/*

Task
Given an integer n, find the maximal number you can obtain by deleting exactly one digit of the given number.

Example
For n = 152, the output should be 52;

For n = 1001, the output should be 101.

Input/Output
[input] integer n

Constraints: 10 ≤ n ≤ 1000000.

[output] an integer

*/

#include <cassert>
#include <iostream>
#include <format>

using namespace std;

int delete_digit(int n)
{
	if (n < 0)
		return 0;

	auto m = 0;
	auto s = format("{}", n);
	for (size_t i = 0; i < s.size(); i++)
	{
		auto t = s.substr(0, i) + s.substr(i + 1);
		if (t != "")
			m = max(m, stoi(t));
	}
	return m;
}

int main()
{
	assert(delete_digit(152) == 52);
	assert(delete_digit(1001) == 101);
	assert(delete_digit(10) == 1);

	return 0;
}
