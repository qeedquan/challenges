/*

You are given two integer arrays energyDrinkA and energyDrinkB of the same length n by a futuristic sports scientist.
These arrays represent the energy boosts per hour provided by two different energy drinks, A and B, respectively.

You want to maximize your total energy boost by drinking one energy drink per hour.
However, if you want to switch from consuming one energy drink to the other,
you need to wait for one hour to cleanse your system (meaning you won't get any energy boost in that hour).

Return the maximum total energy boost you can gain in the next n hours.

Note that you can start consuming either of the two energy drinks.

Example 1:

Input: energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]

Output: 5

Explanation:

To gain an energy boost of 5, drink only the energy drink A (or only B).

Example 2:

Input: energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]

Output: 7

Explanation:

To gain an energy boost of 7:

Drink the energy drink A for the first hour.
Switch to the energy drink B and we lose the energy boost of the second hour.
Gain the energy boost of the drink B in the third hour.

Constraints:

n == energyDrinkA.length == energyDrinkB.length
3 <= n <= 10^5
1 <= energyDrinkA[i], energyDrinkB[i] <= 10^5

Hint 1
Can we solve it using dynamic programming?

Hint 2
Define dpA[i] as the maximum energy boost if we consider only the first i + 1 hours such that in the last hour, we drink the energy drink A.

Hint 3
Similarly define dpB[i].

Hint 4
dpA[i] = max(dpA[i - 1], dpB[i - 2]) + energyDrinkA[i]

Hint 5
Similarly, fill dpB.

Hint 6
The answer is max(dpA[n - 1], dpB[n - 1]).

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxboost(int *a, int *b, size_t n)
{
	size_t i;
	int x0, x1;
	int y0, y1;

	x0 = x1 = 0;
	for (i = 0; i < n; i++) {
		y0 = max(x0 + a[i], x1);
		y1 = max(x1 + b[i], x0);

		x0 = y0;
		x1 = y1;
	}
	return max(x0, x1);
}

int
main()
{
	int a1[] = { 1, 3, 1 };
	int a2[] = { 4, 1, 1 };

	int b1[] = { 3, 1, 1 };
	int b2[] = { 1, 1, 3 };

	assert(maxboost(a1, b1, nelem(a1)) == 5);
	assert(maxboost(a2, b2, nelem(a2)) == 7);

	return 0;
}
