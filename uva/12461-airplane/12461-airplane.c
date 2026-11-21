#include <assert.h>
#include <string.h>

/*

F[1] = 1
F[2] = 0.5, 50% sit on his own seat
F[3] = 1/3*F[2] + 1/3 = 0.5
F[4] = 2/4*F[3] + 1/4 = 0.5

Pattern shows that it is all p=0.5 when n > 1

*/

const char *
solve(int n)
{
	if (n < 1)
		return "0/1";

	if (n == 1)
		return "1/1";

	return "1/2";
}

int
main()
{
	assert(!strcmp(solve(2), "1/2"));

	return 0;
}
