/*

Writing out numbers is among the Hello worlds of programming, often the numbers 1-10.

I want to write out many numbers! Many, Many numbers. But how many numbers do I have to write?

Task
Given an integer input, give a number as output that would give me the number of digits that would
be in a string containing all integer numbers in the range from 0 to the input, inclusive.
The negation identifier ("-") counts as a single character.

Example I/Os
Input: 8
Written out: 0,1,2,3,4,5,6,7,8
Output: 9

Input: 101
written out: 0,1,2,3....,99,100,101
Output: 196

Input: 102
written out: 0,1,2,3....,100,101,102
output: 199

Input -10
Written out: 0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10
output: 22

This is a code-golf. The lowest number of bytes wins!

*/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

int sign(int n)
{
	return (n >= 0) ? 1 : -1;
}

// https://oeis.org/A117804 (related)
int count(int n)
{
	string s = "";
	for (auto i = n; i != 0; i -= sign(n))
		s += to_string(i);
	return s.size() + 1;
}

int main()
{
	static const vector<int> tab =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28,
		30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60,
		62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92,
		94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120
	};

	assert(count(8) == 9);
	assert(count(101) == 196);
	assert(count(102) == 199);
	assert(count(-10) == 22);

	for (size_t i = 0; i < tab.size(); i++)
		assert(count(i) == tab[i]);

	return 0;
}
