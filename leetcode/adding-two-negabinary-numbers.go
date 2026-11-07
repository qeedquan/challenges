/*

Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

Example 1:

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
Example 2:

Input: arr1 = [0], arr2 = [0]
Output: [0]
Example 3:

Input: arr1 = [0], arr2 = [1]
Output: [1]


Constraints:

1 <= arr1.length, arr2.length <= 1000
arr1[i] and arr2[i] are 0 or 1
arr1 and arr2 have no leading zeros

Hint:
We can try to determine the last digit of the answer, then divide everything by 2 and repeat.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 1, 1, 1, 1}, []int{1, 0, 1}, []int{1, 0, 0, 0, 0})
	test([]int{0}, []int{0}, []int{0})
	test([]int{0}, []int{1}, []int{1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, r []int) {
	z := nbadd(x, y)
	fmt.Println(z)
	assert(reflect.DeepEqual(z, r))
}

/*

https://mathworld.wolfram.com/Negabinary.html
https://en.wikipedia.org/wiki/Negative_base
https://walkccc.me/LeetCode/problems/1073/

*/

func nbadd(x, y []int) []int {
	z := []int{}
	c := 0
	i := len(x) - 1
	j := len(y) - 1
	for c != 0 || i >= 0 || j >= 0 {
		if i >= 0 {
			c, i = c+x[i], i-1
		}
		if j >= 0 {
			c, j = c+y[j], j-1
		}
		z = append(z, c&1)
		c = -(c >> 1)
	}

	for {
		n := len(z)
		if !(n > 1 && z[n-1] == 0) {
			break
		}
		z = z[:n-1]
	}

	n := len(z)
	for i := 0; i < n/2; i++ {
		z[i], z[n-i-1] = z[n-i-1], z[i]
	}

	return z
}
