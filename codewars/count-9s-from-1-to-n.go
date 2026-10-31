/*

It's 9 time!

I want to count from 1 to n. How many times will I use a '9'?

9, 19, 91.. will contribute one '9' each, 99, 199, 919.. wil contribute two '9's each...etc

Note: n will always be a positive integer.

Examples (input -> output)
8  -> 0
9  -> 1
10 -> 1
98 -> 18
100 -> 20

*/

package main

func main() {
	tab := []int{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 20,
	}

	assert(nines(8) == 0)
	assert(nines(9) == 1)
	assert(nines(10) == 1)
	assert(nines(98) == 18)
	assert(nines(100) == 20)

	for i := range tab {
		assert(nines(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A102684
func nines(n int) int {
	c, p := 0, 1
	for p <= n {
		c += n/(p*10)*p + bool2(n/p%10 == 9)*(n%p+1)
		p *= 10
	}
	return c
}

func bool2(x bool) int {
	if x {
		return 1
	}
	return 0
}
