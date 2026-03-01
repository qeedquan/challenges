/*

i is the imaginary unit, it is defined by i^2 = -1,
therefore it is a solution to x^2 + 1 = 0

Your Task
Complete the function pofi that returns i to the power of a given non-negative integer in its simplest form, as a string (answer may contain i).

*/

#include <cassert>
#include <string>

using namespace std;

string pofi(int n)
{
	static const string lut[] = { "1", "i", "-1", "-i" };
	return lut[n & 3];
}

int main()
{
	assert(pofi(0) == "1");
	assert(pofi(1) == "i");
	assert(pofi(2) == "-1");
	assert(pofi(3) == "-i");
	assert(pofi(4) == "1");
	assert(pofi(5) == "i");
	assert(pofi(6) == "-1");
	assert(pofi(7) == "-i");
	assert(pofi(8) == "1");
	assert(pofi(9) == "i");
	assert(pofi(10) == "-1");
	
	return 0;
}
