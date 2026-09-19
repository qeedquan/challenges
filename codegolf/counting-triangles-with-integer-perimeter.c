/*

Mary has given John two sticks of lengths a and b respectively, where a and b are positive integers.

John is very curious.

He would like to know how many triangles with integer perimeter can be formed, by having one additional side.

Please help him find it out.

(This is my first time composing this kind of stupid stories in coding problems, so forgive me if it is too stupid.)

Specs
Given two integers a and b, find the number of triangles with integer perimeter that can be formed, by having one additional side.

Details
Congruent triangles are congruent.
Flat triangles are flat out uncounted.
Zero-sided triangles are counted zero times.

Scoring
This is code-golf. Shortest solution in bytes wins.

Testcases
a b output
1 2 1
3 3 5
9 7 13

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

/*

@Martin Ender

(Not quite rigorous) proof of correctness:

Let x = min(a,b) and y = max(a,b), and let z be a potential third side.
We can't have z ≤ y-x, because for z < y-x the triangle can't be closed and for z = y-x it would be degenerate. See triangle inequality.
We can't have z ≥ y+x, for the same reasons.
Every integer z in between is valid and gives a different triangle. That means we've got (y+x) - (y-x) - 1 = 2x - 1 different triangles.

*/

int
triangles(int a, int b)
{
	return (2 * min(a, b)) - 1;
}

int
main(void)
{
	assert(triangles(1, 2) == 1);
	assert(triangles(3, 3) == 5);
	assert(triangles(9, 7) == 13);
	assert(triangles(45, 135) == 89);

	return 0;
}
