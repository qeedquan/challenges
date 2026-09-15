/*

Implement abstract class Shape.

Implement classes Rectangle, Triangle that extend Shape.

Implement class Square that extends Rectangle.

abstract class Shape
{
  int a, b;
  Shape(int a, int b) // Constructor
  abstract int Perimeter(); // Perimeter
  abstract double Area(); // Area
}

class Rectangle extends Shape
{
  Rectangle(int a, int b) // Constructor
  public int Perimeter() // Perimeter of Rectangle
  public double Area() // Area of Rectangle
}

class Square extends Rectangle
{
  Square(int a) // Constructor
}

class Triangle extends Shape
{
  int c;
  Triangle (int a, int b, int c) // Constructor
  public int Perimeter() // Perimeter of Triangle
  public double Area() // Area of Triangle
}

Input
Each line contains one of three types of figures in the next format:

Square a

Rectangle a b

Triangle a b c

Output
For each figure print in a separate line its perimeter and area.

Examples

Input #1
Square 5
Rectangle 2 3
Triangle 3 4 5

Answer #1
20 25.0
10 6.0
12 6.0

*/

#include <cmath>
#include <print>

using namespace std;

class Shape
{
protected:
	int a, b;

public:
	Shape(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	virtual int Perimeter() = 0;
	virtual double Area() = 0;
};

class Rectangle : public Shape
{
public:
	Rectangle(int a, int b) : Shape(a, b)
	{
	}

	int Perimeter()
	{
		return 2 * (a + b);
	}

	double Area()
	{
		return a * b;
	}
};

class Square : public Rectangle
{
public:
	Square(int a) : Rectangle(a, a)
	{
	}
};

class Triangle : public Shape
{
private:
	int c;

public:
	Triangle(int a, int b, int c) : Shape(a, b)
	{
		this->c = c;
	}

	int Perimeter()
	{
		return a + b + c;
	}

	double Area()
	{
		double s = (a + b + c) / 2.0;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
};

int main()
{
	auto square = Square(5);
	auto rectangle = Rectangle(2, 3);
	auto triangle = Triangle(3, 4, 5);

	println("{} {}", square.Perimeter(), square.Area());
	println("{} {}", rectangle.Perimeter(), rectangle.Area());
	println("{} {}", triangle.Perimeter(), triangle.Area());

	return 0;
}
