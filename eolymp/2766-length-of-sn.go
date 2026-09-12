/*

A number sequence is defined as follows:

S(1)=1, S(2)=11, S(3)=21, S(4)=1211, S(5)=111221, S(6)=312211, …

You are required to determine the length of S(n).

Input
The input consists of multiple test cases. Each test case contains a single integer n (1≤n≤30) on a separate line.
The last line contains n=0 and should not be processed.

Output
For each test case, output the length of S(n) on a separate line.

Examples

Input #1
2
5
0

Answer #1
2
6

*/

package main

import "fmt"

func main() {
	tab := []int{
		1, 2, 2, 4, 6, 6, 8, 10, 14, 20, 26, 34, 46, 62, 78, 102, 134, 176, 226,
		302, 408, 528, 678, 904, 1182, 1540, 2012, 2606, 3410, 4462, 5808, 7586,
		9898, 12884, 16774, 21890, 28528, 37158, 48410, 63138, 82350,
	}

	assert(solve(2) == 2)
	assert(solve(5) == 6)

	for i := range len(tab) {
		assert(solve(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A005341
func solve(n int) int {
	return len(looksay(n))
}

// https://oeis.org/A005150
func looksay(n int) string {
	if n <= 0 {
		return ""
	}

	s := "1"
	for i := 1; i < n; i++ {
		s += "$"
		t := ""
		c := 1
		for j := 1; j < len(s); j++ {
			if s[j] != s[j-1] {
				t += fmt.Sprintf("%d%c", c, s[j-1])
				c = 1
			} else {
				c++
			}
		}
		s = t
	}
	return s
}
