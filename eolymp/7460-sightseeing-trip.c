/*

The pupils from 10-B class decided in the autumn holiday to go on an excursion to the capital.
Knowing the number of boys n and girls m, determine how many rooms you need to book in a hotel,
if each room has k beds and it is forbidden to settle boys and girls together.

Input
One line contains three numbers n,m,k (n,m,k≤100).

Output
Print the number of rooms to book in the hotel.

Examples
Input #1
6 12 3

Answer #1
6

*/

#include <assert.h>

int
solve(int n, int m, int k)
{
	int r;

	if (k == 0)
		return 0;

	r = n / k;
	if (n % k)
		r += 1;

	r += m / k;
	if (m % k)
		r += 1;

	return r;
}

int
main()
{
	assert(solve(6, 12, 3) == 6);

	return 0;
}
