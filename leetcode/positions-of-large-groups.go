/*

In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.

Example 1:

Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.

Example 2:

Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.

Example 3:

Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".


Constraints:

1 <= s.length <= 1000
s contains lowercase English letters only.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("abbxxxxzzy", [][2]int{{3, 6}})
	test("abc", [][2]int{})
	test("abcdddeeeeaabbbcd", [][2]int{{3, 5}, {6, 9}, {12, 14}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r [][2]int) {
	p := groups(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func groups(s string) [][2]int {
	r := [][2]int{}
	for i, j := 0, 0; j < len(s); j++ {
		if j == len(s)-1 || s[j] != s[j+1] {
			if j-i+1 >= 3 {
				r = append(r, [2]int{i, j})
			}
			i = j + 1
		}
	}
	return r
}
