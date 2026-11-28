/*

Task
You're given an equation that consists of numbers, parenthesis and operations '+' and '-'. But you don't want just to calculate it's result the way ordinary people do. You have your own rules of calculation!

Remove all whitespaces from the equation (who needs them anyway)?
Calculate the sum of even digits in it. If there's a - symbol just before the digit, you consider it as a negative number.
Calculate the sum of odd digits, paying attention to the - symbols as well.
Subtract the sum of the odd digits from the sum of even digits. The obtained result is the result of the equation.
Now you need to write a program that does this kind of calculation for you. Given an equation, calculate it's value with your very own algorithm.

Note: the given equation can be confusing and invalid ;-)

Input/Output
[input] string equation

An equation (not necessarily correct) consisting of digits, parenthesis and operators - and +

0 ≤ equation.length ≤ 100

[output] an integer

Result of the equation.

Examples
For equation (-100) + 100 - (-200) + 1, the output should be -3

remove the whitespaces: (-100)+100-(-200)+1
sum the even digits: -2
sum the odd digits: -1 + 1 + 1 = 1
calculate the difference: -2 - 1 = -3
For equation (-25) + (-75) + 50 - 40 - (22 + 2), the output should be -8

remove the whitespaces: (-25)+(-75)+50-40-(22+2)
sum the even digits: -2 - 4 + 2 + 2 + 2 = 0
sum the odd digits: 5 - 7 + 5 + 5 = 8
calculate the difference: 0 - 8 = -8

*/

#include <cassert>
#include <string>

using namespace std;

int sumdiff(const string &input)
{
	auto total = 0;
	auto sign = 1;
	size_t index = 0;
	size_t length = input.size();
	for (;;)
	{
		while (index < length && isspace(input[index]))
			index++;

		if (index >= length)
			break;

		auto symbol = input[index++];
		switch (symbol)
		{
		case '2':
		case '4':
		case '6':
		case '8':
			total += sign * (symbol - '0');
			break;

		case '1':
		case '3':
		case '5':
		case '7':
		case '9':
			total -= sign * (symbol - '0');
			break;

		case '-':
			sign = -1;
			continue;
		}
		sign = 1;
	}
	return total;
}

int main()
{
	assert(sumdiff("(-100) + 100  - (-200) + 1") == -3);
	assert(sumdiff("(-25) + (-75) + 50 - 40 - (22 + 2)") == -8);
	assert(sumdiff("999 + 999 + 999 + 888 + 888 - (-777)") == -40);
	assert(sumdiff("(-25) + (-75 )+ 50 - (-40 ) - (-80)") == -22);
	assert(sumdiff("(2-262+(+))7182(++1 ") == 9);
	assert(sumdiff("49)-3044203+571+7335 ") == -26);
	assert(sumdiff("") == 0);

	return 0;
}
