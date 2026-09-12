/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"})
	test(1, []string{"()"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []string) {
	p := parens(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func parens(n int) []string {
	var p []string
	recurse("", n, n, &p)
	return p
}

func recurse(s string, l, r int, p *[]string) {
	if l == 0 && r == 0 {
		*p = append(*p, s)
		return
	}
	if l > 0 {
		recurse(s+"(", l-1, r, p)
	}
	if l < r {
		recurse(s+")", l, r-1, p)
	}
}
