/*

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]


Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.

Hint:
Using a hashmap, we can map the values of arr2 to their position in arr2.
After, we can use a custom sorting function.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, []int{2, 1, 4, 3, 9, 6}, []int{2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19})
	test([]int{28, 6, 22, 8, 44, 17}, []int{22, 28, 8, 6}, []int{22, 28, 8, 6, 17, 44})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []int) {
	p := relsort(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func relsort(a, b []int) []int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	r := []int{}
	for _, v := range b {
		for ; m[v] > 0; m[v]-- {
			r = append(r, v)
		}
	}

	l := len(r)
	for k, v := range m {
		for ; v > 0; v-- {
			r = append(r, k)
		}
	}
	sort.Ints(r[l:])

	return r
}
