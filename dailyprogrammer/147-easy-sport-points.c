/*

You must write code that verifies the awarded points for a fictional sport are valid. This sport is a simplification of American Football scoring rules. This means that the score values must be any logical combination of the following four rewards:

6 points for a "touch-down"

3 points for a "field-goal"

1 point for an "extra-point"; can only be rewarded after a touch-down. Mutually-exclusive with "two-point conversion"

2 points for a "two-point conversion"; can only be rewarded after a touch-down. Mutually-exclusive with "extra-point"

A valid score could be 7, which can come from a single "touch-down" and then an "extra-point". Another example could be 6, from either a single "touch-down" or two "field-goals". 4 is not a valid score, since it cannot be formed by any well-combined rewards.

Formal Inputs & Outputs
Input Description
Input will consist of a single positive integer given on standard console input.

Output Description
Print "Valid Score" or "Invalid Score" based on the respective validity of the given score.

Sample Inputs & Outputs
Sample Input 1
35
Sample Output 1

Valid Score
Sample Input 2
2
Sample Output 2
Invalid Score

*/

#include <assert.h>

/*

@13467

Valid "units" of scores are:

bare touch-down (6 points)

touch-down → extra-point (6+1=7 points)

touch-down → two-point conversion (6+2=8 points)

field-goal (3 points)

So a valid score is a positive integer that can be expressed as a sum of {3, 6, 7, 8}. (In fact, the 6 here is redundant, because 6 can be represented as 3+3, but it makes things a bit easier later.)

n = 0 is a valid score, the empty sum.

0 < n < 3 is invalid: 3 is the smallest element in our set, so we can't build anything smaller than it. This rules out 1 and 2.

n = 3 is in the set, so is clearly valid.

3 < n < 6 is invalid: the only way you can break n down is 3 + (n-3), but then there's no way to build (n-3) as 0 < n-3 < 3 (see above.) This rules out 4 and 5.

For n ≥ 6, through Euclidean division, n can be written as 3q+r with 0 ≤ r < 3. Then n = 3q+r = 3(q-2)+(6+r). Here, 6 ≤ 6+r < 9 means 6+r is in the set, so 6+r is a valid score, and n ≥ 6 implies q ≥ 2, so 3(q-2) is also valid score (i.e. (q-2) field-goals.) Thus n is also valid.

We conclude that 1, 2, 4, and 5 are the only invalid scores.

To make this representation clearer, here are the first few sums:

n	Sum
0
1	(invalid)
2	(invalid)
3	3
4	(invalid)
5	(invalid)
6	6
7	7
8	8
9	6+3
10	7+3
11	8+3
12	6+3+3
13	7+3+3
14	8+3+3
15	6+3+3+3
16	7+3+3+3

*/

bool
valid(int n)
{
	switch (n) {
	case 1:
	case 2:
	case 4:
	case 5:
		return false;
	}
	return n >= 0;
}

int
main()
{
	assert(valid(35) == true);
	assert(valid(2) == false);
	assert(valid(5) == false);
	assert(valid(0) == true);

	return 0;
}
