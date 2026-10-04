/*

The bucket was filled with water and placed outside. The outside air temperature is t degrees. Print Water if t is positive, and Ice if t is zero or negative.

Input
The input contains one integer t (−10^9≤t≤10^9).

Output
Print Water if t is positive, and Ice if t is zero or negative.

Examples

Input #1
3

Answer #1
Water

Input #2
-6

Answer #2
Ice

*/

#include <cassert>
#include <string>

using namespace std;

string solve(int n)
{
	if (n > 0)
		return "Water";
	return "Ice";
}

int main()
{
	assert(solve(3) == "Water");
	assert(solve(-6) == "Ice");
	
	return 0;
}
