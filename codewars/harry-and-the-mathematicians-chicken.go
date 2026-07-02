/*

Harry's local chicken shop - The Golden Chick - sells chicken pieces in boxes of 3, 6 and 10.

Write a function that takes the total number of chicken pieces Harry can eat (n) and returns an array of the possible numbers of chicken pieces he can buy, that are less than or equal to n.

0 chicken pieces is a valid chicken option.

For example:

chickenOptions(9)
should return [0,3,6,9], as Harry can buy no boxes, a box of 3, a box of 6, or a box of 3 and a box of 6 (9 in total).

For non-numeric input, the function should return [0].

Don't forget to rate this kata!

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(9, []int{0, 3, 6, 9})
	test(13, []int{0, 3, 6, 9, 10, 12, 13})
	test(2, []int{0})
	test(21, []int{0, 3, 6, 9, 10, 12, 13, 15, 16, 18, 19, 20, 21})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := chickenoptions(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func chickenoptions(n int) []int {
	if n < 0 {
		return []int{}
	}

	r := []int{0, 3, 6, 9, 10, 12, 13, 15, 16}
	i := sort.SearchInts(r, n+1)
	r = r[:i]
	for x := 18; x <= n; x++ {
		r = append(r, x)
	}
	return r
}
