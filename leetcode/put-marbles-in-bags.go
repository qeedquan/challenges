/*

You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:

No bag is empty.
If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.

Example 1:

Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation:
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6.
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10.
Thus, we return their difference 10 - 6 = 4.

Example 2:

Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3].
Since both the maximal and minimal score are the same, we return 0.

Constraints:

1 <= k <= weights.length <= 10^5
1 <= weights[i] <= 10^9

Hint 1
Each bag will contain a subarray, and only the endpoints of these subarrays matter.

Hint 2
Each subarray only contributes two numbers to the sum. Use this property to choose the subarrays optimally.

Hint 3
Try to use a priority queue.

*/

package main

import "sort"

func main() {
	assert(put([]int{1, 3, 5, 1}, 2) == 4)
	assert(put([]int{1, 3}, 2) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func put(w []int, k int) int {
	n := len(w)
	p := make([]int, n-1)
	for i, x := range w[:n-1] {
		p[i] = x + w[i+1]
	}
	sort.Ints(p)

	r := 0
	for i := 0; i < k-1; i++ {
		r += p[n-2-i] - p[i]
	}
	return r
}
