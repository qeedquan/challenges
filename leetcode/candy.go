/*

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.


Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:

n == ratings.length
1 <= n <= 2 * 10^4
0 <= ratings[i] <= 2 * 10^4

*/

package main

func main() {
	assert(candy([]int{1, 0, 2}) == 5)
	assert(candy([]int{1, 2, 2}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

http://buttercola.blogspot.com/2014/09/leetcode-candy.html
https://www.geeksforgeeks.org/minimum-number-of-candies-required-to-distribute-among-children-based-on-given-conditions/

This is a assigning candy problem. There are basically two requirements. First of all, each child must have at least one candy. Secondly, children with a higher rating get more candies than their lower rating neighbor. We can take several examples to show this problem.
For 1   2   3   3   3
      1   2   3    1   1 , so sum = 8

For 1   2   3    2   3
      1   2   3    1    2   so sum = 9

Note that we cannot sort the array, since we must maintain the neighbor relationships between each child. So we can naturally think of using DP to solve this problem.

A DP Solution:

Define a DP array, dp[N], where as dp[i] means number of candies for child i.
Transit function:  rank[i] > rank[i - 1], dp[i] = dp[i - 1] + 1.  If rank[i] == rank[i - 1], dp[i] = 1. If rank[i] < rank[i -1], it is hard to make a decision since if dp[i - 1] = 1, we cannot let child[i] have 0 candy. So we must go back to plus 1 for all its previous visited children until meet the requirements again.

*/

func candy(a []int) int {
	n := len(a)
	c := make([]int, n)
	for i := range c {
		c[i] = 1
	}

	for i := 1; i < n; i++ {
		if a[i] > a[i-1] {
			c[i] = c[i-1] + 1
		}
	}

	for i := n - 2; i >= 0; i-- {
		if a[i] > a[i+1] {
			c[i] = max(c[i], c[i+1]+1)
		}
	}

	r := 0
	for i := range c {
		r += c[i]
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
