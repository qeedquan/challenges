/*

John and his wife Ann have decided to go to Codewars. On the first day Ann will do one kata and John - he wants to know how it is working - 0 kata.

Let us call a(n) - and j(n) - the number of katas done by Ann - and John - at day n. We have a(0) = 1 and in the same manner j(0) = 0.

They have chosen the following rules:

On day n the number of katas done by Ann should be n minus the number of katas done by John at day t, t being equal to the number of katas done by Ann herself at day n - 1

On day n the number of katas done by John should be n minus the number of katas done by Ann at day t, t being equal to the number of katas done by John himself at day n - 1

Whoops! I think they need to lay out a little clearer exactly what there're getting themselves into!

Could you write:
functions ann(n) and john(n) that return the list of the number of katas Ann/John does on the first n days;
functions sum_ann(n) and sum_john(n) that return the total number of katas done by Ann/John on the first n days
Examples:
john(11)  -->  [0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6]
ann(6)    -->  [1, 1, 2, 2, 3, 3]

sum_john(75)  -->  1720
sum_ann(150)  -->  6930
Note:
Keep an eye on performance.

*/

package main

import (
	"slices"
)

func main() {
	assert(slices.Equal(john(11), []int{0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6}))
	assert(slices.Equal(ann(6), []int{1, 1, 2, 2, 3, 3}))
	assert(sumjohn(75) == 1720)
	assert(sumann(150) == 6930)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func johnandann(n int) ([]int, []int, int, int) {
	A := []int{1}
	J := []int{0}
	a := 1
	j := 0
	for i := 1; i < n; i++ {
		J = append(J, i-A[J[i-1]])
		A = append(A, i-J[A[i-1]])
		j += J[i]
		a += A[i]
	}
	return A, J, a, j
}

// https://oeis.org/A005378
func ann(n int) []int {
	A, _, _, _ := johnandann(n)
	return A
}

// https://oeis.org/A194179
func john(n int) []int {
	_, J, _, _ := johnandann(n)
	return J
}

// https://oeis.org/A194180
func sumjohn(n int) int {
	_, _, _, j := johnandann(n)
	return j
}

// https://oeis.org/A022778
func sumann(n int) int {
	_, _, a, _ := johnandann(n)
	return a
}
