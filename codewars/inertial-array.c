/*

An array is defined to be inertial if the following conditions hold:

a. it contains at least one odd value
b. the maximum value in the array is even
c. every odd value is greater than every even value that is not the maximum value.

eg:-

So [11, 4, 20, 9, 2, 8] is inertial because
a. it contains at least one odd value [11,9]
b. the maximum value in the array is 20 which is even
c. the two odd values (11 and 9) are greater than all the even values that are not equal to 20 (the maximum), i.e., [4, 2, 8]

Write a function called is_inertial that accepts an integer array and returns true if the array is inertial; otherwise it returns false.q

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
inertial(int *array, size_t length)
{
	size_t index;
	size_t odds;
	int low;
	int high;

	odds = 0;
	low = INT_MAX;
	high = INT_MIN;
	for (index = 0; index < length; index++) {
		if (array[index] & 1) {
			odds += 1;
			low = min(low, array[index]);
		}
		high = max(high, array[index]);
	}

	if (odds < 1 || high & 1)
		return false;

	for (index = 0; index < length; index++) {
		if (array[index] & 1)
			continue;
		if (array[index] == high)
			continue;
		if (array[index] > low)
			return false;
	}

	return true;
}

int
main()
{
	int array_1[] = { 11, 4, 20, 9, 2, 8 };

	assert(inertial(array_1, nelem(array_1)) == true);

	return 0;
}
