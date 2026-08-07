/*

An Almost Equilateral Heronian Triangle is a triangle with integer lengths of the form n-1, n, and n+1 and also has integer area. The first few are:

 3,  4,  5 ->    6
13, 14, 15 ->   84
51, 52, 53 -> 1170
Quest: Generate the shortest program that outputs the nth such triple. (Hint: this is a known sequence).

*/

package main

func main() {
	tab := []int{3, 4, 5, 13, 14, 15, 51, 52, 53, 193, 194, 195, 723, 724, 725, 2701, 2702, 2703, 10083, 10084, 10085, 37633, 37634, 37635, 140451, 140452, 140453, 524173, 524174, 524175, 1956243, 1956244, 1956245, 7300801, 7300802, 7300803, 27246963, 27246964, 27246965}

	for i := range tab {
		assert(heronian(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A242497
func heronian(n int) int {
	a := []int{-1, -1, -1, 4, 4, 4, -1, -1}
	x := []int{3, 4, 5, 13, 14, 15, 51, 52}
	for i := 0; i < n; i++ {
		v := dot(a, x)
		copy(x, x[1:])
		x[len(x)-1] = v
	}
	return x[0]
}

func dot(a, b []int) int {
	r := 0
	for i := range a {
		r += a[i] * b[i]
	}
	return r
}
