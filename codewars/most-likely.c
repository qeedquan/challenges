/*

Create a function which compares two probabilities, returning true if the first one is most likely otherwise false.

For this exercise probability is expressed as two numbers separated by a colon e.g. a probability of 1 in 3 will be 1:3.

So:

Input: ('1:3','1:2') - returns false as 1 in 3 is less likely than 1 in 2.

*/

#include <assert.h>
#include <stdio.h>

int
mostlikely(const char *s1, const char *s2)
{
	int n1, n2;
	int d1, d2;
	int p1, p2;

	if (sscanf(s1, "%d:%d", &n1, &d1) != 2)
		return -1;
	if (sscanf(s2, "%d:%d", &n2, &d2) != 2)
		return -1;

	p1 = n1 * d2;
	p2 = n2 * d1;
	return p1 > p2;
}

int
main()
{
	assert(mostlikely("1:3", "1:2") == 0);
	assert(mostlikely("2:3", "1:2") == 1);
	assert(mostlikely("10:5", "10:20") == 1);
	assert(mostlikely("10:500", "10:20") == 0);

	return 0;
}
