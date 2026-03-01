/*

The complexity c(n) of a whole number is the smallest possible sum of a set of whole numbers that can be combined to make n using only addition, multiplication, and parentheses. Some examples:

c(9) = 6, because 9 = 3x3 and 3+3 = 6

c(11) = 8, because 11 = 2x5+1 and 2+5+1 = 8

c(154) = 16, because 154 = 2x(2x3+1)x(3x3+2) and 2+2+3+1+3+3+2 = 16

c(446) = 19, because 446 = 2x(2x3x(2x2x3x3+1)+1) and 2+2+3+2+2+3+3+1+1 = 19

In each case, only the formula with the smallest sum matters. For instance, 11 = 3+2x4, but since 3+2+4 = 9, and there's a formula with a sum of 8, this one doesn't matter. Since 5 is the highest number for which c(n) = n, 5 is the highest number that will appear in any formula. Write a program that calculates the complexity of every whole number and finds at least one formula whose sum is that complexity Check complexities for numbers through 10,000 here.

Post formulas for 956 (complexity 22) and 6458 (complexity 29).

Thanks to cosmologicon for today's challenge at /r/dailyprogrammer_ideas

*/

package main

func main() {
	tab := []int{
		1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 7, 8, 8, 8, 8, 9, 8, 9, 9, 9, 10, 11, 9,
		10, 10, 9, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 12, 11,
		12, 12, 11, 12, 13, 11, 12, 12, 12, 12, 13, 11, 12, 12, 12, 13, 14, 12,
		13, 13, 12, 12, 13, 13, 14, 13, 14, 13, 14, 12, 13, 13, 13, 13, 14, 13, 14,
	}
	for i := range tab {
		assert(mahler_popken(i+1) == tab[i])
	}

	assert(mahler_popken(9) == 6)
	assert(mahler_popken(11) == 8)
	assert(mahler_popken(154) == 16)
	assert(mahler_popken(446) == 19)
	assert(mahler_popken(956) == 22)
	assert(mahler_popken(6458) == 29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = make(map[int]int)

// https://oeis.org/A005245
func mahler_popken(n int) int {
	if n < 0 {
		return 0
	}

	if _, ok := cache[n]; ok {
		return cache[n]
	}

	r := n
	for i := 2; i < n; i++ {
		a := n*(n%i) + mahler_popken(n/i)
		b := mahler_popken(n - i)
		r = min(r, mahler_popken(i)+min(a, b))
	}
	cache[n] = r
	return r
}
