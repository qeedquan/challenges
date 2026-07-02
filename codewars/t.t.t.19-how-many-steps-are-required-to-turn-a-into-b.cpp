/*

Task
Complete the function howManyStep (or your languages equivalent) that accepts two numbers a and b (0 < a <= b).

This function will need to return the lowest number of steps required to turn a into b, by either doubling (a = a * 2) or incrementing by one (a = a + 1).

Examples
a=1, b=10 => 4
// 1+1=2, 2*2=4, 4+1=5, 5*2=10
a=1, b=17 => 5
// 1*2=2, 2*2=4, 4*2=8, 8*2=16, 16+1=17
a=1, b=64 => 6
// 1*2=2, 2*2=4, 4*2=8, 8*2=16, 16*2=32, 32*2=64
a=1, b=63 => 10
a=50, b=100 => 1
a=51, b=100 => 49
a=100, b=100 => 0

*/

#include <cassert>

int steps(int a, int b)
{
	auto s = 0;
	while (b > a)
	{
		if (!(b % 2) && (b / 2) >= a)
			b /= 2;
		else
			b -= 1;
		s += 1;
	}
	return s + a - b;
}

int main()
{
	assert(steps(1, 10) == 4);
	assert(steps(1, 17) == 5);
	assert(steps(1, 64) == 6);
	assert(steps(1, 63) == 10);
	assert(steps(50, 100) == 1);
	assert(steps(51, 100) == 49);
	assert(steps(100, 100) == 0);

	return 0;
}
