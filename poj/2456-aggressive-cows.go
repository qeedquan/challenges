/*

Description

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input

* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output

* Line 1: One integer: the largest minimum distance

Sample Input

5 3
1
2
8
4
9

Sample Output

3
Hint

OUTPUT DETAILS:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

Huge input data,scanf is recommended.

Source

USACO 2005 February Gold

*/

package main

import "sort"

func main() {
	assert(distance([]int{1, 2, 8, 4, 9}, 3) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distance(x []int, C int) int {
	n := len(x)
	if n == 0 {
		return 0
	}

	sort.Ints(x)

	l := 1
	r := x[n-1] - x[0]
	m := l + (r-l)/2
	for l+1 < r {
		if check(x, C, m) {
			l = m
		} else {
			r = m - 1
		}
		m = l + (r-l)/2
	}

	d := 0
	if check(x, C, l) {
		d = l
	}
	if check(x, C, r) {
		d = r
	}
	return d
}

func check(x []int, C, d int) bool {
	t := C - 1
	p := x[0]
	for i := 1; i < len(x); i++ {
		if x[i]-p >= d {
			p = x[i]
			if t--; t < 1 {
				return true
			}
		}
	}
	return false
}
