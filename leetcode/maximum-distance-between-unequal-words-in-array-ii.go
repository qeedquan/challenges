/*

You are given a string array words.

Find the maximum distance between two distinct indices i and j such that:

1. words[i] != words[j], and
2. the distance is defined as j - i + 1

Return the maximum distance among all such pairs. If no valid pair exists, return 0.

Example 1:
Input: words = ["leetcode", "leetcode", "codeforces"]
Output: 3
Explanation: In this example, words[0] and words[2] are not equal, and they have a maximum distance of 2 - 0 + 1 = 3.

Example 2:
Input: words = ["a", "b", "c", "a", "a"]
Output: 4
Explanation: In this example, words[1] and words[4] have the largest distance of 4 - 1 + 1 = 4.

*/

package main

func main() {
	assert(maxdistance([]string{"leetcode", "leetcode", "codeforces"}) == 3)
	assert(maxdistance([]string{"a", "b", "c", "a", "a"}) == 4)
	assert(maxdistance([]string{"a", "b", "c"}) == 3)
	assert(maxdistance([]string{"z", "z", "z"}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxdistance(s []string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	for i := 0; i <= n/2; i++ {
		if s[n-i-1] != s[0] || s[i] != s[n-1] {
			return n - i
		}
	}
	return 0
}
