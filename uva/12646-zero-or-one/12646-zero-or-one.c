#include <assert.h>

int
solve(int A, int B, int C)
{
	if (A == 0 && B == 1 && C == 1)
		return 'A';
	if (A == 1 && B == 0 && C == 0)
		return 'A';

	if (A == 1 && B == 0 && C == 1)
		return 'B';
	if (A == 0 && B == 1 && C == 0)
		return 'B';

	if (A == 1 && B == 1 && C == 0)
		return 'C';
	if (A == 0 && B == 0 && C == 1)
		return 'C';

	return '*';
}

int
main()
{
	assert(solve(1, 1, 0) == 'C');
	assert(solve(0, 0, 0) == '*');
	assert(solve(1, 0, 0) == 'A');

	return 0;
}
