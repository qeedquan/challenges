/*

Task
Write function which validates an input string. If the string is a perfect square return true,false otherwise.

What is perfect square?
* We assume that character '.' (dot) is a perfect square (1x1) * Perfect squares can only contain '.' (dot) and optionally '\n' (line feed) characters.
* Perfect squares must have same width and height -> cpt.Obvious
* Squares of random sizes will be tested!
Function input:
perfectSquare = "...\n...\n...";    

// This represents the following Perfect Square:

`...
 ...
 ...`
                               
notPerfect = "..,\n..\n...";

// This is not a Perfect Square:

`..,
 ..
 ...`

*/

#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

bool perfect_square(const string &s)
{
	auto w = -1;
	auto h = 1;
	auto x = 0;
	for (auto c : s)
	{
		if (c == '\n')
		{
			if (w < 0)
				w = x;
			else if (x != w)
				return false;

			x = 0;
			h += 1;
		}
		else if (c != '.')
			return false;
		else
			x += 1;
	}
	if (w < 0)
		w = x;

	return w == h;
}

int main()
{
	assert(perfect_square("") == false);
	assert(perfect_square(".") == true);
	assert(perfect_square("..\n..") == true);
	assert(perfect_square("...\n...\n...") == true);
	assert(perfect_square("..,\n..\n...") == false);

	return 0;
}
