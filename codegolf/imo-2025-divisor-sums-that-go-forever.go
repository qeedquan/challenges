/*

Problem 4 of the 2025 International Mathematical Olympiad asked (paraphrased):

Let f(n) be the sum of the largest three proper divisors of n, that is divisors excluding n itself.
For example, f(24)=6+8+12=26. Repeatedly apply f until you cannot because your current value has fewer than 3 proper divisors.
For which starting values of n does this process continue forever?

For example, 24 does not work because it gives

24→26→16→14→10→8→7

and 7 has only the proper divisor 1. But, 6 works because it just goes 6→6→6→⋯.

These values are OEIS A386276, which starts:

6, 18, 42, 54, 66, 72, 78, 102, 114, 126, 138, 162, 174, 186, 198, 216, 222, 234, 246, 258, 282, 294, 306, 318, 342, 354, 366, 378, 402, 414, 426, 438, 462, 474, 486, 498, 504, 522, 534, 546, 558, 582, 594, 606, 618, 642, 648, 654, 666, 678, 702, 714, 726, 738, 762, 774, 786, 792, 798, 822, 834, 846, 858, 864, 882, 894, 906, 918, 936, 942, 954, 966, 978

Given a positive integer n, output whether the process continues forever, using either:

One of two fixed distinct values indicating "yes" or "no"
A truthy or falsy value, as defined by your language (these may be swapped)
The answer to the IMO problem, which you may find useful, is that n has the property exactly if its prime factorization

n = 2^a2 * 3^a3 * 5^a5 * 7^a7

satisfies

a2 is odd
a3 ≥ (a2 + 1)/2
a5 = 0


*/

package main

import (
	"math"
	"reflect"
)

func main() {
	tab := []int{
		6, 18, 42, 54, 66, 72, 78, 102, 114, 126, 138,
		162, 174, 186, 198, 216, 222, 234, 246, 258, 282,
		294, 306, 318, 342, 354, 366, 378, 402, 414, 426,
		438, 462, 474, 486, 498, 504, 522, 534, 546, 558,
		582, 594, 606, 618, 642, 648, 654, 666, 678, 702,
		714, 726, 738, 762, 774, 786, 792, 798, 822, 834,
		846, 858, 864, 882, 894, 906, 918, 936, 942, 954,
		966, 978,
	}

	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 0; len(r) < n && i < math.MaxInt; i++ {
		if f(i) {
			r = append(r, i)
		}
	}
	return r
}

// https://oeis.org/A386276
func f(n int) bool {
	if n < 1 {
		return false
	}
	x := n % 5
	y := (n % 6) * 6
	z := n % 12
	return x > y && y < z+truth(f(n/12))
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
