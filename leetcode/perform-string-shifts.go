/*

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift).
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation:
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"

Explanation:
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

*/

package main

func main() {
	assert(stringshift("abc", [][2]int{{0, 1}, {1, 2}}) == "cab")
	assert(stringshift("abcdefg", [][2]int{{1, 1}, {1, 1}, {0, 2}, {1, 3}}) == "efgabcd")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func stringshift(str string, shift [][2]int) string {
	count := 0
	for _, value := range shift {
		if value[0] == 0 {
			count += value[1]
		} else {
			count -= value[1]
		}
	}

	count %= len(str)
	if count > 0 {
		str = leftshift(str, count)
	} else if count < 0 {
		str = rightshift(str, -count)
	}
	return str
}

func leftshift(str string, num int) string {
	return str[num:] + str[:num]
}

func rightshift(str string, num int) string {
	return str[len(str)-num:] + str[:len(str)-num]
}
