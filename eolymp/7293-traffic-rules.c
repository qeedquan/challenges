/*

Stepan bought a car and decided to take his younger brother, Petryk, for a ride.
Petryk sat in the front passenger seat. Stepan immediately reminded him of the traffic rules in Ruthenia, which state: children shorter than 145 cm are not allowed to sit in the front seat.
Determine how many centimeters Petryk needs to grow to be allowed to sit in the front seat, given that his current height is N cm.

Input
The input consists of a single line containing the integer N (1≤N≤145).

Output
Output a single number representing the number of centimeters Petryk needs to grow.

Examples

Input #1
100

Answer #1
45

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int n)
{
	return max(145 - n, 0);
}

int
main()
{
	assert(solve(100) == 45);

	return 0;
}
