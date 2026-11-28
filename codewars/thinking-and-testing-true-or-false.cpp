/*

No Story

No Description

Only by Thinking and Testing

Look at the results of the testcases, and guess the code!

*/

#include <cassert>
#include <bit>

using namespace std;

constexpr auto solve = popcount<unsigned>;

int main()
{
	assert(solve(0) == 0);
	assert(solve(1) == 1);

	assert(solve(2) == 1);
	assert(solve(3) == 2);

	assert(solve(4) == 1);
	assert(solve(5) == 2);
	assert(solve(6) == 2);
	assert(solve(7) == 3);

	assert(solve(8) == 1);
	assert(solve(9) == 2);
	assert(solve(10) == 2);
	assert(solve(100) == 3);
	assert(solve(1000) == 6);
	assert(solve(10000) == 5);

	return 0;
}
