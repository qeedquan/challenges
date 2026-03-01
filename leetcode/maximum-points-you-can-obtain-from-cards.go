/*

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.



Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.



Constraints:

    1 <= cardPoints.length <= 10^5
    1 <= cardPoints[i] <= 10^4
    1 <= k <= cardPoints.length


Hint 1
Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.

Hint 2
Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)

*/

package main

import "math"

func main() {
	assert(maxscore([]int{1, 2, 3, 4, 5, 6, 1}, 3) == 12)
	assert(maxscore([]int{2, 2, 2}, 2) == 4)
	assert(maxscore([]int{9, 7, 7, 9, 7, 7, 9}, 7) == 55)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxscore(p []int, k int) int {
	if len(p) == 0 {
		return 0
	}

	c, l, t, v := 0, 0, 0, math.MaxInt
	for r := range p {
		t += p[r]
		c += p[r]
		if r-l+1 > len(p)-k {
			c -= p[l]
			l += 1
		}
		if r-l+1 == len(p)-k {
			v = min(v, c)
		}
	}
	return t - v
}
