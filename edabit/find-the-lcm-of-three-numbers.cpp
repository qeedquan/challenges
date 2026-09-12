/*

Create a function that takes an array of three numbers and returns the Least Common Multiple (LCM).

The LCM is the smallest positive number that is a multiple of two or more numbers. In our case, we are dealing with three numbers.

Multiples of 3 are: 3, 6, 9, 12, and so on.
Multiples of 4 are: 4, 8,12, and so on.
Multiples of 12 are: 12, 24, 36, and so on.
Thus, the least common multiple of 3, 4, and 12 is 12.

Examples
lcmThree(5, 7, 13) ➞ 455

lcmThree(104, 105, 107) ➞ 1168440

lcmThree(19, 47, 43) ➞ 38399

Notes
N/A

*/

#include <cassert>
#include <numeric>

using namespace std;

int lcm3(int x, auto ...xs)
{
	return ((x = lcm(x, xs)), ...);
}

int main()
{
	assert(lcm3(5, 7, 13) == 455);
	assert(lcm3(104, 105, 107) == 1168440);
	assert(lcm3(19, 47, 43) == 38399);
	assert(lcm3(3, 4, 12) == 12);
	assert(lcm3(6, 16, 348) == 1392);
	assert(lcm3(97, 103, 301) == 3007291);
	assert(lcm3(97, 997, 301) == 29109409);

	return 0;
}
