/*

An onion array is an array that satisfies the following condition for all values of j and k:

If all of the following are true:

j >= 0
k >= 0
j + k = array.length - 1
j != k
then:

a[j] + a[k] <= 10

Examples:
[1, 2, 19, 4, 5]   =>  true  (as 1+5 <= 10 and 2+4 <= 10)
[1, 2, 19, 4, 10]  =>  false (as 1+10 > 10)

Write a function named isOnionArray/IsOnionArray/is_onion_array() that returns true if its argument is an onion array and returns false if it is not.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
onion(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n / 2; i++) {
		if (a[i] + a[n - i - 1] > 10)
			return false;
	}
	return true;
}

int
main()
{
	int a1[] = {1, 2, 19, 4, 5};
	int a2[] = {1, 2, 19, 4, 10};

	assert(onion(a1, nelem(a1)) == true);
	assert(onion(a2, nelem(a2)) == false);
	return 0;
}
