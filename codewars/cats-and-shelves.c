/*

Description
An infinite number of shelves are arranged one above the other in a staggered fashion.
The cat can jump either one or three shelves at a time: from shelf i to shelf i+1 or i+3 (the cat cannot climb on the shelf directly above its head), according to the illustration:

                 ┌────────┐
                 │-6------│
                 └────────┘
┌────────┐
│------5-│
└────────┘  ┌─────► OK!
            │    ┌────────┐
            │    │-4------│
            │    └────────┘
┌────────┐  │
│------3-│  │
BANG!────┘  ├─────► OK!
  ▲  |\_/|  │    ┌────────┐
  │ ("^-^)  │    │-2------│
  │ )   (   │    └────────┘
┌─┴─┴───┴┬──┘
│------1-│
└────────┘

Input
Start and finish shelf numbers (always positive integers, finish no smaller than start)

Task
Find the minimum number of jumps to go from start to finish

Example
Start 1, finish 5, then answer is 2 (1 => 4 => 5 or 1 => 2 => 5)

*/

#include <assert.h>

unsigned
solutionbf(unsigned start, unsigned finish)
{
	unsigned count;

	if (finish <= start)
		return 0;

	for (count = 0; start < finish; count++) {
		if (start + 3 <= finish)
			start += 3;
		else
			start += 1;
	}
	return count;
}

unsigned
solution(unsigned start, unsigned finish)
{
	unsigned distance;

	if (finish <= start)
		return 0;

	distance = finish - start;
	return (distance / 3) + (distance % 3);
}

int
main()
{
	unsigned start, finish, limit;

	assert(solution(1, 5) == 2);
	assert(solution(1, 2) == 1);
	assert(solution(2, 2) == 0);
	assert(solution(2, 5) == 1);
	assert(solution(1, 3) == 2);

	limit = 5000;
	for (start = 0; start <= limit; start++) {
		for (finish = 0; finish <= limit; finish++)
			assert(solution(start, finish) == solutionbf(start, finish));
	}

	return 0;
}
