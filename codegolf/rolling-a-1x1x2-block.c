/*

Rolling a 1x1x2 block
This challenge is inspired by the game Bloxorz. Like that game, there is a 1x1x2 block, which may be moved on a square grid in any of the four cardinal directions.
It moves by rotating 90 degrees about one of its edges which is touching the ground.
Initially, the block is standing upright on a single square in a square grid.
After some sequence of moves, determine whether it is:

Standing upright on the starting square,
Laying half-on, half-off the starting square, or
Not on the starting square at all.

Input
Input is given as a string consisting of the characters F, B, L, and R, which represent moving forward, backward, left, and right.

Output
Output can be 1, 0.5, or 0, representing the fraction of the block resting on the starting square. Your program may use some other set of three distinct outputs, as long as they consistently represent the three possibilities.

Test cases
"FFFBBB" -> 1
"" -> 1
"FRRRBLL" -> 1
"FRBL" -> 0.5
"FRBBL" -> 0

*/

#include <assert.h>

/*

@huanglx

Explanation
We store the direction the block is facing in variable d and the position of one side of the block in variable p.
We then use numbers 2 and 3 to represent the directions (with ±2 being forward/backward and ±3 being right/left), since 2 and 3 are linearly independent so we can represent any position that way with a single variable.

We then check if p equals 0 and if p+d equals 0, and add those values. If both p == 0 and p+d == 0, then we are standing upright on the origin.
If one of p == 0 and p+d == 0 is true, then we are sideways on the origin (since p is always tracking the same end of the block). If neither is true, then we are not on the origin.

*/

double
roll(const char *s)
{
	int d, p, n, r;

	for (d = p = 0; *s; s++) {
		switch (*s) {
		case 'F':
			n = 2;
			break;
		case 'B':
			n = -2;
			break;
		case 'L':
			n = 3;
			break;
		case 'R':
			n = -3;
			break;
		default:
			return -1;
		}

		if (d && d != n)
			p += n;
		else
			p += n * 2;

		if (d == -n || d == n)
			d = 0;
		else if (d == 0)
			d = -n;
	}

	r = !p + !(p + d);
	if (r == 2)
		return 1;
	if (r == 1)
		return 0.5;
	return 0;
}

int
main(void)
{
	assert(roll("FFFBBB") == 1);
	assert(roll("") == 1);
	assert(roll("FRRRBLL") == 1);
	assert(roll("FRBL") == 0.5);
	assert(roll("FRBBL") == 0);

	return 0;
}
