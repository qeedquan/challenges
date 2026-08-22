/*

In the world of Draenor, orcs are a formidable race known for their strength and courage in battle, though not particularly for their intelligence.
Each year, orcs from various clans gather in the Valley of Strength to select the leader of the Horde.
Unlike humans, orcs do not use votes, ballots, or polling stations—these are foreign concepts to them.
Instead, they determine their leader through a series of fair duels.

In each duel, two candidates face off, with one emerging as the victor and the other being defeated.
An orc who loses a duel is eliminated and cannot participate in any subsequent contests.
The last orc remaining after all duels becomes the leader of the Horde.

The orc elders, who oversee these contests, enjoy predicting the outcomes.
However, predicting the overall winner or even the victor of a specific duel is not always straightforward.
The outcome depends on the strength of the opponents: usually, the stronger orc wins.
But if two orcs have equal strength, the result is uncertain and could go either way, depending on fate.

The elders have asked you to develop a program that determines how many contenders have a chance to become the leader.

Input
The first line contains the number N of contenders for the leadership this year (1≤N≤1000000).
The second line contains N integers, each from 1 to 10000, representing the strength of each candidate.

Output
Output one integer—the number of contenders who have a chance to become the leader.

Examples
Input #1
5
1 2 3 4 5

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int *a, size_t n)
{
	size_t i;
	int m, r;

	m = r = 0;
	for (i = 0; i < n; i++) {
		if (m < a[i]) {
			m = a[i];
			r = 1;
		} else if (m == a[i])
			r += 1;
	}
	return r;
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5 };

	assert(solve(a1, nelem(a1)) == 1);

	return 0;
}
