/*

Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

*/

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool xo(const string &input)
{
	size_t x = 0, o = 0;
	for (auto ch : input)
	{
		ch = toupper(ch);
		x += (ch == 'X');
		o += (ch == 'O');
	}
	return x == o;
}

int main()
{
	assert(xo("ooxx") == true);
	assert(xo("xooxx") == false);
	assert(xo("ooxXm") == true);
	assert(xo("zpzpzpp") == true);
	assert(xo("zzoo") == false);
	return 0;
}
