/*

Inspired by this Mathematica.SE post
https://mathematica.stackexchange.com/questions/261869/generating-a-matrix-with-specific-number-of-1s-in-every-row-and-column

Given two positive integers n,k with n>k≥1, output a binary n×n matrix such that every row and column contains exactly k 1s, and the leading diagonal is all zero. This is the adjacency matrix of a regular graph.

You may output any valid matrix, and it does not have to be deterministic. You may output in any reasonable format, including a flat n^2 list, or a nested list, etc.

This is code-golf, so the shortest code in bytes wins.

Test cases
n, k -> output
2, 1 -> [[0, 1], [1, 0]]
5, 3 -> [[0, 1, 1, 1, 0], [1, 0, 0, 1, 1], [1, 1, 0, 0, 1], [1, 0, 1, 0, 1], [0, 1, 1, 1, 0]]
3, 1 -> [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
5, 1 -> [[0, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1], [0, 0, 1, 0, 0]]
6, 2 -> [[0, 0, 0, 0, 1, 1], [1, 0, 0, 0, 1, 0], [1, 1, 0, 0, 0, 0], [0, 0, 1, 0, 0, 1], [0, 0, 1, 1, 0, 0], [0, 1, 0, 1, 0, 0]]
7, 6 -> [[0, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 0]]

*/

package main

import "fmt"

func main() {
	test(2, 1)
	test(5, 3)
	test(3, 1)
	test(5, 1)
	test(6, 2)
	test(7, 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, k int) {
	m := gen(n, k)
	dump(m, n, k)
	assert(check(m, n, k))
}

func dump(m [][]int, n, k int) {
	fmt.Printf("(%d, %d)\n", n, k)
	for i := range m {
		fmt.Println(m[i])
	}
	fmt.Println()
}

func check(m [][]int, n, k int) bool {
	for i := range n {
		k0 := 0
		k1 := 0
		for j := range n {
			if m[i][j] == 1 {
				k0++
			}
			if m[j][i] == 1 {
				k1++
			}
		}
		if k0 != k || k1 != k || m[i][i] != 0 {
			return false
		}
	}
	return true
}

// ported from @Jonathan Allan solution
func gen(n, k int) [][]int {
	m := alloc(n)
	for i := range m {
		for j := range m[i] {
			c := i*n + j
			if mod(c/n-c-1, n) < k {
				m[i][j] = 1
			}
		}
	}
	return m
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
