/*

Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

Example 1:

Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.

Example 2:

Input: arr = [3,2,1], k = 10
Output: 3
Explanation: 3 will win the first 10 rounds consecutively.


Constraints:

2 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
arr contains distinct integers.
1 <= k <= 10^9

Hint 1
If k ≥ arr.length return the max element of the array.

Hint 2
If k < arr.length simulate the game until a number wins k consecutive games.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

vlong
winner(vlong *a, size_t n, vlong k)
{
	size_t l, r;
	vlong v, w;
	vlong t;
	vlong m;

	if (n < 2)
		return 0;

	v = -1;
	t = 0;
	l = 0;
	r = 1;
	m = max(a[l], a[r]);

	while (r < n) {
		if (a[l] < a[r])
			l = r;
		r += 1;

		w = a[l];
		if (w == v)
			t += 1;
		else {
			v = w;
			t = 1;
		}

		if (t >= k)
			return v;

		if (r < n)
			m = max(m, a[r]);
	}

	return m;
}

int
main()
{
	vlong a1[] = { 2, 1, 3, 5, 4, 6, 7 };
	vlong a2[] = { 3, 2, 1 };
	vlong a3[] = { 1, 9, 8, 2, 3, 7, 6, 4, 5 };
	vlong a4[] = { 1, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

	assert(winner(a1, nelem(a1), 2) == 5);
	assert(winner(a2, nelem(a2), 10) == 3);
	assert(winner(a3, nelem(a3), 7) == 9);
	assert(winner(a4, nelem(a4), 1000000000) == 99);

	return 0;
}
