/*

The aim of this kata is to write function drawACross / draw_a_cross which returns a cross shape with 'x' characters on a square grid of size and height of our sole input n. All non-'x' characters in the grid should be filled with a space character (" ").

For example for drawACross(7) / draw_a_cross(7), the function should draw the following grid:

x     x
 x   x 
  x x  
   x   
  x x  
 x   x 
x     x

The arms of the cross must only intersect through one central 'x' character, and start in the corner of the grid, so for even values of n, return "Centered cross not possible!"

If n<3, function should return "Not possible to draw cross for grids less than 3x3!"

*/

#include <iostream>
#include <string>

using namespace std;

string cross(int n)
{
	if (n < 3)
		return "Not possible to draw cross for grids less than 3x3";
	if (!(n & 1))
		return "Centered cross not possible!";

	cout << "n=" << n << endl << endl;
	for (auto y = 0; y < n; y++)
	{
		for (auto x = 0; x < n; x++)
		{
			if (x == y || x == n - y - 1)
				cout << "x";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	return "Success";
}

int main()
{
	for (auto i = 3; i <= 11; i += 2)
		cross(i);
	return 0;
}
