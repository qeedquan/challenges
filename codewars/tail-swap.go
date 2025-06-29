/*

You'll be given a list of two strings, and each will contain exactly one colon (":") in the middle (but not at beginning or end). The length of the strings, before and after the colon, are random.

Your job is to return a list of two strings (in the same order as the original list), but with the characters after each colon swapped.

Examples
["abc:123", "cde:456"]  -->  ["abc:456", "cde:123"]
["a:12345", "777:xyz"]  -->  ["a:xyz", "777:12345"]

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(tailswap([2]string{"abc:123", "cde:456"}))
	fmt.Println(tailswap([2]string{"a:12345", "777:xyz"}))
}

func tailswap(s [2]string) [2]string {
	i := strings.Index(s[0], ":")
	j := strings.Index(s[1], ":")
	if i < 0 || j < 0 {
		return s
	}
	return [2]string{
		fmt.Sprint(s[0][:i], s[1][j:]),
		fmt.Sprint(s[1][:j], s[0][i:]),
	}
}
