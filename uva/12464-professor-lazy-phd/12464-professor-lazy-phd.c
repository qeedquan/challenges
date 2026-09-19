#include <assert.h>

typedef long long vlong;

vlong
solve(vlong a, vlong b, vlong n)
{
	switch (n % 5) {
	case 0:
		return a;
	case 1:
		return b;
	case 2:
		return (1 + b) / a;
	case 3:
		return (1 + a + b) / (a * b);
	default:
		return (1 + a) / b;
	}
}

int
main()
{
	assert(solve(1, 1, 0) == 1);
	assert(solve(1, 2, 1) == 2);
	assert(solve(5, 9, 2) == 2);
	assert(solve(2, 3, 3) == 1);
	assert(solve(7, 4, 4) == 2);
	assert(solve(2109, 650790, 344341899059516) == 650790);
	assert(solve(45861686, 57, 594261603792314) == 804591);
	assert(solve(2309734, 21045930, 808597262407955) == 2309734);

	return 0;
}
