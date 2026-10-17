/*

Hey Codewarrior!

You already implemented a Cube class, but now we need your help again! I'm talking about constructors. We don't have one. Let's code two: One taking an integer and one handling no given arguments!

Also we got a problem with negative values. Correct the code so negative values will be switched to positive ones!

The constructor taking no arguments should assign 0 to Cube's Side property.

*/

#include <iostream>
#include <cmath>

using namespace std;

class Cube
{
	int side;

public:
	Cube()
	{
		side = 0;
	}

	Cube(int side)
	{
		set(side);
	}

	void set(int side)
	{
		this->side = abs(side);
	}

	int get()
	{
		return side;
	}
};

int main()
{
	Cube cube;
	cout << cube.get() << endl;
	cube.set(-20);
	cout << cube.get() << endl;
	return 0;
}
