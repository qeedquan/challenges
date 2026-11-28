/*

https://static.e-olymp.com/content/96/96ed6508f858eaedff187caa2ce52166d75238c9.jpg

How many points with integer coordinates lie inside or on a circle of radius r? The center of the circle has integer coordinates.

Input
An integer r (r≤15000) — the radius of the circle.

Output
Print the required number of points.

Examples
Input #1
2

Answer #1
13

*/

package main

func main() {
	tab := []int{
		1, 5, 13, 29, 49, 81, 113, 149, 197, 253, 317, 377, 441, 529, 613, 709,
		797, 901, 1009, 1129, 1257, 1373, 1517, 1653, 1793, 1961, 2121, 2289,
		2453, 2629, 2821, 3001, 3209, 3409, 3625, 3853, 4053, 4293, 4513, 4777,
		5025, 5261, 5525, 5789, 6077, 6361, 6625,
	}

	assert(solve(2) == 13)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000328
func solve(r int) int {
	k := 0
	for x := 1; x <= r; x++ {
		for y := 1; y <= r; y++ {
			if x*x+y*y <= r*r {
				k++
			}
		}
	}
	return 4*k + 4*r + 1
}
