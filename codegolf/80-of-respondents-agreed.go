/*

Sometimes I see a claim like "80% of respondents agreed" and I think "what was your sample size? 5?" because, of course, with a sample size of 5 it's possible to get 80% to agree on something. If the claim is "47% of respondents agreed" then I know it must be a larger sample size.[1]

challenge
Given a positive integer x≤100, output the minimum number of respondents needed for an honest claim that "x% of respondents agreed".

Input and output will be however integers (or numbers) are normally handled.

This is code golf.

Caveat: Note the effect of rounding. For example, a claim of "12% of respondents agreed" can mean that there were 8 respondents, 1 agreed, and the claim is rounding half down. Likewise, "13% of respondents agreed" can mean there were 8 respondents, 1 agreed, and the claim is rounding half up. Assume numbers closest to an integer are rounded to that integer, but you must account for both of ways of rounding half. Thus, on an input of 12 or of 13, your algorithm should output 8.

examples
1 ↦ 67
2 ↦ 40
100 ↦ 1
[1] Of course, this is assuming that what I'm reading is telling the truth.

*/

package main

import "math"

func main() {
	tab := []int{200, 67, 40, 29, 23, 19, 16, 14, 12, 11, 10, 9, 8, 8, 7, 13, 19, 6, 11, 16, 5, 14, 9, 13, 17, 4, 19, 11, 18, 7, 10, 13, 19, 3, 29, 17, 11, 8, 8, 18, 5, 17, 12, 7, 9, 11, 13, 15, 21, 35, 2, 35, 21, 15, 13, 11, 9, 7, 12, 17, 5, 18, 8, 8, 11, 17, 29, 3, 19, 13, 10, 7, 18, 11, 19, 4, 17, 13, 9, 14, 5, 16, 11, 6, 19, 13, 7, 8, 8, 9, 10, 11, 12, 14, 16, 19, 23, 29, 40, 67, 1}

	for i := range tab {
		assert(respondents(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://oeis.org/A239525
Find the smallest N such that there is some x > 0 with abs(100*x/N - n) <= 0.5.

*/

func respondents(n int) int {
	if n < 0 || n > 100 {
		return 0
	}

	for i := 1; i < math.MaxInt; i++ {
		for j := i; j > 0; j-- {
			x := 100 * float64(j) / float64(i)
			if math.Abs(x-float64(n)) <= 0.5 {
				return i
			}
		}
	}
	return 0
}
