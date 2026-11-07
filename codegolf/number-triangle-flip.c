/*

Say you list the positive integers in a triangle, then flip it left-to-right. Given a number, output the number it's sent to. This is a self-inverse mapping.

         1                      1
       2   3                  3   2
     4   5   6    <--->     6   5   4
   7   8   9  10         10   9   8   7
11  12  13  14  15     15  14  13  12  11
This is the n'th element of A038722, one-indexed:

1, 3, 2, 6, 5, 4, 10, 9, 8, 7, 15, 14, 13, 12, 11, ...
This sequence reverses contiguous chunks of the positive integers with increasing lengths:

 1, 3, 2, 6, 5, 4, 10, 9, 8, 7, 15, 14, 13, 12, 11, ...
<-><----><-------><-----------><------------------>
Test cases:

1 -> 1
2 -> 3
3 -> 2
4 -> 6
14 -> 12
990 -> 947
991 -> 1035
1000 -> 1026
1035 -> 991
1036 -> 1081
12345 -> 12305

*/

#include <assert.h>
#include <math.h>

// https://oeis.org/A038722
int
triflips(int n)
{
	int x;

	if (n <= 0)
		return 0;

	x = ceil((sqrt((8 * n) + 1) - 1) / 2);
	return (x * x) - n + 1;
}

int
main(void)
{
	assert(triflips(1) == 1);
	assert(triflips(2) == 3);
	assert(triflips(4) == 6);
	assert(triflips(14) == 12);
	assert(triflips(990) == 947);
	assert(triflips(991) == 1035);
	assert(triflips(1000) == 1026);
	assert(triflips(1035) == 991);
	assert(triflips(1036) == 1081);
	assert(triflips(12345) == 12305);

	return 0;
}
