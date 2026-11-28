/*

Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:

1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100

Hint 1
If the temperature is say, 70 today, then in the future a warmer temperature must be either 71, 72, 73, ..., 99, or 100. We could remember when all of them occur next.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{73, 74, 75, 71, 69, 72, 76, 73},
		[]int{1, 1, 4, 2, 1, 1, 0, 0},
	)

	test(
		[]int{30, 40, 50, 60},
		[]int{1, 1, 1, 0},
	)

	test(
		[]int{30, 60, 90},
		[]int{1, 1, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(t, r []int) {
	p := temperatures(t)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func temperatures(t []int) []int {
	n := len(t)
	r := make([]int, n)
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j += r[j] {
			if t[j] > t[i] {
				r[i] = j - i
				break
			} else if r[j] == 0 {
				r[i] = 0
				break
			}
		}
	}
	return r
}
