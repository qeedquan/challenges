/*

All of you know that GCD means the greatest common divisor. So, you must have thought that this problem requires finding some sort of GCD. Don't worry, you are absolutely right!

Given N positive integers, not necessarily distinct, how many ways you can take 4 integers from the N numbers such that their GCD is 1.

Input
Input starts with an integer T (≤ 20), denoting the number of test cases.

Each case starts with an integer N (4 ≤ N ≤ 10000). The next line contains N integers separated by spaces. The integers will be positive and not greater than 10000.

Output
For each case, print the case number and the number of ways you can take the integers as mentioned above.

Sample
Input	Output
3
4
2 4 6 1
5
1 2 4 6 8
10
12 46 100 131 5 6 7 8 9 10

Case 1: 1
Case 2: 4
Case 3: 195

*/

package main

func main() {
	assert(solve([]int{2, 4, 6, 1}) == 1)
	assert(solve([]int{1, 2, 4, 6, 8}) == 4)
	assert(solve([]int{12, 46, 100, 131, 5, 6, 7, 8, 9, 10}) == 195)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	d := make(map[int]int)
	m := 0
	for _, x := range a {
		m = max(m, x)
		for j := 1; j*j <= x; j++ {
			if x%j != 0 {
				continue
			}
			d[j]++
			if j*j != x {
				d[x/j]++
			}
		}
	}

	r := make(map[int]int)
	for i := m; i >= 1; i-- {
		r[i] = nc4(d[i])
		for j := i + i; j <= m; j += i {
			r[i] -= r[j]
		}
	}
	return r[1]
}

func nc4(n int) int {
	return (n * (n - 1) * (n - 2) * (n - 3)) / 24
}
