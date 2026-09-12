/*

Method chaining is a very interesting way to keep your program clean.

As a part of this Kata, you need to create functions such that one could evaluate the following expression:

(3).add(5).multiply(2)
The above expression evaluates to be 16.

You need to implement the following methods:

add
subtract
multiply
divide
square

After you're done, one could chain these five methods to create chains of almost any length.

*/

#include <cassert>
#include <iostream>

using namespace std;

struct Number
{
	int value;

	Number(int value)
	{
		this->value = value;
	}

	Number add(int value)
	{
		return Number(this->value + value);
	}

	Number subtract(int value)
	{
		return Number(this->value - value);
	}

	Number multiply(int value)
	{
		return Number(this->value * value);
	}

	Number divide(int value)
	{
		return Number(this->value / value);
	}

	Number square()
	{
		return Number(this->value * this->value);
	}
};

ostream &operator<<(ostream &os, Number number)
{
	return os << number.value;
}

int main()
{
	cout << Number(3).add(5).multiply(2) << endl;
	cout << Number(2).square().square().square() << endl;
	return 0;
}
