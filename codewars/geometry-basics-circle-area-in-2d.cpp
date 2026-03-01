/*

This series of katas will introduce you to basics of doing geometry with computers.

Write the function circleArea/CircleArea which takes in a Circle object and calculates the area of that circle.
The Circle class can be seen below:

# Represents a Circle where center is a Point and radius is a Number
class Circle
  attr_accessor :center, :radius
  def initialize(center, radius) 
    @center = center 
    @radius = radius
  end
end
And the Point class can be seen below:

# Represents a Point where x and y are Numbers
class Point
  attr_accessor :x, :y
  def initialize(x, y)
    @x = x
    @y = y 
  end
end

*/

#include <cmath>
#include <iostream>

using namespace std;

struct Point
{
	double x, y;
};

struct Circle
{
	Point center;
	double radius;

	double area();
};

double Circle::area()
{
	return M_PI * radius * radius;
}

int main()
{
	auto circle1 = Circle{ { 10, 10 }, 30 };
	auto circle2 = Circle{ { 27, -70 }, 30 };
	auto circle3 = Circle{ { -15, 5 }, 0 };
	auto circle4 = Circle{ { -15, 5 }, 12.5 };

	cout << circle1.area() << endl;
	cout << circle2.area() << endl;
	cout << circle3.area() << endl;
	cout << circle4.area() << endl;

	return 0;
}
