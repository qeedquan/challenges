/*

Task
Your task is to calculate how many ways there are to attach an 1 × 1 Lego brick to an a(width) × b(height) Lego brick and your code length should less than 31 characters.

For an 2 x 4 Lego brick, the result should be 19

https://files.gitter.im/myjinxin2015/aMPy/blob

*/

#include <assert.h>

int
brickcombos(int a, int b)
{
	return (a * b * 3) - a - b + 1;
}

int
main()
{
	assert(brickcombos(2, 4) == 19);
	assert(brickcombos(3, 4) == 30);
	assert(brickcombos(2, 2) == 9);
	assert(brickcombos(1, 1) == 2);
	assert(brickcombos(55, 55) == 8966);
	assert(brickcombos(29, 3) == 230);
	return 0;
}
