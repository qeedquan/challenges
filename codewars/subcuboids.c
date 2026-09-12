/*

Your Task

You have a cuboid with dimensions x,y,z ∈ ℕ. The values of x, y, and z are between 1 and 10^9. A subcuboid of this cuboid has dimensions length, width, height ∈ ℕ where 1≤length≤x, 1≤width≤y, 1≤height≤z. If two subcuboids have the same length, width, and height, but they are at different positions within the cuboid, they are distinct. Find the total number of subcuboids for the given cuboid.

Examples

See sample tests and the image below
27 subcuboids for a 2×2×2 cuboid

https://imgur.com/3CnboOW

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
triangular(uvlong n)
{
	return n * (n + 1) / 2;
}

uvlong
subcuboids(uvlong x, uvlong y, uvlong z)
{
	return triangular(x) * triangular(y) * triangular(z);
}

int
main()
{
	assert(subcuboids(1, 1, 1) == 1);
	assert(subcuboids(2, 2, 2) == 27);
	assert(subcuboids(2, 3, 3) == 108);
	assert(subcuboids(4, 5, 6) == 3150);
	assert(subcuboids(3, 7, 11) == 11088);
	return 0;
}
