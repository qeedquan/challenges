/*

Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length l, breadth b, and height h.

The default constructor of the class should initialize l, b, and h to 0.

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l, b and h to length, breadth and height.

The copy constructor Box(Box B) should set l, b and h to B's l, b and h, respectively.

Apart from the above, the class should have 4 functions:

int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box

Overload the operator < for the class Box. Box A < Box B if:

1. A.l < B.l
2. A.b < B.b and A.l == B.l
3. A.h < B.h and A.h == B.b and A.l == B.l
Overload operator  for the class Box().
If B is an object of class Box:

cout << B should print B.l, B.b and B.h on a single line separated by spaces.

For example,

Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength();	// Should return 2
b2.getBreadth(); // Should return 3
b2.getheight();	// Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2);	// Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.

Constraints
0 <= l, b, h <= 10^5

Two boxes being compared using the  operator will not have all three dimensions equal.

*/

#include <iostream>
#include <cassert>

using namespace std;

class Box
{
private:
	int length = 0;
	int breadth = 0;
	int height = 0;

public:
	Box() = default;

	Box(int length, int breadth, int height)
		: length(length), breadth(breadth), height(height)
	{
	}

	int getLength() const
	{
		return length;
	}

	int getBreadth() const
	{
		return breadth;
	}

	int getHeight() const
	{
		return height;
	}

	long long CalculateVolume() const
	{
		return length * breadth * height;
	}

	bool operator<(const Box &other)
	{
		if (length < other.length)
			return true;
		if (length > other.length)
			return false;

		if (breadth < other.breadth)
			return true;
		if (breadth > other.breadth)
			return false;

		if (height < other.height)
			return true;
		return false;
	}

	friend ostream &operator<<(ostream &stream, const Box &box);
};

ostream &operator<<(ostream &stream, const Box &box)
{
	stream << box.length << ' ' << box.breadth << ' ' << box.height;
	return stream;
}

int main()
{
	Box b1;
	Box b2(2, 3, 4);
	assert(b2.getLength() == 2);
	assert(b2.getBreadth() == 3);
	assert(b2.getHeight() == 4);
	assert(b2.CalculateVolume() == 24);
	assert(b1 < b2);
	cout << b2 << endl;
	cout << b1 << endl;

	return 0;
}
