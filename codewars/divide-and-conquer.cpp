/*

Given a mixed array of number and string representations of integers, add up the non-string integers and subtract the total of the string integers.

Return as a number.

*/

#include <iostream>
#include <cassert>
#include <variant>
#include <vector>

using namespace std;

typedef variant<int, char> Value;

int divcon(const vector<Value> &values)
{
	auto numbersum = 0;
	auto stringsum = 0;
	for (auto value : values)
	{
		if (holds_alternative<int>(value))
			numbersum += get<int>(value);
		else if (holds_alternative<char>(value))
			stringsum += get<char>(value) - '0';
	}
	return numbersum - stringsum;
}

int main()
{
	vector<Value> values_1 = { 9, 3, '7', '3' };
	vector<Value> values_2 = { '5', '0', 9, 3, 2, 1, '9', 6, 7 };
	vector<Value> values_3 = { '3', 6, 6, 0, '5', 8, 5, '6', 2, '0' };
	vector<Value> values_4 = { '1', '5', '8', 8, 9, 9, 2, '3' };
	vector<Value> values_5 = { 8, 0, 0, 8, 5, 7, 2, 3, 7, 8, 6, 7 };

	assert(divcon(values_1) == 2);
	assert(divcon(values_2) == 14);
	assert(divcon(values_3) == 13);
	assert(divcon(values_4) == 11);
	assert(divcon(values_5) == 61);

	return 0;
}
