/*

Given an array of integers of length N and an odd integer K, return N - K + 1 integers, where the ith integer represents the median of a K-length subarray starting from i.

You may write a full program or a function.

The input is N, K and the input array. You can take input in any reasonable form, and you don't have to take the length if it's unnecessary.

Sample test (input is in the form N, K, then array)

10 3
3 5 8 2 4 7 5 2 7 4
Output

5 5 4 4 5 5 5 4
How the output is obtained:

The first number is the median of the range [1, 3], or [1, 1 + K - 1]
The second number is the median of the range [2, 4]
...
This is code-golf, so shortest code wins! (In bytes.)

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{3, 5, 8, 2, 4, 7, 5, 2, 7, 4}, 3, []int{5, 5, 4, 4, 5, 5, 5, 4})
	test([]int{1, 2, 3, 4, 5, 6}, 3, []int{2, 3, 4, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := rollingmedians(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func rollingmedians(a []int, k int) []int {
	r := []int{}
	for i := range len(a) - k + 1 {
		x := append([]int{}, a[i:i+k]...)
		sort.Ints(x)
		r = append(r, x[k/2])
	}
	return r
}
