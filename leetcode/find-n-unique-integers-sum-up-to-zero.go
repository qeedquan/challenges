/*

Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]

Constraints:

    1 <= n <= 1000

*/

package main

func main() {
	for i := 1; i <= 1000; i++ {
		test(i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int) {
	p := sumzero(n)
	assert(len(p) == n)
	assert(sum(p) == 0)
	assert(uniq(p))
}

func uniq(a []int) bool {
	m := make(map[int]bool)
	for _, v := range a {
		if m[v] {
			return false
		}
		m[v] = true
	}
	return true
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}

func sumzero(n int) []int {
	if n <= 0 {
		return []int{}
	}
	if n == 1 {
		return []int{0}
	}

	var r []int
	for i := 0; i < n-1; i++ {
		r = append(r, i+1)
	}
	r = append(r, -triangular(n-1))

	return r
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
