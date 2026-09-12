/*

In statistics, sometimes it's useful to know whether two data samples come from the same underlying distribution. One way to do this is to use the two-sample Kolmogorov-Smirnov test.

Your task will be to write a program that reads in two unsorted nonnegative integer arrays and calculates the main statistic used in the test.

Given an array A and a real number x, define the distribution function F by

F(A,x) = (#number of elements in A less than or equal to x)/(#number of elements in A)
Given two arrays A1 and A2, define

D(x) = |F(A1, x) - F(A2, x)|
The two-sample Kolmogorov-Smirnov statistic is the maximum value of D over all real x.

Example
A1 = [1, 2, 1, 4, 3, 6]
A2 = [3, 4, 5, 4]
Then:

D(1) = |2/6 - 0| = 1/3
D(2) = |3/6 - 0| = 1/2
D(3) = |4/6 - 1/4| = 5/12
D(4) = |5/6 - 3/4| = 1/12
D(5) = |5/6 - 4/4| = 1/6
D(6) = |6/6 - 4/4| = 0
The KS-statistic for the two arrays is 1/2, the maximum value of D.

Test cases
[0] [0] -> 0.0
[0] [1] -> 1.0
[1, 2, 3, 4, 5] [2, 3, 4, 5, 6] -> 0.2
[3, 3, 3, 3, 3] [5, 4, 3, 2, 1] -> 0.4
[1, 2, 1, 4, 3, 6] [3, 4, 5, 4] -> 0.5
[8, 9, 9, 5, 5, 0, 3] [4, 9, 0, 5, 5, 0, 4, 6, 9, 10, 4, 0, 9] -> 0.175824
[2, 10, 10, 10, 1, 6, 7, 2, 10, 4, 7] [7, 7, 9, 9, 6, 6, 5, 2, 7, 2, 8] -> 0.363636

Rules
You may write a function or a full program. Input may be via STDIN or function argument, and output may be via STDOUT or return value.
You may assume any unambiguous list or string format for the input, as long as it is consistent for both arrays
On the off-chance that your language has a builtin for this, you may not use it.
Answers need to be correct to at least 3 significant figures
This is code-golf, so the program in the fewest bytes wins

*/

package main

import (
	"fmt"
	"math"
	"slices"
)

func main() {
	test([]int{1, 2, 1, 4, 3, 6}, []int{3, 4, 5, 4}, 0.5)
	test([]int{0}, []int{0}, 0)
	test([]int{0}, []int{1}, 1)
	test([]int{1, 2, 3, 4, 5}, []int{2, 3, 4, 5, 6}, 0.2)
	test([]int{3, 3, 3, 3, 3}, []int{5, 4, 3, 2, 1}, 0.4)
	test([]int{1, 2, 1, 4, 3, 6}, []int{3, 4, 5, 4}, 0.5)
	test([]int{8, 9, 9, 5, 5, 0, 3}, []int{4, 9, 0, 5, 5, 0, 4, 6, 9, 10, 4, 0, 9}, 0.175824)
	test([]int{2, 10, 10, 10, 1, 6, 7, 2, 10, 4, 7}, []int{7, 7, 9, 9, 6, 6, 5, 2, 7, 2, 8}, 0.363636)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b []int, r float64) {
	p := ks(a, b)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-3)
}

func ks(a, b []int) float64 {
	r := 0.0
	m := max(slices.Max(a), slices.Max(b))
	for i := range m + 1 {
		r = max(r, math.Abs(cdf(a, i)-cdf(b, i)))
	}
	return r
}

func cdf(a []int, m int) float64 {
	r := 0.0
	for _, v := range a {
		if v <= m {
			r++
		}
	}
	return r / float64(len(a))
}
