/*

#It's show time! Archers have gathered from all around the world to participate in the Arrow Function Faire. But the faire will only start if there are archers signed and if they all have enough arrows in their quivers - at least 5 is the requirement! Are all the archers ready?

#Reference https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions

#Argument archers is an array of integers, in which each element corresponds to the number of arrows each archer has.

#Return Your function must return true if the requirements are met or false otherwise.

#Examples archersReady([1, 2, 3, 4, 5, 6, 7, 8]) returns false because there are archers with not enough arrows.

archersReady([5, 6, 7, 8]) returns true.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
ready(int *a, size_t n)
{
	size_t i;

	if (n == 0)
		return false;

	for (i = 0; i < n; i++) {
		if (a[i] < 5)
			return false;
	}
	return true;
}

int
main()
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int a2[] = {5, 6, 7, 8};

	assert(ready(a1, nelem(a1)) == false);
	assert(ready(a2, nelem(a2)) == true);
	return 0;
}
