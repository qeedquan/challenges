#include <iostream>

using namespace std;

class Triangle
{
public:
	void triangle()
	{
		cout << "I am a triangle\n";
	}
};

class Isoceles : public Triangle
{
public:
	void isoceles()
	{
		cout << "I am an isoceles triangle\n";
	}
};

class Equilateral : public Isoceles
{
public:
	void equilateral()
	{
		cout << "I am an equilateral triangle\n";
	}
};

int main()
{
	Equilateral eqr;
	eqr.equilateral();
	eqr.isoceles();
	eqr.triangle();
	return 0;
}
