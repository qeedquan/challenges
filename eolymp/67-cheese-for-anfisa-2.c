/*

After cutting cheese in the problem «Cheese for Anfisa», the owner was left with pieces of cheese in the form of rectangular parallelepipeds with integer side lengths.
To prepare a new dish for Anfisa, the owner needs to cut these pieces into cubes of side 1.
At each step, only one piece can be cut, and each cut divides a piece into two parts.
What is the minimum number of cuts required to divide the initial cheese piece into unit cubes?

Input
The input contains one line with three integers a, b, c (1≤a,b,c≤2⋅10^9) — the side lengths of the cheese piece.

Output
Print the minimum number of cuts required. It is guaranteed that this number does not exceed 10^18.

Examples

Input #1
2 3 4

Answer #1
23

*/

#include <assert.h>

int
solve(int a, int b, int c)
{
	return a * b * c - 1;
}

int
main()
{
	assert(solve(2, 3, 4) == 23);

	return 0;
}
