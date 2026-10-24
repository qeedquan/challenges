/*

Watch the Numberphile video to write a function that utilizes the formula Katie Steckles uses to solve the Mental Logs.

https://www.youtube.com/watch?v=AZRD5UkAm2Y

Your function will get an array with a mental log in each element, so 3847 is one stick with the numbers 3, 8, 4, and 7 below each other. (Picture, last log).
Katie tells you about the fact that the trick works with fewer than four sticks. Make your function so that it accepts n sticks.

Examples
mentalLogs([7593, 5687, 4628, 9485]) ➞ 29826

mentalLogs([2957, 8357, 3798, 2739]) ➞ 25591

mentalLogs([6428]) ➞ 20
Notes
The formula is very easy; you'll be able to solve the trick just by looking at the array input.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

ulong
mentallog(ulong *a, size_t n)
{
	size_t i;
	ulong r;

	r = 2;
	for (i = 0; i < n; i++)
		r = (r * 10) + ((a[i] / 10) % 10);
	return r - 2;
}

int
main(void)
{
	ulong a1[] = {7593, 5687, 4628, 9485};
	ulong a2[] = {9247, 9376, 8357, 3798};
	ulong a3[] = {7596, 9376};
	ulong a4[] = {7863, 2957, 8357};
	ulong a5[] = {9485, 9247, 7863, 7269};
	ulong a6[] = {5687, 8357, 9485, 9247};
	ulong a7[] = {2957, 8357, 3798, 2739};
	ulong a8[] = {6428};
	ulong a9[] = {9376};
	ulong a10[] = {3847, 7269};
	ulong a11[] = {5687, 8357, 6428, 3798, 5687};

	assert(mentallog(a1, nelem(a1)) == 29826);
	assert(mentallog(a2, nelem(a2)) == 24757);
	assert(mentallog(a3, nelem(a3)) == 295);
	assert(mentallog(a4, nelem(a4)) == 2653);
	assert(mentallog(a5, nelem(a5)) == 28464);
	assert(mentallog(a6, nelem(a6)) == 28582);
	assert(mentallog(a7, nelem(a7)) == 25591);
	assert(mentallog(a8, nelem(a8)) == 20);
	assert(mentallog(a9, nelem(a9)) == 25);
	assert(mentallog(a10, nelem(a10)) == 244);
	assert(mentallog(a11, nelem(a11)) == 285296);

	return 0;
}
