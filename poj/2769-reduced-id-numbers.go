/*

Description

T. Chur teaches various groups of students at university U. Every U-student has a unique Student Identification Number (SIN). A SIN s is an integer in the range 0 ≤ s ≤ MaxSIN with MaxSIN = 10^6-1. T. Chur finds this range of SINs too large for identification within her groups. For each group, she wants to find the smallest positive integer m, such that within the group all SINs reduced modulo m are unique.

Input

On the first line of the input is a single positive integer N, telling the number of test cases (groups) to follow. Each case starts with one line containing the integer G (1 ≤ G ≤ 300): the number of students in the group. The following G lines each contain one SIN. The SINs within a group are distinct, though not necessarily sorted.

Output

For each test case, output one line containing the smallest modulus m, such that all SINs reduced modulo m are distinct.

Sample Input

2
1
124866
3
124866
111111
987651

Sample Output

1
8

Source

Northwestern Europe 2005

*/

package main

import "math"

func main() {
	assert(modulus([]int{124866}) == 1)
	assert(modulus([]int{124866, 111111, 987651}) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func modulus(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	m := make(map[int]bool)
	for r := n; r < math.MaxInt; r++ {
		clear(m)
		for _, v := range a {
			i := v % r
			if m[i] {
				break
			}
			m[i] = true
		}
		if len(m) == n {
			return r
		}
	}
	return -1
}
