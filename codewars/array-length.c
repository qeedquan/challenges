/*

Define a macro that yields the length of the array it receives as parameter.

*/

#include <assert.h>
#include <stdio.h>

#define ARRAY_LENGTH(x) ((int)(sizeof(x) / sizeof(x[0])))

int
main()
{
	char arr1[] = "abcd";
	short arr2[] = { 80, 1000, 50 };
	int arr3[] = { 666, -333, 444, 999, 10, 11 };
	long arr4[] = { -1 };
	assert(ARRAY_LENGTH(arr1) == 5);
	assert(ARRAY_LENGTH(arr2) == 3);
	assert(ARRAY_LENGTH(arr3) == 6);
	assert(ARRAY_LENGTH(arr4) == 1);

	assert(ARRAY_LENGTH(((double[]){ 1, 2, 3, 4, 5, 6 })) == 6);
	assert(ARRAY_LENGTH(((float[]){ 1, 2, 3 })) == 3);

	assert(-ARRAY_LENGTH(((int[]){ 1, 2, 3, 4 })) == -4);
	assert(64 / ARRAY_LENGTH(((int[]){ 1, 2, 3, 4 })) / 2 == 8);

	size_t length = 666;
	int array[length];
	assert(ARRAY_LENGTH(array) == 666);

	int(*pointer)[666];
	assert(ARRAY_LENGTH(*pointer) == 666);

	short m3[2][3][4];
	assert(ARRAY_LENGTH(m3) == 2);
	assert(ARRAY_LENGTH(1 [m3]) == 3);
	assert(ARRAY_LENGTH(1 [m3][2]) == 4);

	return 0;
}
