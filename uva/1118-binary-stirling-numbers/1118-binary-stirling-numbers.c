#include <assert.h>

/*

https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind#Parity

S(n,m) = {n, m} = mS(n-1, m)+S(n-1, m-1)
{n, k} = C(z, w) mod 2
z = n - ceil((k+1)/2)
w = floor((k-1)/2)

*/

int
solve(int n, int m)
{
	int z, w;

	z = n - ((m + 2) / 2);
	w = (m - 1) / 2;
	return (z & w) == w;
}

int
main()
{
	assert(solve(4, 2) == 1);

	return 0;
}
