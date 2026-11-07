/*

Multiply two longs, but take care of overflow. If the result cannot be accurately stored in a long, throw an ArithmeticException.

*/

#include <climits>
#include <iostream>
#include <stdexcept>

using namespace std;

long multiply(long a, long b)
{
	long r;

	if (__builtin_mul_overflow(a, b, &r))
		throw runtime_error("Multiplication Overflow!");
	return r;
}

int main()
{
	cout << multiply(2, 3) << endl;
	cout << multiply(15, 15) << endl;

	try
	{
		multiply(LONG_MAX, LONG_MIN);
	}
	catch (runtime_error &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
