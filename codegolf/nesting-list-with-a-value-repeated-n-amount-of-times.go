/*

Given the input of n and value. The code is supposed to nest the single element list with value repeated n times. The final output should be a multilevel nested list with single repeated values in all sublists.

This is code-golf, so the shortest code in bytes wins!

Test cases:
n = 1, value = 'a': ['a']
n = 2, value = 'a': ['a', ['a']]
n = 3, value = 'a': ['a', ['a', ['a']]]
n = 4, value = 'a': ['a', ['a', ['a', ['a']]]]
n = 5, value = 'a': ['a', ['a', ['a', ['a', ['a']]]]]
n = 6, value = 'a': ['a', ['a', ['a', ['a', ['a', ['a']]]]]]

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 6; i++ {
		fmt.Println(gen(i, 'a'))
	}
}

func gen(n int, c rune) any {
	if n < 1 {
		return []any{}
	}

	r := []any{c}
	for range n - 1 {
		r = []any{c, r}
	}
	return r
}
