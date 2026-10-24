/*

You are provided with a skeleton of the class Fraction, which accepts two arguments (numerator, denominator).

Your task is to make this class string representable, and addable while keeping the result in the minimum representation possible.

Note: your class should not subclass fractions.Fraction

Example
fraction1 = Fraction(4, 5)
print(fraction1 + Fraction(1, 8))
# outputs: 37/40

Enjoy!

*/

#include <iostream>
#include <numeric>

using namespace std;

struct Fraction
{
	int top;
	int bottom;

	Fraction(int numerator, int denominator)
	{
		if (denominator == 0)
			throw "Denominator cannot be zero";
		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}

		auto multiple = gcd(numerator, denominator);
		top = numerator / multiple;
		bottom = denominator / multiple;
	}

	Fraction &operator=(const Fraction &other)
	{
		top = other.top;
		bottom = other.bottom;
		return *this;
	}

	bool operator==(const Fraction &other)
	{
		return top == other.top && bottom == other.bottom;
	}

	Fraction operator+(const Fraction &other)
	{
		return Fraction(top * other.bottom + other.top * bottom, bottom * other.bottom);
	}

	Fraction &operator+=(const Fraction &other)
	{
		*this = *this + other;
		return *this;
	}
};

ostream &operator<<(ostream &os, const Fraction &fraction)
{
	return os << fraction.top << '/' << fraction.bottom;
}

int main()
{
	auto fraction1 = Fraction(4, 5);
	cout << (fraction1 + Fraction(1, 8)) << endl;
	return 0;
}
