/*

Task
You are given a big cube, made up of several little cubes. You paint the outside of the big cube and are now supposed to find out how many of the little cubes have zero faces painted, one face painted, two faces painted, etc.

Write a function which accepts two parameters:

length: the side length of the big cube (in little cubes), 0 <= length <= 50
n: the number of faces painted, 0 <= n <= 7
You have to figure out how many of the little cubes have n faces painted.

Example
painted_faces(4,3)

=> result: 8  # Only the vertices of the big cube will have three faces painted
If n > 3 then return 0 as it is not possible for a painted cube to have more than 3 sides painted (unless s == 1, in that case it will have 6 faces painted).

*/

#include <assert.h>
#include <stdio.h>

int
painted_faces(int l, int n)
{
	if (l < 1 || n < 0)
		return 0;
	if (l == 1)
		return n == 6;
	if (n == 3)
		return 8;
	if (n == 2)
		return 12 * (l - 2);
	if (n == 1)
		return 6 * (l - 2) * (l - 2);
	if (n == 0)
		return (l - 2) * (l - 2) * (l - 2);
	return 0;
}

int
main()
{
	assert(painted_faces(4, 3) == 8);
	assert(painted_faces(5, 1) == 54);
	assert(painted_faces(10, 2) == 96);
	assert(painted_faces(2, 2) == 0);
	assert(painted_faces(9, 0) == 343);
	assert(painted_faces(7, 4) == 0);
	assert(painted_faces(1, 0) == 0);
	assert(painted_faces(1, 1) == 0);
	assert(painted_faces(1, 2) == 0);
	assert(painted_faces(1, 3) == 0);
	assert(painted_faces(1, 4) == 0);
	assert(painted_faces(1, 5) == 0);
	assert(painted_faces(1, 6) == 1);
	assert(painted_faces(2, 0) == 0);
	assert(painted_faces(2, 1) == 0);
	assert(painted_faces(2, 2) == 0);
	assert(painted_faces(2, 3) == 8);
	assert(painted_faces(2, 4) == 0);
	assert(painted_faces(2, 5) == 0);
	assert(painted_faces(2, 6) == 0);

	return 0;
}
