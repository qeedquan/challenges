/*

Task
Ram lives in a house which is round in shape. The house has n entrances numbered from 1 to n. For each i in range 1..n-1 entrances i and i + 1 are adjacent; entrances 1 and n are also adjacent.

Ram's flat is located at entrance a. Each evening he goes for a walk around the house, counting the entrances he walks by. Today Ram decided to walk until he counts b entrances.

Help Ram to determine the number of the entrance near which he will be at the end of his walk.

Input/Output
Input:

integer n - The number of entrances, 1 ≤ n ≤ 200
integer a - The number of the entrance where Ram starts his walk, 1 ≤ a ≤ n
integer b - The number of entrances Ram wants to count, -100 000 ≤ b ≤ 100 000

Note:
if b > 0, Ram walks clockwise until he counts b entrances
if b < 0, Ram walks counterclockwise until he counts b entrances
if b = 0, Ram stays at his entrance and doesn't go anywhere

Output:

an integer - The number of the house at the end of his walk.

Examples
For n = 5, a = 1 and b = 3, the output should be 4: Ram will walk clockwise around the house, counting the entrances as follows: 1 -> 2 -> 3 -> 4

For n = 6, a = 2 and b = -5, the output should be 3: Ram will walk counterclockwise around the house, so he will count the entrances as follows: 2 -> 1 -> 6 -> 5 -> 4 -> 3q

*/

#include <assert.h>
#include <stdio.h>

int
sign(int x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

int
roundandround(int n, int a, int b)
{
	int s;

	s = sign(b);
	if (s == 0)
		return a;

	while (b) {
		b += -s;
		a = (a + s) % (n + 1);
		if (a <= 0)
			a = (s < 0) ? n : 1;
	}
	return a;
}

int
main()
{
	assert(roundandround(5, 1, 3) == 4);
	assert(roundandround(6, 2, -5) == 3);
	assert(roundandround(3, 2, 7) == 3);
	assert(roundandround(100, 1, -1) == 100);
	assert(roundandround(100, 54, 100) == 54);
	assert(roundandround(97, 37, -92) == 42);
	assert(roundandround(99, 41, 0) == 41);
	assert(roundandround(35, 34, 1) == 35);
	assert(roundandround(3, 2, -100) == 1);
	assert(roundandround(1, 1, -100) == 1);
	assert(roundandround(100, 1, -100000) == 1);
	assert(roundandround(333, 222, 111) == 333);
	
	return 0;
}
