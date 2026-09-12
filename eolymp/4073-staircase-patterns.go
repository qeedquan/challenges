/*

One day, you come across an interesting staircase. On each step, there is a number written.
Curious about the sequence, you decide to observe all the numbers as you climb.
Soon, you notice a pattern: for each number on the step, you record the sum of all previously encountered numbers that are smaller than the current one.

Input
The first line contains an integer t (t≤10) — the number of test cases. The next 2t lines follow.
The first of these lines contains an integer n (1≤n≤10^5) — the number of steps.
The next line contains n integers — the numbers written on the steps. All numbers are in the range from 0 to 10^6.

Output
For each test case, print the final sum in a separate line.

Examples
Input #1
1
5
1 5 3 6 4

Answer #1
15

*/

package main

func main() {
	assert(solve([]int{1, 5, 3, 6, 4}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	r := 0
	for i := range len(a) {
		s := 0
		for j := range i {
			if a[j] < a[i] {
				s += a[j]
			}
		}
		r += s
	}
	return r
}
