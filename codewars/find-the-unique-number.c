/*

There is an array with some numbers. All numbers are equal except for one. Try to find it!

findUniq([ 1, 1, 1, 2, 1, 1 ]) === 2
findUniq([ 0, 0, 0.55, 0, 0 ]) === 0.55
It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
unique(double *array, size_t size)
{
	double value[2];
	double count[2];
	size_t index;
	size_t length;

	memset(value, 0, sizeof(value));
	memset(count, 0, sizeof(count));
	length = 0;
	for (index = 0; index < size; index++) {
		if (length > 0 && value[0] == array[index])
			count[0] += 1;
		else if (length > 1 && value[1] == array[index])
			count[1] += 1;
		else if (length < 2) {
			count[length] += 1;
			value[length] = array[index];
			length += 1;
		}

		if (length == 2) {
			if (count[0] >= 2)
				return value[1];
			if (count[1] >= 2)
				return value[0];
		}
	}
	return NAN;
}

int
main()
{
	double array_1[] = { 1, 1, 1, 2, 1, 1 };
	double array_2[] = { 0, 0, 0.55, 0, 0 };
	double array_3[] = { 999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999, 999.666 };

	assert(unique(array_1, nelem(array_1)) == 2);
	assert(unique(array_2, nelem(array_2)) == 0.55);
	assert(unique(array_3, nelem(array_3)) == 999);

	return 0;
}
