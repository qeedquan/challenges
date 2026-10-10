/*

You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.

Example 1:

Input: s = "aabaac", cost = [1,2,3,4,1,10]

Output: 11

Explanation:

Deleting the characters at indices 0, 1, 2, 3, 4 results in the string "c", which consists of equal characters, and the total cost is cost[0] + cost[1] + cost[2] + cost[3] + cost[4] = 1 + 2 + 3 + 4 + 1 = 11.

Example 2:

Input: s = "abc", cost = [10,5,8]

Output: 13

Explanation:

Deleting the characters at indices 1 and 2 results in the string "a", which consists of equal characters, and the total cost is cost[1] + cost[2] = 5 + 8 = 13.

Example 3:

Input: s = "zzzzz", cost = [67,67,67,67,67]

Output: 0

Explanation:

All characters in s are equal, so the deletion cost is 0.

Constraints:

n == s.length == cost.length
1 <= n <= 10^5
1 <= cost[i] <= 10^9
s consists of lowercase English letters.

Hint 1
Keep the character whose total deletion cost is maximum

*/

package main

func main() {
	assert(cost("aabaac", []int{1, 2, 3, 4, 1, 10}) == 11)
	assert(cost("abc", []int{10, 5, 8}) == 13)
	assert(cost("zzzzz", []int{67, 67, 67, 67, 67}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(input string, cost []int) int {
	total := 0
	for _, value := range cost {
		total += value
	}

	maximum := 0
	count := make(map[rune]int)
	for index, symbol := range input {
		count[symbol] += cost[index]
		maximum = max(maximum, count[symbol])
	}
	return total - maximum
}
