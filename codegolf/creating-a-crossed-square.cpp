/*

Creating a Crossed Square
You are to take input of an integer of one or more and output a square made of any printable character of your choice with a diagonal cross through the centre.

The general idea is for the output to be a hollow square that has a diagonal cross through it.:

Input: 7
Output:
*******
*#   #*
* # # *
*  #  *
* # # *
*#   #*
*******
In the above example the '*'s represent the outer box and the '#'s represent the diagonal cross.

Note that the above example uses two different characters so that it is easier to see what the output looks like, your program should use one character only.

Input

An integer of 1 or more, it is guaranteed to be odd.

Output

A square that is made up of a character of your choice with a cross through the middle.

The cross must be diagonal
The square may be output via the function or written to output
Trailing newlines are okay
Can output as a graphic, diagram or image if you wish too
Examples

Input: 1
Output:
*

Input: 3
Output:
***
***
***

Input: 5
Output:
*****
** **
* * *
** **
*****

Input: 7
Output:
*******
**   **
* * * *
*  *  *
* * * *
**   **
*******
Specs

Functions or full programs are allowed
You can get input by your preferred means
Standard loopholes are disallowed
Programs must work without any additional statements i.e. usings in C#, they must be included in the entry
You can output from a function or print the result
This is code golf so the shortest solution wins.

*/

#include <iostream>

using namespace std;

void square(int n)
{
	cout << "n=" << n << endl;
	for (auto y = 0; y < n; y++)
	{
		for (auto x = 0; x < n; x++)
		{
			if (n - 1 - y == x || y == x || y == 0 || x == 0 || y == n - 1 || x == n - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	square(1);
	square(3);
	square(5);
	square(7);
	return 0;
}
