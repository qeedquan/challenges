/*

Programming contests became so popular in the year 2397 that the governor of New Earck — the
largest human-inhabited planet of the galaxy — opened a special Alley of Contestant Memories (ACM)
at the local graveyard. The ACM encircles a green park, and holds the holographic statues of famous
contestants placed equidistantly along the park perimeter. The alley has to be renewed from time to
time when a new group of memorials arrives.
When new memorials are added, the exact place for each can be selected arbitrarily along the ACM,
but the equidistant disposition must be maintained by moving some of the old statues along the alley.
Surprisingly, humans are still quite superstitious in 24th century: the graveyard keepers believe
the holograms are holding dead people souls, and thus always try to renew the ACM with minimal
possible movements of existing statues (besides, the holographic equipment is very heavy). Statues are
moved along the park perimeter. Your work is to find a renewal plan which minimizes the sum of travel
distances of all statues. Installation of a new hologram adds no distance penalty, so choose the places
for newcomers wisely!

Input
The input file contains several test cases, each of them consists of a a line that contains two integer
numbers: n — the number of holographic statues initially located at the ACM, and m — the number
of statues to be added (2 ≤ n ≤ 1000, 1 ≤ m ≤ 1000). The length of the alley along the park perimeter
is exactly 10 000 feet.

Output
For each test case, write to the output a line with a single real number — the minimal sum of travel
distances of all statues (in feet). The answer must be precise to at least 4 digits after decimal point.
Note:
Pictures show the first three examples. Marked circles denote original statues, empty circles denote
new equidistant places, arrows denote movement plans for existing statues.

Sample Input
2 1
2 3
3 1
10 10

Sample Output
1666.6667
1000.0
1666.6667
0.0

*/

#include <stdio.h>
#include <math.h>

double
solve(int n, int m)
{
	double p, r;
	int i;

	r = 0;
	for (i = 1; i < n; i++) {
		p = (i * 1.0 / n) * (n + m);
		r += fabs(p - floor(p + 0.5)) / (n + m);
	}
	return r * 10000;
}

int
main()
{
	printf("%.4f\n", solve(2, 1));
	printf("%.4f\n", solve(2, 3));
	printf("%.4f\n", solve(3, 1));
	printf("%.4f\n", solve(10, 10));

	return 0;
}
