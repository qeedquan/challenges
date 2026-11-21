/*

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 10^5
All the integers in rating are unique.

Hint 1
BruteForce, check all possibilities.

*/

package main

func main() {
	assert(numteams([]int{2, 5, 3, 4, 1}) == 3)
	assert(numteams([]int{2, 1, 3}) == 0)
	assert(numteams([]int{1, 2, 3, 4}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func numteams(rating []int) int {
	result := 0
	for i := 1; i < len(rating)-1; i++ {
		less := [2]int{}
		greater := [2]int{}
		for j := range rating {
			slot := truth(i < j)
			if rating[i] > rating[j] {
				less[slot] += 1
			} else if rating[i] < rating[j] {
				greater[slot] += 1
			}
		}
		result += less[0]*greater[1] + greater[0]*less[1]
	}
	return result
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
