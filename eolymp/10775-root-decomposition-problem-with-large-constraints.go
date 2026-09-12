/*

Positive integer n is given. Find how many different numbers there are among the numbers n mod 1, n mod 2, …, n mod n.

Input
One integer n (1≤n≤10^12).

Output
Print one number — the number of different integers among nmod1, nmod2, …, nmodn.

Examples

Input #1
1

Answer #1
1

Input #2
2

Answer #2
1

Input #3
3

Answer #3
2

Note
In the first example we consider only one number: 1 mod 1 = 0, so the answer is 1.

In the second example we have 2 mod 1 = 2 mod 2 = 0, so the answer is 1.

In the third example we have 3 mod 1 = 3 mod 3 = 0, and also 3 mod 2 = 1, just two different numbers.

*/

package main

func main() {
	assert(solve(1) == 1)
	assert(solve(2) == 1)
	assert(solve(3) == 2)

	for i := range 10000 {
		assert(solve(i) == solvebf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return 0
	}
	return (n + 1) / 2
}

func solvebf(n int) int {
	m := make(map[int]bool)
	r := 0
	for i := 1; i <= n; i++ {
		if j := n % i; !m[j] {
			r, m[j] = r+1, true
		}
	}
	return r
}
