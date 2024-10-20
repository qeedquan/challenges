/*

The positive odd numbers are sorted in ascending order as 1,3,5,7,9,11,13,15,17,19 .... and grouped as
(1), (3,5), (7,9,11), (13,15,17,19),... and so on.

Thus, the first group is (1), the second group is (3,5), the third group is (7,9,11), etc.
In general, the group contains the next k elements of the sequence.

Given k, find the sum of the elements of the kth group. For example, for k=3, the answer is 27:

*/

#include <assert.h>

long
groupbf(long k)
{
	long i, s, p;

	s = 0;
	p = (k - 1) * k + 1;
	for (i = 0; i < k; i++)
		s += p + 2 * i;
	return s;
}

long
group(long k)
{
	return k * k * k;
}

int
main(void)
{
	long k;

	for (k = 0; k <= 100; k++)
		assert(group(k) == groupbf(k));

	return 0;
}
