/*

Your task is to sort a given string. Each word in the string will contain a single number. This number is the position the word should have in the result.

Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

If the input string is empty, return an empty string. The words in the input String will only contain valid consecutive numbers.

Examples
"is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
"4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
""  -->  ""

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(order("is2 Thi1s T4est 3a") == "Thi1s is2 3a T4est")
	assert(order("4of Fo1r pe6ople g3ood th5e the2") == "Fo1r the2 g3ood 4of th5e pe6ople")
	assert(order("") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func order(s string) string {
	const digits = "123456789"

	t := strings.Split(s, " ")
	sort.Slice(t, func(i, j int) bool {
		n := strings.IndexAny(t[i], digits)
		m := strings.IndexAny(t[j], digits)
		if n < 0 {
			return false
		}
		if m < 0 {
			return true
		}
		return t[i][n] < t[j][m]
	})
	return strings.Join(t, " ")
}
