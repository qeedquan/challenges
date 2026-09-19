/*

It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5)
24 cm: (6, 8, 10)
30 cm: (5, 12, 13)
36 cm: (9, 12, 15)
40 cm: (8, 15, 17)
48 cm: (12, 16, 20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L <= 1,500,000 can exactly one integer sided right angle triangle be formed?</p>

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1500000))
}

// https://codereview.stackexchange.com/questions/25388/speed-up-solution-to-project-euler-problem-75
// Based on @Gareth Rees solution
func solve(limit int) int {
	ch := make(chan [4]int)
	go triples(ch)

	m := make(map[int]int)
	for {
		x := <-ch
		if x[3] > limit {
			break
		}

		p := x[0] + x[1] + x[2]
		for i := p; i <= limit; i += p {
			m[i]++
		}
	}
	return count(m, 1)
}

func count(m map[int]int, x int) int {
	r := 0
	for _, v := range m {
		if v == x {
			r++
		}
	}
	return r
}

func triples(ch chan [4]int) {
	for m := 1; m < math.MaxInt; m++ {
		for n := 1; n < m; n++ {
			if (m+n)&1 != 0 && gcd(m, n) == 1 {
				a := m*m - n*n
				b := 2 * m * n
				ch <- [4]int{a, b, m*m + n*n, 2 * m * (m + 1)}
			}
		}
	}
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
