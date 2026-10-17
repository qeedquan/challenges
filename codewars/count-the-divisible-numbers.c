/*

Complete the function that takes 3 numbers x, y and k (where x ≤ y), and returns the number of integers within the range [x..y] (both ends included) that are divisible by k.

More scientifically: { i : x ≤ i ≤ y, i mod k = 0 }
Example

Given x = 6, y = 11, k = 2 the function should return 3, because there are three numbers divisible by 2 between 6 and 11: 6, 8, 10

    Note: The test cases are very large. You will need a O(log n) solution or better to pass. (A constant time solution is possible.)

*/

#include <assert.h>

long
divisiblecount(long x, long y, long k)
{
	if (k < 1)
		return 0;
	return (y / k) - (x / k) + !(x % k);
}

int
main()
{
	assert(divisiblecount(6, 11, 2) == 3);
	assert(divisiblecount(20, 20, 8) == 0);

	return 0;
}
