/*

Cubes in the box
Your job is to write a function f(x,y,z) to count how many cubes of any size can fit inside a x*y*z box. For example, a 2*2*3 box has 12 1*1*1 cubes, 2 2*2*2 cubes, so a total of 14 cubes in the end. See the animation below for a visual description of the task!

Notes:
x,y,z are strictly positive and will not be too big.

https://i.ibb.co/KXzMQkC/cube.gif

Animation made by AwesomeAD

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cubes(int x, int y, int z)
{
	int s, r;
	int i;

	r = 0;
	s = min(x, min(y, z));
	for (i = 0; i < s; i++)
		r += (x - i) * (y - i) * (z - i);
	return r;
}

int
main()
{
	assert(cubes(2, 2, 3) == 14);
	assert(cubes(3, 3, 3) == 36);
	return 0;
}
