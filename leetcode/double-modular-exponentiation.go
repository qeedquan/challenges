/*

You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.

An index i is good if the following formula holds:

0 <= i < variables.length
((ai^bi % 10)^ci) % mi == target
Return an array consisting of good indices in any order.

Example 1:

Input: variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
Output: [0,2]
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [2,3,3,10], (23 % 10)3 % 10 = 2.
2) For the index 1, variables[1] = [3,3,3,1], (33 % 10)3 % 1 = 0.
3) For the index 2, variables[2] = [6,1,1,4], (61 % 10)1 % 4 = 2.
Therefore we return [0,2] as the answer.
Example 2:

Input: variables = [[39,3,1000,1000]], target = 17
Output: []
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [39,3,1000,1000], (393 % 10)1000 % 1000 = 1.
Therefore we return [] as the answer.

Constraints:

1 <= variables.length <= 100
variables[i] == [ai, bi, ci, mi]
1 <= ai, bi, ci, mi <= 10^3
0 <= target <= 10^3

*/

package main

import (
	"fmt"
	"math/big"
	"reflect"
)

func main() {
	test(
		[][4]int64{{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}}, 2,
		[]int{0, 2},
	)

	test(
		[][4]int64{{39, 3, 1000, 1000}}, 17,
		[]int{},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(v [][4]int64, t int64, r []int) {
	i := goodindices(v, t)
	fmt.Println(i)
	assert(reflect.DeepEqual(i, r))
}

func goodindices(v [][4]int64, t int64) []int {
	ten := big.NewInt(10)

	r := []int{}
	z := new(big.Int)
	for i, x := range v {
		a := big.NewInt(x[0])
		b := big.NewInt(x[1])
		c := big.NewInt(x[2])
		m := big.NewInt(x[3])

		z.Exp(a, b, ten)
		z.Exp(z, c, m)
		if z.Int64() == t {
			r = append(r, i)
		}
	}
	return r
}
