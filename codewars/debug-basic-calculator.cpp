/*

Debug a function called calculate that takes 3 values. The first and third values are numbers. The second value is a character. If the character is "+" , "-", "*", or "/", the function will return the result of the corresponding mathematical function on the two numbers. If the string is not one of the specified characters, the function should return null.

calculate(2,"+", 4); //Should return 6
calculate(6,"-", 1.5); //Should return 4.5
calculate(-4,"*", 8); //Should return -32
calculate(49,"/", -7); //Should return -7
calculate(8,"m", 2); //Should return null
calculate(4,"/",0) //should return null

*/

#include <cassert>
#include <cmath>

using namespace std;

double calculate(double a, int op, double b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b)
			return a / b;
		break;
	}
	return NAN;
}

int main()
{
	assert(calculate(2, '+', 4) == 6);
	assert(calculate(6, '-', 1.5) == 4.5);
	assert(calculate(-4, '*', 8) == -32);
	assert(calculate(49, '/', -7) == -7);
	assert(isnan(calculate(8, 'm', 2)));
	assert(isnan(calculate(4, '/', 0)));

	return 0;
}
