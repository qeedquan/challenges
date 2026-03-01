/*

Imagine two rings with numbers on them. The inner ring spins clockwise (decreasing by 1 each spin) and the outer ring spins counter clockwise (increasing by 1 each spin). We start with both rings aligned on 0 at the top, and on each move we spin each ring one increment. How many moves will it take before both rings show the same number at the top again?

The inner ring has integers from 0 to innerMax and the outer ring has integers from 0 to outerMax, where innerMax and outerMax are integers >= 1.

e.g. if innerMax is 2 and outerMax is 3 then after
1 move: inner = 2, outer = 1
2 moves: inner = 1, outer = 2
3 moves: inner = 0, outer = 3
4 moves: inner = 2, outer = 0
5 moves: inner = 1, outer = 1
Therefore it takes 5 moves for the two rings to reach the same number
Therefore spinningRings(2, 3) = 5

e.g. if innerMax is 3 and outerMax is 2 then after
1 move: inner = 3, outer = 1
2 moves: inner = 2, outer = 2
Therefore it takes 2 moves for the two rings to reach the same number
spinningRings(3, 2) = 2

*/

#include <assert.h>

int
spinning_rings(int inner_max, int outer_max)
{
	int current_inner;
	int current_outer;
	int counter;

	if (inner_max < 1 || outer_max < 1)
		return 0;

	current_inner = inner_max;
	current_outer = 1;
	counter = 1;
	while (current_inner != current_outer) {
		counter += 1;
		if (current_outer == outer_max)
			current_outer = 0;
		else
			current_outer += 1;

		if (current_inner == 0)
			current_inner = inner_max;
		else
			current_inner -= 1;
	}
	return counter;
}

int
main()
{
	assert(spinning_rings(2, 3) == 5);
	assert(spinning_rings(3, 2) == 2);

	return 0;
}
