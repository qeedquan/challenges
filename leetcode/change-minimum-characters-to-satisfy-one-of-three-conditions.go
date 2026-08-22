/*

You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.
Return the minimum number of operations needed to achieve your goal.

Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).

Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".

Constraints:

1 <= a.length, b.length <= 10^5
a and b consist only of lowercase letters.

Hint 1
Iterate on each letter in the alphabet, and check the smallest number of operations needed to make it one of the following:
the largest letter in a and smaller than the smallest one in b, vice versa, or let a and b consist only of this letter.

Hint 2
For the first 2 conditions, take care that you can only change characters to lowercase letters,
so you can't make 'z' the smallest letter in one of the strings or 'a' the largest letter in one of them.

*/

package main

func main() {
	assert(chars("aba", "caa") == 2)
	assert(chars("dabadd", "cda") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chars(a, b string) int {
	c1 := make(map[byte]int)
	c2 := make(map[byte]int)

	for i := 0; i < len(a); i++ {
		c1[a[i]-'a'] += 1
	}
	for i := 0; i < len(b); i++ {
		c2[b[i]-'a'] += 1
	}

	r := len(a) + len(b)
	for i := range byte(26) {
		r = min(r, len(a)+len(b)-c1[i]-c2[i])
		if i > 0 {
			c1[i] += c1[i-1]
			c2[i] += c2[i-1]
		}
		if i < 25 {
			r = min(r, len(a)-c1[i]+c2[i])
			r = min(r, len(b)-c2[i]+c1[i])
		}
	}
	return r
}
