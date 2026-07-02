/*

Given an initial array arr, every day you produce a new array using the array of the previous day.

On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:

If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
The first and last elements never change.
After some days, the array does not change. Return that final array.

Example 1:

Input: arr = [6,2,3,4]
Output: [6,3,3,4]
Explanation:
On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
No more operations can be done to this array.
Example 2:

Input: arr = [1,6,3,4,3,5]
Output: [1,4,4,4,4,5]
Explanation:
On the first day, the array is changed from [1,6,3,4,3,5] to [1,5,4,3,4,5].
On the second day, the array is changed from [1,5,4,3,4,5] to [1,4,4,4,4,5].
No more operations can be done to this array.


Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 100

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{6, 2, 3, 4}, []int{6, 3, 3, 4})
	test([]int{1, 6, 3, 4, 3, 5}, []int{1, 4, 4, 4, 4, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := transform(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func transform(a []int) []int {
	p := append([]int{}, a...)
	q := append([]int{}, a...)
	for {
		f := false
		for i := 1; i < len(a)-1; i++ {
			switch {
			case p[i] > p[i-1] && p[i] > p[i+1]:
				q[i], f = p[i]-1, true
			case p[i] < p[i-1] && p[i] < p[i+1]:
				q[i], f = p[i]+1, true
			default:
				q[i] = p[i]
			}
		}
		p, q = q, p

		if !f {
			return p
		}
	}
}
