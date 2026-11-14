/*

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:

Input: s = "eccbbbbdec"
Output: [10]

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

Hint 1
Try to greedily choose the smallest partition that includes the first letter.
If you have something like "abaccbdeffed", then you might need to add b.
You can use an map like "last['b'] = 5" to help you expand the width of your partition.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("ababcbacadefegdehijhklij", []int{9, 7, 8})
	test("eccbbbbdec", []int{10})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(input string, expected []int) {
	result := labels(input)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func labels(input string) []int {
	lookup := make(map[rune]int)
	for index, symbol := range input {
		lookup[symbol] = index
	}

	result := []int{}
	first := 0
	last := 0
	for index, symbol := range input {
		last = max(last, lookup[symbol])
		if index == last {
			result = append(result, index-first+1)
			first = index + 1
		}
	}
	return result
}
