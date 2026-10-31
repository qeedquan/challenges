/*

Given an D-dimension array, where each axis is of length N, your goal is to find the sum of every index in the array starting from 0.

For Example if D=1 and N=10 then the answer would be 45 ([0,1,2,3,4,5,6,7,8,9]) If D=2 and N = 3 the answer is 18 which would be the sum of every number in the following:

[
[(0,0), (0,1), (0,2)],
[(1,0), (1,1), (1,2)],
[(2,0), (2,1), (2,2)]
]
A naive solution could be to loop over every index in every dimension and add to a global sum. This won't work as the number of dimension is expected to be quite large.

Hint: A formulaic approach would be best Hint 2: Gauss could solve the one dimensional case in his earliest of years, This is just a generalization.

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
supersum(uvlong d, uvlong n)
{
	return pow(n, d) * d * (n - 1) / 2;
}

int
main()
{
	assert(supersum(1, 1) == 0);
	assert(supersum(2, 2) == 4);
	assert(supersum(3, 3) == 81);
	assert(supersum(4, 4) == 1536);
	assert(supersum(5, 5) == 31250);
	assert(supersum(6, 6) == 699840);
	assert(supersum(7, 7) == 17294403);
	assert(supersum(8, 8) == 469762048);

	return 0;
}
