/*

For an integer k rearrange all the elements of the given array in such way, that:

all elements that are less than k are placed before elements that are not less than k;
all elements that are less than k remain in the same order with respect to each other;
all elements that are not less than k remain in the same order with respect to each other.

For k = 6 and elements = [6, 4, 10, 10, 6], the output should be splitByValue(k, elements) = [4, 6, 10, 10, 6].

For k = 5 and elements = [1, 3, 5, 7, 6, 4, 2], the output should be splitByValue(k, elements) = [1, 3, 4, 2, 5, 7, 6].

S: codefights.com

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(6, []int{6, 4, 10, 10, 6}, []int{4, 6, 10, 10, 6})
	test(0, []int{5, 2, 7, 3, 2}, []int{5, 2, 7, 3, 2})
	test(5, []int{1, 3, 5, 7, 6, 4, 2}, []int{1, 3, 4, 2, 5, 7, 6})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(k int, a, r []int) {
	split(k, a)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func split(k int, a []int) []int {
	sort.SliceStable(a, func(i, j int) bool {
		if (a[i] >= k && a[j] >= k) || (a[i] < k && a[j] < k) {
			return false
		}
		return a[i] < a[j]
	})
	return a
}
