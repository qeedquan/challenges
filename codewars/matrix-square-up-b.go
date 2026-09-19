/*

Welcome. Welcome all to my very second Kata. As you know, the first one was a huge success. This time, however, things are going to be a little bit different. Is it going to be as cool as the last one? Let's find out! Tell your friends!

Given an integer b greater than 0, create and return a b X b matrix with the following pattern:

                     [x,1]
matrixSquareUp(2) => [2,1]

                     [x,x,1]
                     [x,2,1]
matrixSquareUp(3) => [3,2,1]

                     [x,x,x,1]
                     [x,x,2,1]
                     [x,3,2,1]
matrixSquareUp(4) => [4,3,2,1]

Those are lowercase 'x'.

50 > b > 0

*/

package main

import "reflect"

func main() {
	test(2, [][]int{
		{'x', 1},
		{2, 1},
	})

	test(3, [][]int{
		{'x', 'x', 1},
		{'x', 2, 1},
		{3, 2, 1},
	})

	test(4, [][]int{
		{'x', 'x', 'x', 1},
		{'x', 'x', 2, 1},
		{'x', 3, 2, 1},
		{4, 3, 2, 1},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][]int) {
	m := matrix(n)
	assert(reflect.DeepEqual(m, r))
}

func matrix(n int) [][]int {
	m := make([][]int, n)
	for i := range n {
		m[i] = make([]int, n)
		for j := range n {
			m[i][j] = 'x'
			if n-j <= i+1 {
				m[i][j] = n - j
			}
		}
	}
	return m
}
