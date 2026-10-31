/*

The usual correlation coefficient (in 2d) measures how well a set of points can be described by a line, and if yes, its sign tells us whether we have a positive or negative correlation.
But this assumes that coordinates of the points can actually interpreted quantitatively for instance as measurements.

If you cannot do that but you can still order the coordinates, there is the rank correlation coefficient: It measures how well the points can be described by a monotonic function.

Challenge
Given a list of 2d points, determine their rank correlation coefficient.

Details
You can assume the input to be positive integers (but you don't have to), or any other "sortable" values.
The points can be taken as a list of points, or two lists for the x- and y-coordinates or a matrix or 2d array etc.
The output must be a floating point or rational type, as it should represent a real number between 0 and 1.

Definitions
Rank: Given a list of numbers X=[x(1),...,x(n)] we can assign a positive number rx(i) called rank to each entry x(i).
      We do so by sorting the list and assigning the index of x(i) in the sorted list rx(i). If two or more x(i) have the same value, then we just use the arithmetic mean of all the corresponding indices as rank. Example:

          List: [21, 10, 10, 25, 3]
Indices sorted: [4, 2, 3, 5, 1]
The number 10 appears twice here. In the sorted list it would occupy the indices 2 and 3. The arithmetic mean of those is 2.5 so the ranks are

         Ranks: [4, 2.5, 2.5, 5, 1]
Rank Correlation Coefficient: Let [(x(1),y(1)),(x(2),y(2)),...,(x(n),y(n))] be the given points where each x(i) and y(i) is a real number (wlog. you can assume it is an integer)
For each i=1,...,n we compute the rank rx(i) and ry(i) of x(i) and y(i) respectively.

Let d(i) = rx(i)-ry(i) be the rank difference and let S be the sum S = d(1)^2 + d(2)^2 + ... + d(n)^2. Then the rank correlation coefficient rho is given by

rho = 1 - 6 * S / (n * (n^2-1))

Example
x   y   rx              ry   d      d^2
21  15  4               5   -1      1
10  6   2&3 -> 2.5      2    0.5    0.25
10  7   2&3 -> 2.5      3   -0.5    0.25
25  11  5               4    1      1
3   5   1               1    0      0

rho = 1 - 6 * (1+0.25+0.25+1)/(5*(5^2-1)) = 0.875

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	test([]int{21, 10, 10, 25, 3}, []int{15, 6, 7, 11, 5}, 0.875)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y []int, r float64) {
	p := rankcoeff(x, y)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-3)
}

func rankcoeff(x, y []int) float64 {
	if len(x) != len(y) {
		panic("mismatch array length")
	}

	rx := rankify(x)
	ry := rankify(y)

	n := float64(len(x))
	s := 0.0
	for i := range rx {
		d := rx[i] - ry[i]
		s += d * d
	}
	return 1 - 6*s/(n*(n*n-1))
}

// https://www.geeksforgeeks.org/rank-elements-array/
func rankify(a []int) []float64 {
	n := len(a)
	x := make([][2]int, n)
	for i := range a {
		x[i][0] = a[i]
		x[i][1] = i
	}

	sort.Slice(x, func(i, j int) bool {
		return x[i][0] < x[j][0]
	})

	r := make([]float64, n)
	m := 0
	z := 1.0
	for i := 0; i < n; i += m {
		j := i
		for j < n-1 && x[j][0] == x[j+1][0] {
			j++
		}

		m = j - i + 1
		for k := 0; k < m; k++ {
			l := x[i+k][1]
			r[l] = z + float64(m-1)*0.5
		}
		z += float64(m)
	}
	return r
}
